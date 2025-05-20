//FormAI DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>


#define PORT "8080"     // The port the firewall will listen to.


// Get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa){
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


int main(){

    int sockfd, new_fd;  // Listen on sockfd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // Connector's address information
    socklen_t sin_size;
    struct sigaction sa;
    int yes = 1;
    char s[INET6_ADDRSTRLEN];
    int rv;


    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // Use my IP address

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Loop through all the results, bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);


    if (p == NULL) {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Firewall is waiting for incoming connections...\n");

    while(1) {  // Main accept() loop

        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (new_fd == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s); // Convert IP address to readable format
        printf("Firewall: Connection from %s\n", s);

        char buf[1024];
        int numbytes;

        if ((numbytes = recv(new_fd, buf, sizeof buf, 0)) == -1) {  // Receiving data from the client
            perror("recv");
            exit(1);
        }

        buf[numbytes] = '\0';  // Adding null terminator at the end of the string
        printf("Firewall: Message received: %s\n", buf);

        if(strcmp(buf,"blockme")==0){ // If the message is "blockme", ignore it and close the connection
            printf("Firewall: blocking the connection from %s\n", s);
            close(new_fd);
        }else{  // If the message is anything else, forward it to the destination server

            int sock;
            struct addrinfo hints, *servinfo, *p;
            int rv;
            char s[INET6_ADDRSTRLEN];
            char dest_address[] = "www.google.com";  // Destination address
            char dest_port[] = "80";  // Destination port

            memset(&hints, 0, sizeof hints);
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_STREAM;

            if ((rv = getaddrinfo(dest_address, dest_port, &hints, &servinfo)) != 0) {  // Resolving host name to IP address
                fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
                return 1;
            }

            // Loop through all the results and connect to the first available one
            for(p = servinfo; p != NULL; p = p->ai_next) {
                if ((sock = socket(p->ai_family, p->ai_socktype,
                        p->ai_protocol)) == -1) {
                    perror("client: socket");
                    continue;
                }

                if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
                    close(sock);
                    perror("client: connect");
                    continue;
                }

                break;
            }

            if (p == NULL) {
                fprintf(stderr, "client: failed to connect\n");
                return 2;
            }

            inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s); // Converting IP address to human-readable format
            printf("Firewall: sending message to %s\n", s);

            if (send(sock, buf, numbytes, 0) == -1) {  // Sending the received message to the destination server
                perror("send");
                close(sock);
                exit(1);
            }

            char dest_response[1024];
            int dest_numbytes;

            if ((dest_numbytes = recv(sock, dest_response, sizeof dest_response, 0)) == -1) {  // Receiving response from the destination server
                perror("recv");
                exit(1);
            }

            dest_response[dest_numbytes] = '\0';  // Adding null terminator at the end of the string
            printf("Firewall: Received response from %s: %s\n", s, dest_response);

            if (send(new_fd, dest_response, dest_numbytes, 0) == -1) {  // Sending the destination server's response back to the client
                perror("send");
                close(new_fd);
                exit(1);
            }

            freeaddrinfo(servinfo);

            close(sock);
            close(new_fd);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MY_PORT 4444    // designate a port for communication

/* Medieval style server code */
int main(void) {
    int sockfd, new_sockfd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    socklen_t sin_size;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if(sockfd == -1) {
        perror("socket error");
        exit(1);
    }

    my_addr.sin_family = AF_INET; // set family
    my_addr.sin_port = htons(MY_PORT); // set port
    my_addr.sin_addr.s_addr = INADDR_ANY; // bind to any available address
    memset(&(my_addr.sin_zero), '\0', 8); // zero out the sockaddr struct

    if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind error");
        exit(1);
    }

    if(listen(sockfd, 5) == -1) { // listen for incoming connections
        perror("listen error");
        exit(1);
    }

    printf("Medieval style TCP server awaiting knights on horseback...\n");
    
    while(1) {  // accept connections and serve them
        sin_size = sizeof(struct sockaddr_in);
        new_sockfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        
        if(new_sockfd == -1) {
            perror("accept error");
            continue;
        }

        printf("Successful connection with knight from %s\n", inet_ntoa(their_addr.sin_addr)); 

        if(!fork()) { // create child process to handle request
            close(sockfd);
            if(send(new_sockfd, "Greetings sir knight!\n", 22, 0) == -1) {
                perror("send error");
            }
            char buf[1024];
            int numbytes;
            if((numbytes = recv(new_sockfd, buf, 1023, 0)) == -1) { // receive message
                perror("recv error");
                exit(1); 
            }
            buf[numbytes] = '\0';
            printf("Received message: \"%s\" from knight at %s\n", buf, inet_ntoa(their_addr.sin_addr));
            if(send(new_sockfd, "Very good, sir knight!\n", 23, 0) == -1) { // send response
                perror("send error"); 
            }
            close(new_sockfd);
            exit(0);
        }
        close(new_sockfd); // parent process closes connection
    }
    return 0; // done
}
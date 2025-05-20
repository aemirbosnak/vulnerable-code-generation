//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to the address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept a connection
    printf("Server listening on port %d\n", ntohs(serv_addr.sin_port));
    for (;;) {
        if ((portno = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &n)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        int pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            close(sockfd);

            // Send a message to the client
            n = send(portno, "HTTP/1.1 200 OK\r\n\r\n", 28, 0);
            if (n < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }

            // Receive the response from the client
            while ((n = recv(portno, buffer, 1024, 0)) > 0) {
                buffer[n] = '\0';
                printf("%s", buffer);
            }
            close(portno);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            close(portno);
        }
    }
    return 0;
}
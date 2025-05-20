//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>   
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <unistd.h>      
#include <errno.h>       

#define PORT_NUMBER     5000
#define BUFFER_SIZE     1024

int main(void)
{
    int ret;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char message_start[] = "Welcome to the TCP/IP Programming Example!";
    char message_end[] = "Bye bye!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORT_NUMBER);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error binding socket: %s", strerror(errno));
        close(sockfd);
        return 1;
    }

    ret = listen(sockfd, 10);
    if (ret == -1) {
        printf("Error listening on socket: %s", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Server is listening on port %d...\n", PORT_NUMBER);

    while (1) {
        int clientfd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len;

        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (clientfd == -1) {
            printf("Error accepting connection: %s", strerror(errno));
            continue;
        }

        printf("New client connected!\n");

        send(clientfd, message_start, strlen(message_start), 0);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ret = recv(clientfd, buffer, BUFFER_SIZE, 0);
            if (ret == -1) {
                printf("Error receiving data from client: %s", strerror(errno));
                break;
            } else if (ret == 0) {
                printf("Client disconnected.\n");
                break;
            } else {
                printf("Received %d bytes from client: %s", ret, buffer);

                // Do something interesting with the data!
                for (int i = 0; i < ret; i++) {
                    buffer[i] ^= 0x55;
                }

                ret = send(clientfd, buffer, ret, 0);
                if (ret == -1) {
                    printf("Error sending data to client: %s", strerror(errno));
                    break;
                }
            }
        }

        send(clientfd, message_end, strlen(message_end), 0);

        close(clientfd);
        printf("Client connection closed.\n");
    }

    close(sockfd);
    printf("Server shutting down.\n");

    return 0;
}
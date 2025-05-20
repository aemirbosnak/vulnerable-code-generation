//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MY_PORT 3490
#define MAX_CONNECTIONS 10
#define MAX_DATA_SIZE 1024

int main() {

    int sockfd, new_fd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    char data_buffer[MAX_DATA_SIZE];
    int bytes_received;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MY_PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(my_addr.sin_zero), '\0', 8);

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    printf("TCP Server is running on port %d...\n", MY_PORT);

    while(1) {
        if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) {
            perror("accept");
            continue;
        }

        printf("Received connection from %s\n", inet_ntoa(their_addr.sin_addr));

        if (!fork()) {
            close(sockfd);

            while(1) {
                if ((bytes_received = recv(new_fd, data_buffer, MAX_DATA_SIZE-1, 0)) == -1) {
                    perror("recv");
                    exit(1);
                }

                if (bytes_received == 0) {
                    printf("Connection closed by client\n");
                    close(new_fd);
                    exit(0);
                }

                data_buffer[bytes_received] = '\0';
                printf("Received message: %s", data_buffer);

                if (send(new_fd, "I got your message", 18, 0) == -1) {
                    perror("send");
                }
            }
            exit(0);
        }
        close(new_fd);
    }

    return 0;
}
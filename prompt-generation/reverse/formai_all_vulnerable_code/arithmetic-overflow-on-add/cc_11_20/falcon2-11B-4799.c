//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/time.h>

#define BACKLOG 10
#define MAX_CONNECTIONS 100
#define PORT 12345

int main() {
    int sockfd, new_fd;
    struct sockaddr_in server, client;
    int yes = 1;
    int valread;
    pid_t pid;
    char buf[4096];
    struct timeval timeout;
    fd_set readfds;
    int nfds;
    char *logfile;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&server, '0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, MAX_CONNECTIONS);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        nfds = sockfd + 1;

        if (select(nfds, &readfds, NULL, NULL, &timeout) < 0) {
            perror("ERROR on select");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            if ((new_fd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)&valread)) < 0) {
                perror("ERROR on accept");
                exit(1);
            }

            if (fork() == 0) {
                close(sockfd);

                while (1) {
                    if ((valread = recv(new_fd, buf, sizeof(buf), 0)) <= 0) {
                        if (valread == 0) {
                            printf("Client disconnected\n");
                            break;
                        } else {
                            perror("ERROR reading from socket");
                            exit(1);
                        }
                    }

                    send(new_fd, buf, valread, 0);
                }

                close(new_fd);

                exit(0);
            }
        }
    }

    close(sockfd);
    return 0;
}
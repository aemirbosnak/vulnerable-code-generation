//FormAI DATASET v1.0 Category: Socket programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, max_fd, i, activity, client_count = 0;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    fd_set read_set;
    struct sockaddr_in serv_addr, cli_addr;
    int client_sockfd[MAX_CLIENTS];
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    listen(sockfd, 5);
    printf("Server is running on port %d\n", portno);
    while(1) {
        FD_ZERO(&read_set);
        FD_SET(sockfd, &read_set);
        max_fd = sockfd;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockfd[i] > 0) {
                FD_SET(client_sockfd[i], &read_set);
                if (client_sockfd[i] > max_fd)
                    max_fd = client_sockfd[i];
            }
        }
        activity = select(max_fd + 1, &read_set, NULL, NULL, NULL);
        if ((activity < 0) && (errno!=EINTR)) {
            printf("Error during select");
            exit(1);
        }
        if (FD_ISSET(sockfd, &read_set)) {
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (newsockfd < 0) {
                perror("Error on accept");
                exit(1);
            }
            printf("New client connected\n");
            client_count++;
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockfd[i] == 0) {
                    client_sockfd[i] = newsockfd;
                    break;
                }
            }
        }
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_sockfd[i], &read_set)) {
                memset(buffer, 0, BUFFER_SIZE);
                if (read(client_sockfd[i], buffer, BUFFER_SIZE) == 0) {
                    close(client_sockfd[i]);
                    FD_CLR(client_sockfd[i], &read_set);
                    client_sockfd[i] = 0;
                    client_count--;
                    printf("Client disconnected\n");
                }
                else {
                    printf("Received: %s\n", buffer);
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sockfd[j] != 0 && client_sockfd[j] != client_sockfd[i])
                            write(client_sockfd[j], buffer, strlen(buffer));
                    }
                }
            }
        }
    }
    close(sockfd);
    return 0;
}
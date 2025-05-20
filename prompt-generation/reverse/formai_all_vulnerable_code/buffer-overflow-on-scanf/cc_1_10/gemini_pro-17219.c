//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define PUZZLE_PORT 12345

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256], client_ip[INET6_ADDRSTRLEN];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PUZZLE_PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return 1;
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        return 1;
    }

    inet_ntop(AF_INET, &cli_addr.sin_addr, client_ip, INET6_ADDRSTRLEN);
    printf("Client connected from %s\n", client_ip);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv(newsockfd, buffer, 255, 0);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        printf("Client: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));

        int i, j, n, k = 0;
        scanf("%d", &n);

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                k++;
                buffer[i] += k;
            }
        }

        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}
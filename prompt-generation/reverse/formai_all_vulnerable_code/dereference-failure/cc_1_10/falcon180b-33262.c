//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 110
#define USERNAME "username"
#define PASSWORD "password"

typedef struct {
    char *username;
    char *password;
    int port;
} Config;

Config config = {USERNAME, PASSWORD, SERVER_PORT};

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[1024];

    if (argc > 1) {
        if (strcmp(argv[1], "--config") == 0) {
            config.username = argv[2];
            config.password = argv[3];
            config.port = atoi(argv[4]);
        }
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(config.port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);

        send(sockfd, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "QUIT\r\n") == 0) {
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        recv(sockfd, buffer, sizeof(buffer), 0);

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
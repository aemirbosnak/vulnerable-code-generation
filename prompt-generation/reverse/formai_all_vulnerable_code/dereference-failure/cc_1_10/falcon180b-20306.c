//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char server[256] = {0};
    strcpy(server, argv[1]);

    char username[256] = {0};
    strcpy(username, argv[2]);

    char password[256] = {0};
    strcpy(password, argv[3]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }

    struct hostent *server_info = gethostbyname(server);
    if (server_info == NULL) {
        error("gethostbyname failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, server_info->h_addr, server_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    char *login_msg = "USER ";
    strcat(login_msg, username);
    strcat(login_msg, "\r\n");
    send(sockfd, login_msg, strlen(login_msg), 0);

    char *pass_msg = "PASS ";
    strcat(pass_msg, password);
    strcat(pass_msg, "\r\n");
    send(sockfd, pass_msg, strlen(pass_msg), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
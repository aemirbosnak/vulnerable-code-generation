//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4 && argc!= 5) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        printf("Host not found\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    char login_msg[100];
    sprintf(login_msg, "USER %s\r\n", username);
    send(sock, login_msg, strlen(login_msg), 0);

    char pass_msg[100];
    sprintf(pass_msg, "PASS %s\r\n", password);
    send(sock, pass_msg, strlen(pass_msg), 0);

    char *buffer = malloc(BUFFER_SIZE);
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Disconnected\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}
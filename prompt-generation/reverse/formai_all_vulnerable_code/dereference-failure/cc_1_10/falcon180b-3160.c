//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg,...) {
    va_list ap;
    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    va_end(ap);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket() failed");
    }

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        error("gethostbyname() failed");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error("connect() failed");
    }

    char *auth = (char *)malloc(64);
    snprintf(auth, 64, "USER %s\r\n", username);
    send(sock, auth, strlen(auth), 0);

    char *pass = (char *)malloc(64);
    snprintf(pass, 64, "PASS %s\r\n", password);
    send(sock, pass, strlen(pass), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sock, valread;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024] = {0};
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Cannot create socket.\n");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host.\n");
        return 1;
    }

    serv_addr.sin_addr.s_addr = inet_addr(server->h_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_family = AF_INET;

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Cannot connect to server.\n");
        return 1;
    }

    while (1) {
        valread = read(sock, buffer, 1024);
        if (valread == 0) {
            break;
        }
        printf("%s", buffer);
        memset(buffer, 0, 1024);
    }

    close(sock);
    return 0;
}
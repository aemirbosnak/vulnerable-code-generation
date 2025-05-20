//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int MAX_DATA_SIZE = 1024;
const int PORT = 8080;
const int TIME_OUT = 5000;

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error("socket failed");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error("bind failed");

    if (listen(sock, 10) < 0)
        error("listen");

    puts("Server is running...");

    while (1) {
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);
        int clisock = accept(sock, (struct sockaddr*)&cli_addr, &clilen);
        if (clisock < 0)
            error("accept");
        puts("Client connected...");

        char buffer[MAX_DATA_SIZE];
        int bytes_read = 0;
        while (1) {
            memset(buffer, 0, MAX_DATA_SIZE);
            int bytes_received = recv(clisock, buffer, MAX_DATA_SIZE, 0);
            if (bytes_received <= 0) {
                close(clisock);
                break;
            }
            bytes_read += bytes_received;

            if (send(clisock, buffer, bytes_received, 0) < 0)
                error("send");
        }
        puts("Client disconnected...");
        close(clisock);
    }

    return 0;
}
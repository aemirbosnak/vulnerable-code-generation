//Falcon-180B DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <poll.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    int port = 80;

    if (argc == 3) {
        port = atoi(argv[2]);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    char buffer[BUF_SIZE];
    while (1) {
        int bytes_received = recv(sock, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(sock);
            return 1;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}
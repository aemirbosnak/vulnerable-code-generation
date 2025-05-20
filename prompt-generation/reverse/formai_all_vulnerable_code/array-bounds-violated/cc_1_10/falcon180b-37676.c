//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server_addr;
    char *host;
    char buffer[BUF_SIZE];
    char command[BUF_SIZE];
    char response[BUF_SIZE];
    int bytes_read;
    int bytes_written;
    int pid;
    int status;

    if (argc!= 4) {
        printf("Usage:./ftp_client <host> <port> <command>\n");
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    strcpy(command, argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    if (send(sock, command, strlen(command), 0) == -1) {
        printf("Error sending command\n");
        close(sock);
        return 1;
    }

    while (1) {
        bytes_read = recv(sock, buffer, BUF_SIZE, 0);
        if (bytes_read <= 0) {
            break;
        }
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program <IP address> <port number> <file name>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *file_name = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        error_handling("socket failed");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("connect failed");
    }

    char request[100];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", file_name, ip_address, port_number);

    send(sock, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}
//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX_LINE 1024
#define BUFFER_SIZE 1024*1024 // 1MB Buffer size

int main(int argc, char *argv[]) {
    int sock, newsock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;
    int bytes_sent, bytes_received;
    char *response;
    int response_len;
    FILE *fp;
    char filename[40];
    char *ext;
    int file_size, chunk_size;
    char *url = "http://speedtest.net/speedtest.php?test=1&thread=1&file=1&size=1&unit=1";
    char *host = "speedtest.net";
    char *path = "/speedtest.php";
    char *query_string = "test=1&thread=1&file=1&size=1&unit=1";
    char *request;
    int request_len;
    int i;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    bytes_sent = send(sock, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    addrlen = sizeof(client_addr);
    if (getsockname(sock, (struct sockaddr *)&client_addr, &addrlen) == -1) {
        printf("Error getting socket name\n");
        exit(1);
    }

    while ((bytes_received = recv(sock, buffer, MAX_LINE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}
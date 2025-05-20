//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
// ftpclient.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFSIZE 1024

int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send user name
    char buf[BUFSIZE];
    sprintf(buf, "USER %s\r\n", argv[2]);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send password
    sprintf(buf, "PASS %s\r\n", argv[3]);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send type command
    sprintf(buf, "TYPE I\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send pasv command
    sprintf(buf, "PASV\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive response
    int n = recv(sock, buf, BUFSIZE, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Parse response
    char *p = strchr(buf, '(');
    if (!p) {
        fprintf(stderr, "Invalid response\n");
        return 1;
    }
    p++;
    char *q = strchr(p, ')');
    if (!q) {
        fprintf(stderr, "Invalid response\n");
        return 1;
    }
    *q = '\0';
    char *ip = strtok(p, ",");
    if (!ip) {
        fprintf(stderr, "Invalid response\n");
        return 1;
    }
    char *port = strtok(NULL, ",");
    if (!port) {
        fprintf(stderr, "Invalid response\n");
        return 1;
    }

    // Create new socket for data transfer
    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up address structure for data transfer
    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, ip, &data_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to data server
    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send command to get file
    sprintf(buf, "RETR %s\r\n", argv[4]);
    if (send(data_sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive file
    FILE *fp = fopen(argv[5], "w");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    while ((n = recv(data_sock, buf, BUFSIZE, 0)) > 0) {
        fwrite(buf, 1, n, fp);
    }
    fclose(fp);

    // Close sockets
    close(sock);
    close(data_sock);

    return 0;
}
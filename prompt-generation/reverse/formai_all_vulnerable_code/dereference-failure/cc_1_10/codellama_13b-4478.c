//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: shocked
// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;

    if (argc < 3) {
        printf("usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("socket() failed\n");
        return 1;
    }

    // set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("connect() failed\n");
        return 1;
    }

    // send message to server
    n = write(sock, "Hello from client", 14);
    if (n < 0) {
        printf("write() failed\n");
        return 1;
    }

    // receive message from server
    n = read(sock, buffer, BUF_SIZE);
    if (n < 0) {
        printf("read() failed\n");
        return 1;
    }
    printf("Received from server: %s\n", buffer);

    // close socket
    close(sock);

    return 0;
}
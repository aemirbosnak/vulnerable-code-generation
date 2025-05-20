//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: %s <server IP address>\n", argv[0]);
        exit(1);
    }

    // create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // create a sockaddr_in structure with the server address we want to connect to
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(80);   // port 80 for HTTP

    // connect to the server
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // send a GET request to the server
    const char* request = "GET / HTTP/1.1\r\n"
                          "Host: www.google.com\r\n"
                          "Connection: close\r\n\r\n";

    if (send(sock_fd, request, strlen(request), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive the response from the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int n_bytes;
    clock_t start_time = clock();

    while ((n_bytes = recv(sock_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        // do nothing
    }

    clock_t end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (n_bytes < 0) {
        perror("recv() failed");
        exit(1);
    }

    // print the results
    double speed = BUFFER_SIZE / elapsed_time * 8 / 1024 / 1024;   // convert to Mbps
    printf("Your internet speed is: %.2f Mbps\n", speed);

    // close the socket
    close(sock_fd);

    return 0;
}
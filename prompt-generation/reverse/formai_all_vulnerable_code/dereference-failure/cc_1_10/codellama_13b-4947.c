//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 21
#define MAX_BUFFER_SIZE 1024

void print_usage(char* argv[]) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    printf("Example: %s 127.0.0.1 21\n", argv[0]);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage(argv);
        return 1;
    }

    // Get host and port from command line arguments
    char* host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read and write data
    char buffer[MAX_BUFFER_SIZE];
    while (1) {
        // Read data from the server
        int n = read(sock, buffer, MAX_BUFFER_SIZE);
        if (n < 0) {
            perror("read");
            return 1;
        } else if (n == 0) {
            break;
        }

        // Write data to the server
        n = write(sock, buffer, n);
        if (n < 0) {
            perror("write");
            return 1;
        }
    }

    // Close the socket
    close(sock);

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_PACKET_SIZE 1024
#define MAX_BUFFER_SIZE 2048

void print_usage(char *prog_name) {
    printf("Usage: %s <server_ip> <server_port>\n", prog_name);
    printf("  <server_ip>: IP address of the server\n");
    printf("  <server_port>: Port number of the server\n");
    printf("Example: %s 192.168.1.1 8080\n", prog_name);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        printf("Invalid server IP address\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    char buffer[MAX_BUFFER_SIZE];
    int n;
    while ((n = read(sock, buffer, MAX_BUFFER_SIZE)) > 0) {
        printf("Received %d bytes of data\n", n);
    }

    if (n < 0) {
        printf("Failed to read data from server\n");
        return 1;
    }

    close(sock);
    return 0;
}
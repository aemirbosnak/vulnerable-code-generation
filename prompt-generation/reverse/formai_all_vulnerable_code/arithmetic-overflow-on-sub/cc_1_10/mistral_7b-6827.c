//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>

#define PORT_MIN 1
#define PORT_MAX 65535
#define TIMEOUT 1000
#define BUFFER_SIZE 1024

void print_result(const char *ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int connected = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (connected < 0) {
        perror("Error connecting to the server");
        close(sockfd);
        return;
    }

    char buffer[BUFFER_SIZE];
    send(sockfd, "HELO\n", 5, 0);

    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        printf("[+] Open: %s:%d\n", ip, port);
        printf("    Response: %s\n", buffer);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];

    for (int port = PORT_MIN; port <= PORT_MAX; ++port) {
        clock_t start = clock();
        print_result(ip, port);
        clock_t end = clock();

        if (end - start > TIMEOUT) {
            printf("[-] Timeout: %s:%d\n", ip, port);
        }
    }

    return 0;
}
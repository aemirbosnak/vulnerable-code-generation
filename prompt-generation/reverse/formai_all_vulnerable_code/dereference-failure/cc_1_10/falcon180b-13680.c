//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <hostname> <start_port> <end_port>\n", program_name);
    exit(1);
}

int is_port_open(int sockfd, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            return 0;
        } else {
            perror("connect");
            return -1;
        }
    } else {
        close(sockfd);
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range\n");
        exit(1);
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        if (is_port_open(sockfd, i) == 1) {
            printf("Port %d is open\n", i);
        } else if (is_port_open(sockfd, i) == 0) {
            printf("Port %d is closed\n", i);
        } else {
            printf("Error checking port %d\n", i);
        }
    }

    close(sockfd);
    return 0;
}
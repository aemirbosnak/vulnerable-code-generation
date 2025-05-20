//FormAI DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *host = argv[1];
    const int start_port = atoi(argv[2]);
    const int end_port = atoi(argv[3]);
    
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(host);
    if (target.sin_addr.s_addr == INADDR_NONE) {
        fprintf(stderr, "Invalid host: %s\n", host);
        exit(EXIT_FAILURE);
    }
    
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    int port;
    
    for (port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);
        
        if (connect(sock, (struct sockaddr *) &target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            switch (errno) {
                case ECONNREFUSED:
                    printf("Port %d is closed\n", port);
                    break;
                case ETIMEDOUT:
                    printf("Port %d is filtered or host is down\n", port);
                    break;
                default:
                    fprintf(stderr, "Connect error: %s\n", strerror(errno));
                    exit(EXIT_FAILURE);
                    break;
            }
        }
    }
    
    close(sock);
    return EXIT_SUCCESS;
}
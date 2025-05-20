#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <start-port>-<end-port>\n", argv[0]);
        return 1;
    }

    int start, end;
    char input[10];
    strcpy(input, argv[1]);

    if (sscanf(input, "%d-%d", &start, &end) != 2) {
        printf("Invalid port range format.\n");
        return 1;
    }

    if (start < 1 || start > 65535 || end < start || end > 65535) {
        printf("Port range out of bounds.\n");
        return 1;
    }

    for (int port = start; port <= end; ++port) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
            close(sockfd);
        }
    }

    return 0;
}

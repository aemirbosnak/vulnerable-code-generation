#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

void read_packet(int sockfd) {
    char buffer[BUFSIZE];
    struct sockaddr_in src_addr;
    socklen_t addr_len = sizeof(src_addr);
    ssize_t bytes_read;

    while ((bytes_read = recvfrom(sockfd, buffer, BUFSIZE - 1, 0, (struct sockaddr *)&src_addr, &addr_len)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received %zd bytes from %s:%d\n", bytes_read, inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
        // Out-of-bounds read vulnerability
        printf("%s\n", buffer + bytes_read);  // This line intentionally reads beyond the buffer
    }
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(80);

    if (bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening on port 80...\n");
    read_packet(sockfd);

    close(sockfd);
    return 0;
}

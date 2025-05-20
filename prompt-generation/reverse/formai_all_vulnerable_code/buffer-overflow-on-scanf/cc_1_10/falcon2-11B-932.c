//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, n, i, j, sum = 0, addrlen;
    struct sockaddr_in server_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Enter a number n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input! n must be greater than 0.\n");
        exit(1);
    }

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i;
            send(sockfd, &sum, sizeof(int), 0);
        }
    }

    send(sockfd, &sum, sizeof(int), 0);
    close(sockfd);
    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct {
    char symbol[5];
    float price;
} Stock;

void sigint_handler(int signo) {
    printf("\nExiting...\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    pthread_t thread_id;
    Stock stocks[10];

    while (1) {
        char buffer[1024];
        recv(sockfd, buffer, 1024, 0);
        sscanf(buffer, "%[^,],%f", stocks[0].symbol, &stocks[0].price);

        for (int i = 1; i < 10; i++) {
            recv(sockfd, buffer, 1024, 0);
            sscanf(buffer, "%[^,],%f", stocks[i].symbol, &stocks[i].price);
        }

        system("clear"); // for linux
        printf("-------------------------------------------------\n");
        printf("|       Futuristic Stock Market Tracker         |\n");
        printf("-------------------------------------------------\n");
        printf("| Symbol | Price    |\n");
        printf("-------------------------------------------------\n");

        for (int i = 0; i < 10; i++) {
            printf("| %-6s | %.2f | \n", stocks[i].symbol, stocks[i].price);
        }
        printf("-------------------------------------------------\n");

        sleep(1);
    }

    close(sockfd);
    return 0;
}
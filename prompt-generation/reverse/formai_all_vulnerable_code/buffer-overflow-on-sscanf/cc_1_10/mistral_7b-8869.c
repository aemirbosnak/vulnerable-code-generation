//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_STOCKS 10
#define UPDATE_INTERVAL 1000

typedef struct {
    char symbol[5];
    float price;
} Stock;

pthread_mutex_t stocks_mutex;
Stock stocks[MAX_STOCKS];

void handle_signal(int signum) {
    printf("\nExiting gracefully...\n");
    pthread_mutex_destroy(&stocks_mutex);
    exit(0);
}

void init_stocks() {
    int i;
    for (i = 0; i < MAX_STOCKS; i++) {
        strcpy(stocks[i].symbol, "AAPL");
        stocks[i].price = 144.95;
    }
}

void update_stocks() {
    int sockfd, new_sockfd, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address));

    pthread_mutex_lock(&stocks_mutex);
    for (int i = 0; i < MAX_STOCKS; i++) {
        sprintf(buffer, "GET %s\n", stocks[i].symbol);
        send(sockfd, buffer, strlen(buffer), 0);

        read_size = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            perror("Error reading from server");
            pthread_mutex_unlock(&stocks_mutex);
            exit(1);
        }

        sscanf(buffer, "%s %f", stocks[i].symbol, &stocks[i].price);
    }
    pthread_mutex_unlock(&stocks_mutex);

    close(sockfd);
}

void print_stocks() {
    int i;
    pthread_mutex_lock(&stocks_mutex);

    printf("\nCurrent stock prices:\n");
    for (i = 0; i < MAX_STOCKS; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
    }
    pthread_mutex_unlock(&stocks_mutex);
}

int main() {
    int status;
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    pthread_mutex_init(&stocks_mutex, NULL);
    init_stocks();

    while (1) {
        update_stocks();
        print_stocks();
        sleep(UPDATE_INTERVAL);
    }

    return 0;
}
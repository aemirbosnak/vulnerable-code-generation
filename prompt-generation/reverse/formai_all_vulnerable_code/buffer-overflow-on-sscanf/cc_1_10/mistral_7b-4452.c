//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_STOCKS 10
#define BUF_SIZE 1024
#define LOG_FILE "stock_tracker.log"

typedef struct {
    char symbol[5];
    float price;
} Stock;

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void) {
    int fd;
    Stock stocks[MAX_STOCKS];
    char line[BUF_SIZE];
    char symbol[5];
    float price;
    int num_stocks = 0;

    fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) error_exit("Cannot open log file");

    while (fgets(line, BUF_SIZE, fd) != NULL) {
        sscanf(line, "%s%f", symbol, &price);
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Too many stocks\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
        strcpy(stocks[num_stocks].symbol, symbol);
        stocks[num_stocks].price = price;
        num_stocks++;
    }

    close(fd);

    printf("Current stock prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: %.2f\n", stocks[i].symbol, stocks[i].price);
    }

    printf("Enter new stock symbol and price (format: STOCK_SYMBOL PRICE)\n");
    while (1) {
        scanf("%s%f", symbol, &price);
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(symbol, stocks[i].symbol) == 0) {
                printf("Error: Stock symbol already exists\n");
                continue;
            }
        }

        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Max number of stocks reached\n");
            break;
        }

        stocks[num_stocks].price = price;
        strcpy(stocks[num_stocks].symbol, symbol);
        num_stocks++;

        printf("Added new stock: %s %.2f\n", symbol, price);

        fd = open(LOG_FILE, O_WRONLY | O_APPEND);
        if (fd < 0) error_exit("Cannot open log file for writing");

        fprintf(fd, "%s %.2f\n", symbol, price);
        close(fd);
    }

    return EXIT_SUCCESS;
}
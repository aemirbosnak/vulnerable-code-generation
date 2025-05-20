//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>

#define MAX_STOCKS 100
#define MAX_STOCK_LEN 20
#define MAX_PRICE_LEN 10

struct stock {
    char name[MAX_STOCK_LEN];
    double price;
    pthread_t thread;
};

struct stock_list {
    struct stock stocks[MAX_STOCKS];
    int num_stocks;
};

struct stock_list stock_list;

void *stock_thread(void *arg) {
    struct stock *stock = (struct stock *)arg;
    while (1) {
        // Simulate a random stock price change
        double change = (rand() % 100 - 50) / 100.0;
        stock->price += stock->price * change;

        // Sleep for a random amount of time
        sleep(rand() % 10 + 1);
    }
    return NULL;
}

int main(int argc, char **argv) {
    // Initialize the stock list
    stock_list.num_stocks = 0;

    // Read the stock names from a file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        perror("Error opening stocks.txt");
        return EXIT_FAILURE;
    }

    while (1) {
        char line[MAX_STOCK_LEN + 1];
        if (fgets(line, MAX_STOCK_LEN + 1, fp) == NULL) {
            break;
        }
        line[strlen(line) - 1] = '\0'; // Remove the newline character
        strcpy(stock_list.stocks[stock_list.num_stocks].name, line);
        stock_list.stocks[stock_list.num_stocks].price = 0.0;
        stock_list.num_stocks++;
    }

    fclose(fp);

    // Create a thread for each stock
    for (int i = 0; i < stock_list.num_stocks; i++) {
        if (pthread_create(&stock_list.stocks[i].thread, NULL, stock_thread, &stock_list.stocks[i]) != 0) {
            perror("Error creating thread");
            return EXIT_FAILURE;
        }
    }

    // Print the stock prices every second
    while (1) {
        printf("Stock Prices:\n");
        for (int i = 0; i < stock_list.num_stocks; i++) {
            printf("%s: $%.2f\n", stock_list.stocks[i].name, stock_list.stocks[i].price);
        }
        printf("\n");
        sleep(1);
    }

    // Cleanup
    for (int i = 0; i < stock_list.num_stocks; i++) {
        if (pthread_join(stock_list.stocks[i].thread, NULL) != 0) {
            perror("Error joining thread");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
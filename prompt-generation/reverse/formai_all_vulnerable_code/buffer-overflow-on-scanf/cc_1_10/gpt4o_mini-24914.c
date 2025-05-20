//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define NUM_STOCKS 5
#define STOCK_NAME_LENGTH 10
#define UPDATE_INTERVAL 2 // seconds

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
    pthread_mutex_t lock;
} Stock;

Stock stocks[NUM_STOCKS];

void* update_stock_prices(void* arg) {
    while (1) {
        for (int i = 0; i < NUM_STOCKS; i++) {
            pthread_mutex_lock(&stocks[i].lock);
            // Simulate stock price update
            stocks[i].price = ((float)(rand() % 10000) / 100); // Random price between 0.00 to 99.99
            pthread_mutex_unlock(&stocks[i].lock);
        }
        sleep(UPDATE_INTERVAL);
    }
    return NULL;
}

void display_stock_prices() {
    printf("\nCurrent Stock Prices:\n");
    printf("----------------------\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        pthread_mutex_lock(&stocks[i].lock);
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
        pthread_mutex_unlock(&stocks[i].lock);
    }
    printf("----------------------\n");
}

int main() {
    srand(time(NULL));

    // Initialize stocks
    char *stock_names[NUM_STOCKS] = {"AAPL", "GOOGL", "MSFT", "AMZN", "TSLA"};
    for (int i = 0; i < NUM_STOCKS; i++) {
        strncpy(stocks[i].name, stock_names[i], STOCK_NAME_LENGTH);
        stocks[i].price = 0.0;
        pthread_mutex_init(&stocks[i].lock, NULL);
    }

    pthread_t updater_thread;
    if (pthread_create(&updater_thread, NULL, update_stock_prices, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    char command[20];
    while (1) {
        printf("Enter 'view' to see stock prices, or 'exit' to quit: ");
        scanf("%s", command);
        
        if (strcmp(command, "view") == 0) {
            display_stock_prices();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    // Clean up
    pthread_cancel(updater_thread);
    pthread_join(updater_thread, NULL);

    for (int i = 0; i < NUM_STOCKS; i++) {
        pthread_mutex_destroy(&stocks[i].lock);
    }

    return 0;
}
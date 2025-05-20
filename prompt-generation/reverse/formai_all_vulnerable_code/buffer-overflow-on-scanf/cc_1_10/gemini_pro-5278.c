//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: futuristic
// Welcome to the Quantum Stock Market Tracker 2077!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

typedef struct stock {
    char ticker[10];
    double price;
    double change;
} stock_t;

// Global variables
stock_t *stocks;
int num_stocks;
pthread_mutex_t mutex;

// Function to generate a random stock price
double generate_price() {
    return (double)(rand() % 1000) / 100.0;
}

// Function to update the stock prices
void *update_prices(void *arg) {
    while (1) {
        // Acquire the lock
        pthread_mutex_lock(&mutex);

        // Update the stock prices
        for (int i = 0; i < num_stocks; i++) {
            stocks[i].price = generate_price();
            stocks[i].change = (stocks[i].price - stocks[i - 1].price) * 100.0 / stocks[i - 1].price;
        }

        // Release the lock
        pthread_mutex_unlock(&mutex);

        // Sleep for a second
        sleep(1);
    }

    return NULL;
}

// Function to print the stock information
void print_stocks() {
    // Acquire the lock
    pthread_mutex_lock(&mutex);

    // Print the stock information
    printf("%-10s %-10s %-10s\n", "Ticker", "Price", "Change");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-10s %-10.2f %-10.2f%%\n", stocks[i].ticker, stocks[i].price, stocks[i].change);
    }

    // Release the lock
    pthread_mutex_unlock(&mutex);
}

// Function to get the input from the user
int get_input() {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Update stock prices\n");
    printf("2. Print stock information\n");
    printf("3. Exit\n");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Create a mutex
    pthread_mutex_init(&mutex, NULL);

    // Create a thread to update the stock prices
    pthread_t tid;
    pthread_create(&tid, NULL, update_prices, NULL);

    // Get the number of stocks
    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    // Allocate memory for the stocks
    stocks = malloc(sizeof(stock_t) * num_stocks);

    // Initialize the stocks
    for (int i = 0; i < num_stocks; i++) {
        sprintf(stocks[i].ticker, "STK%d", i + 1);
        stocks[i].price = generate_price();
        stocks[i].change = 0.0;
    }

    // Main loop
    while (1) {
        // Get the input from the user
        int choice = get_input();

        // Switch on the choice
        switch (choice) {
            case 1:
                // Update the stock prices
                update_prices(NULL);
                break;
            case 2:
                // Print the stock information
                print_stocks();
                break;
            case 3:
                // Exit the program
                exit(0);
            default:
                // Invalid choice
                printf("Invalid choice!\n");
                break;
        }
    }

    // Cleanup
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);
    free(stocks);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of stocks to track
#define NUM_STOCKS 5

// Define the initial values for the stocks
#define INIT_VALUE 100

// Define the maximum change in value for each stock
#define MAX_CHANGE 10

// Define the number of days to simulate
#define NUM_DAYS 30

// Define the current date and time
struct tm current_time;

void init_stocks(double stocks[NUM_STOCKS]) {
    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i] = INIT_VALUE;
    }
}

void print_stocks(double stocks[NUM_STOCKS]) {
    printf("Current stock values:\n");
    for (int i = 0; i < NUM_STOCKS; i++) {
        printf("Stock %d: $%.2f\n", i + 1, stocks[i]);
    }
}

void update_stocks(double stocks[NUM_STOCKS]) {
    for (int i = 0; i < NUM_STOCKS; i++) {
        stocks[i] += (rand() % MAX_CHANGE) - MAX_CHANGE / 2;
    }
}

int main() {
    srand(time(NULL));

    // Initialize the stocks
    double stocks[NUM_STOCKS];
    init_stocks(stocks);

    // Print the initial stock values
    print_stocks(stocks);

    // Simulate the stock market for NUM_DAYS days
    for (int i = 0; i < NUM_DAYS; i++) {
        update_stocks(stocks);
        print_stocks(stocks);

        // Sleep for one second between updates
        struct tm* current_time_ptr = &current_time;
        current_time_ptr->tm_sec += 1;
        time_t current_time_sec = mktime(current_time_ptr);
        sleep(current_time_sec - time(NULL));
    }

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 50
#define MAX_SYMBOL_LEN 10
#define UPDATE_INTERVAL 3600 // in seconds

// Company structure
typedef struct {
    char symbol[MAX_SYMBOL_LEN];
    float price;
    time_t last_update;
} Company;

Company companies[MAX_COMPANIES];
int num_companies = 0;

// Function to fetch stock price from an API (you can use a real API if you want)
float get_stock_price(const char *symbol) {
    // Placeholder function, replace it with a real API call
    float price = 50.0 + rand() / (float)RAND_MAX * 50.0;
    printf("Fetching stock price for %s...\n", symbol);
    sleep(1); // Simulate delay
    return price;
}

// Function to update all companies' stock prices
void update_prices() {
    for (int i = 0; i < num_companies; i++) {
        Company *company = &companies[i];
        float new_price = get_stock_price(company->symbol);
        printf("New price for %s: %.2f\n", company->symbol, new_price);
        company->price = new_price;
        company->last_update = time(NULL);
    }
}

int main() {
    srand(time(NULL));

    // Initialize some companies
    strcpy(companies[0].symbol, "AAPL");
    strcpy(companies[1].symbol, "GOOG");
    strcpy(companies[2].symbol, "MSFT");
    strcpy(companies[3].symbol, "AMZN");
    strcpy(companies[4].symbol, "TSLA");

    num_companies = 5;

    // Main loop
    while (1) {
        time_t current_time = time(NULL);
        int time_difference = (int)(current_time - companies[0].last_update);

        if (time_difference >= UPDATE_INTERVAL) {
            update_prices();
        }

        printf("\nCurrent time: %s", ctime(&current_time));
        for (int i = 0; i < num_companies; i++) {
            Company *company = &companies[i];
            printf("Symbol: %s, Price: %.2f, Last update: %s\n", company->symbol, company->price, ctime(&company->last_update));
        }

        sleep(1); // Sleep for a second
    }

    return 0;
}
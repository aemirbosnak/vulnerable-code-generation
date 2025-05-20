//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
// Stock market tracker program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold stock information
struct stock {
    char name[100];
    float price;
    float change;
    float percent_change;
};

// Function to calculate the stock's change and percent change
void calculate_change(struct stock *s) {
    s->change = s->price - s->price;
    s->percent_change = (s->change / s->price) * 100;
}

// Function to update the stock information
void update_stock(struct stock *s) {
    float price;
    scanf("%f", &price);
    s->price = price;
    calculate_change(s);
}

// Main function
int main() {
    struct stock stocks[5];
    int i;

    // Initialize the stock information
    for (i = 0; i < 5; i++) {
        strcpy(stocks[i].name, "Stock ");
        stocks[i].price = 100.0;
        calculate_change(&stocks[i]);
    }

    // Update the stock information
    for (i = 0; i < 5; i++) {
        update_stock(&stocks[i]);
    }

    // Print the stock information
    for (i = 0; i < 5; i++) {
        printf("Stock %d: %s\n", i + 1, stocks[i].name);
        printf("Price: %f\n", stocks[i].price);
        printf("Change: %f\n", stocks[i].change);
        printf("Percent Change: %f%%\n\n", stocks[i].percent_change);
    }

    return 0;
}
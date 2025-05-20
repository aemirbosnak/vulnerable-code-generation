//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define NUM_STOCKS 5

// Define a stock struct
typedef struct Stock {
    char name[20];
    float price;
    float change;
} Stock;

// Print the current information of a stock
void printStock(Stock stock) {
    printf("%s\n", stock.name);
    printf("Price: %.2f\n", stock.price);
    printf("Change: %.2f\n", stock.change);
    printf("\n");
}

int main() {
    // Create an array of 5 stocks
    Stock stocks[NUM_STOCKS] = {
        {"Apple", 130.64, 3.45},
        {"Microsoft", 244.99, -1.23},
        {"Amazon", 3322.12, 7.89},
        {"Facebook", 315.94, 0.56},
        {"Tesla", 700.00, -2.87}
    };

    // Print the current information of all stocks
    for (int i = 0; i < NUM_STOCKS; i++) {
        printStock(stocks[i]);
    }

    // Allow user to input which stock they want to track
    int choice;
    printf("Which stock would you like to track? (Enter 1-5): ");
    scanf("%d", &choice);
    printf("\n");

    // Loop until user exits program
    while (1) {
        // Print the current information of the chosen stock
        printStock(stocks[choice - 1]);
        printf("Enter 'q' to quit or any other key to continue: ");

        // Allow user to exit program by pressing 'q'
        char quit;
        scanf(" %c", &quit);
        if (quit == 'q') {
            break;
        }

        // Generate a random change in price for the chosen stock
        float randChange = ((float) rand() / RAND_MAX) * 10 - 5;
        stocks[choice - 1].price += randChange;
        stocks[choice - 1].change = randChange;

        // Clear console before printing updated stock information
        system("clear");

        // Print updated stock information
        printf("UPDATED:\n");
        printStock(stocks[choice - 1]);
    }

    return 0;
}
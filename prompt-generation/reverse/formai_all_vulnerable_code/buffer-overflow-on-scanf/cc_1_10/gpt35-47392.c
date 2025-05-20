//FormAI DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define MAX_NAME_LEN 20 // Maximum length of stock name
#define MAX_NUM_STOCKS 5 // Maximum number of stocks that can be tracked at once

// Define a struct to keep track of a stock's information
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int shares;
} Stock;

// Declare a function to print the stock information
void print_stock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Price: $%.2f\n", s.price);
    printf("Shares: %d\n", s.shares);
}

int main() {
    // Declare an array to hold the stocks
    Stock stocks[MAX_NUM_STOCKS];

    // Declare variables to get user input
    char choice;
    char name[MAX_NAME_LEN];
    float price;
    int shares;

    // Main loop
    while (1) {
        printf("Enter 'n' to add a new stock, 'p' to print all stocks, or 'q' to quit:\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                // Get stock information from user
                printf("Enter stock name (max %d characters): ", MAX_NAME_LEN);
                scanf("%s", name);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter shares: ");
                scanf("%d", &shares);

                // Create stock struct and add it to the array
                Stock new_stock = {0};
                strncpy(new_stock.name, name, MAX_NAME_LEN);
                new_stock.price = price;
                new_stock.shares = shares;

                for (int i=0; i<MAX_NUM_STOCKS; i++) {
                    if (stocks[i].shares == 0) {
                        stocks[i] = new_stock;
                        break;
                    }
                }

                printf("Stock added!\n");
                break;
            case 'p':
                // Print information about each stock
                for (int i=0; i<MAX_NUM_STOCKS; i++) {
                    if (stocks[i].shares != 0) {
                        print_stock(stocks[i]);
                        printf("\n");
                    }
                }
                break;
            case 'q':
                // Exit the program
                printf("Goodbye!\n");
                exit(0);
            default:
                // Handle any invalid input
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
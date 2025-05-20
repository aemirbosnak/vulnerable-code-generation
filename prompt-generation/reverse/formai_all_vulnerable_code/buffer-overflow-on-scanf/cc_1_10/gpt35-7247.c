//FormAI DATASET v1.0 Category: Stock market tracker ; Style: systematic
#include <stdio.h>

// Define the maximum number of stocks that can be tracked
#define MAX_STOCKS 5

// Define the maximum length of a company name
#define MAX_NAME_LENGTH 20

// Define a struct for storing stock information
struct stock {
    char name[MAX_NAME_LENGTH];
    double price;
};

// Function for adding a stock to the tracker
void add_stock(struct stock *tracker, int *num_stocks) {
    if (*num_stocks == MAX_STOCKS) {
        printf("Tracker is full, cannot add more stocks.\n");
        return;
    }

    struct stock new_stock;

    printf("Enter the name of the company: ");
    scanf("%s", new_stock.name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &new_stock.price);

    tracker[*num_stocks] = new_stock;
    (*num_stocks)++;

    printf("Stock added successfully.\n");
}

// Function for printing all the stocks in the tracker
void print_stocks(struct stock *tracker, int num_stocks) {
    printf("Stock Tracker:\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%d. %s: $%.2lf\n", i+1, tracker[i].name, tracker[i].price);
    }

    printf("End of Stock Tracker.\n");
}

// Function for finding the stock with the highest price
void highest_stock(struct stock *tracker, int num_stocks) {
    double highest_price = 0;
    int highest_index = 0;

    for (int i = 0; i < num_stocks; i++) {
        if (tracker[i].price > highest_price) {
            highest_price = tracker[i].price;
            highest_index = i;
        }
    }

    printf("The highest priced stock is %s at $%.2lf.\n", tracker[highest_index].name, tracker[highest_index].price);
}

int main() {
    struct stock stock_tracker[MAX_STOCKS];
    int num_stocks = 0;

    int choice;

    do {
        printf("\n");
        printf("Stock Tracker Menu:\n");
        printf("1. Add a stock\n");
        printf("2. View all stocks\n");
        printf("3. Find the highest priced stock\n");
        printf("4. Exit the program\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_stock(stock_tracker, &num_stocks);
                break;
            case 2:
                print_stocks(stock_tracker, num_stocks);
                break;
            case 3:
                highest_stock(stock_tracker, num_stocks);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
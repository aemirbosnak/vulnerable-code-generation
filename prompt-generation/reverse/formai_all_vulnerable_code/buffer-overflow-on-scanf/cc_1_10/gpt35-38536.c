//FormAI DATASET v1.0 Category: Stock market tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME 20

typedef struct stock {
    char name[MAX_NAME];
    float price;
    int quantity;
} Stock;

void display_options() {
    printf("\nChoose an operation: \n");
    printf("1. Add a Stock\n");
    printf("2. Remove a Stock\n");
    printf("3. Update Stock Price\n");
    printf("4. Update Stock Quantity\n");
    printf("5. Display Stock Details\n");
    printf("6. Exit\n");
}

int main() {

    int choice, stocks_count = 0;
    Stock stocks[MAX_STOCKS];

    while (1) {
        display_options();

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Stock new_stock;
                printf("Enter stock name: ");
                scanf("%s", new_stock.name);
                printf("Enter stock price: ");
                scanf("%f", &new_stock.price);
                printf("Enter stock quantity: ");
                scanf("%d", &new_stock.quantity);

                if (stocks_count < MAX_STOCKS) {
                    stocks[stocks_count++] = new_stock;
                    printf("Stock Added!\n");
                } else {
                    printf("Maximum number of stocks reached.\n");
                }
                break;
            }
            case 2: {
                int stock_index;
                printf("Enter index of stock to remove: ");
                scanf("%d", &stock_index);

                if (stock_index >= stocks_count || stock_index < 0) {
                    printf("Invalid index.\n");
                    break;
                }

                for (int i = stock_index; i < stocks_count - 1; i++) {
                    stocks[i] = stocks[i + 1];
                }
                stocks_count--;
                printf("Stock Removed!\n");
                break;
            }
            case 3: {
                int stock_index;
                float new_price;
                printf("Enter index of stock to update: ");
                scanf("%d", &stock_index);

                if (stock_index >= stocks_count || stock_index < 0) {
                    printf("Invalid index.\n");
                    break;
                }

                printf("Enter new price: ");
                scanf("%f", &new_price);

                stocks[stock_index].price = new_price;
                printf("Price Updated!\n");
                break;
            }
            case 4: {
                int stock_index;
                int new_quantity;
                printf("Enter index of stock to update: ");
                scanf("%d", &stock_index);

                if (stock_index >= stocks_count || stock_index < 0) {
                    printf("Invalid index.\n");
                    break;
                }

                printf("Enter new quantity: ");
                scanf("%d", &new_quantity);

                stocks[stock_index].quantity = new_quantity;
                printf("Quantity Updated!\n");
                break;
            }
            case 5: {
                printf("\n%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
                for (int i = 0; i < stocks_count; i++) {
                    printf("%-20s $%-9.2f %-5d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
                }
                break;
            }
            case 6: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid Choice. Try again.\n");
                break;
            }
        }
    }

    return 0;
}
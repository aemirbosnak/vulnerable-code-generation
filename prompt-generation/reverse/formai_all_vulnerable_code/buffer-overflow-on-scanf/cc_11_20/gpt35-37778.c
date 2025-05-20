//FormAI DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 5
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} stock_t;

int main() {
    int choice, count = 0;
    stock_t stocks[MAX_STOCKS];

    while (1) {
        // print menu options
        printf("\n1. Add stock\n2. Update stock price\n3. View all stock prices\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // add new stock
                if (count == MAX_STOCKS) {
                    printf("Maximum number of stocks reached!\n");
                } else {
                    stock_t new_stock;
                    printf("Enter stock name: ");
                    scanf("%s", new_stock.name);
                    printf("Enter stock price: ");
                    scanf("%f", &new_stock.price);
                    stocks[count++] = new_stock;
                }
                break;
            case 2:
                // update stock price
                if (count == 0) {
                    printf("No stocks added yet!\n");
                } else {
                    char stock_name[MAX_NAME_LEN];
                    int found = 0;
                    printf("Enter stock name: ");
                    scanf("%s", stock_name);

                    for (int i = 0; i < count; i++) {
                        if (strcmp(stocks[i].name, stock_name) == 0) {
                            printf("Current price of %s is %.2f\n", stocks[i].name, stocks[i].price);
                            printf("Enter new price: ");
                            scanf("%f", &stocks[i].price);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Stock not found!\n");
                    }
                }
                break;
            case 3:
                // view all stock prices
                if (count == 0) {
                    printf("No stocks added yet!\n");
                } else {
                    printf("%-20s %s\n", "Stock Name", "Price");
                    for (int i = 0; i < count; i++) {
                        printf("%-20s %.2f\n", stocks[i].name, stocks[i].price);
                    }
                }
                break;
            case 4:
                // exit program
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
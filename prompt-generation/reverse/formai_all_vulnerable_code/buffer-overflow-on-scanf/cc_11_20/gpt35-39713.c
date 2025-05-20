//FormAI DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[10];
    float price;
    float change;
} Stock;

void displayMenu() {
    printf("\nWelcome to the stock market tracker!\n");
    printf("1. Add a new Stock\n");
    printf("2. Display All Stocks\n");
    printf("3. Search for a Stock\n");
    printf("4. Sort by stock symbol\n");
    printf("5. Sort by price change\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    int stockCount = 0;
    Stock stocks[50];

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(stockCount == 50) {
                    printf("Maximum limit reached!\n");
                    break;
                }

                printf("\nEnter stock symbol: ");
                scanf("%s", stocks[stockCount].symbol);

                printf("\nEnter current price: ");
                scanf("%f", &stocks[stockCount].price);

                printf("\nEnter change in price: ");
                scanf("%f", &stocks[stockCount].change);

                stockCount++;
                printf("Stock added successfully!\n");
                break;

            case 2:
                if(stockCount == 0) {
                    printf("No stocks added yet.\n");
                    break;
                }

                printf("\nStocks in the system:\n");

                for(int i = 0; i < stockCount; i++) {
                    printf("\nStock %d\n", i+1);
                    printf("Symbol: %s\n", stocks[i].symbol);
                    printf("Price: %.2f\n", stocks[i].price);
                    printf("Price change: %.2f\n", stocks[i].change);
                }

                break;

            case 3:
                if(stockCount == 0) {
                    printf("No stocks added yet.\n");
                    break;
                }

                char s[10];
                printf("\nEnter stock symbol to search: ");
                scanf("%s", s);

                for(int i = 0; i < stockCount; i++) {
                    if(strcmp(stocks[i].symbol, s) == 0) {
                        printf("Symbol: %s\n", stocks[i].symbol);
                        printf("Price: %.2f\n", stocks[i].price);
                        printf("Price change: %.2f\n", stocks[i].change);
                        break;
                    }

                    if(i == stockCount - 1) {
                        printf("Stock not found!\n");
                    }
                }

                break;

            case 4:
                if(stockCount == 0) {
                    printf("No stocks added yet.\n");
                    break;
                }

                for(int i = 0; i < stockCount; i++) {
                    for(int j = 0; j < stockCount - 1; j++) {
                        if(strcmp(stocks[j].symbol, stocks[j+1].symbol) > 0) {
                            Stock temp = stocks[j+1];
                            stocks[j+1] = stocks[j];
                            stocks[j] = temp;
                        }
                    }
                }

                printf("Stocks sorted by stock symbol!\n");

                break;

            case 5:
                if(stockCount == 0) {
                    printf("No stocks added yet.\n");
                    break;
                }

                for(int i = 0; i < stockCount; i++) {
                    for(int j = 0; j < stockCount - 1; j++) {
                        if(stocks[j].change < stocks[j+1].change) {
                            Stock temp = stocks[j+1];
                            stocks[j+1] = stocks[j];
                            stocks[j] = temp;
                        }
                    }
                }

                printf("Stocks sorted by price change!\n");

                break;

            case 6:
                printf("Thank you for using the stock market tracker!\n");
                break;

            default:
                printf("Invalid choice! Please enter your choice again.\n");
        }

    } while(choice != 6);

    return 0;
}
//FormAI DATASET v1.0 Category: Stock market tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct Stock {
    char name[20];
    double price;
    double change;
};

int main() {
    struct Stock stocks[5];
    int choice, i;
    double newPrice;
    
    // Intializing Stock data
    strcpy(stocks[0].name, "AAPL");
    stocks[0].price = 135.39;
    stocks[0].change = 0.81;

    strcpy(stocks[1].name, "GOOG");
    stocks[1].price = 2047.63;
    stocks[1].change = -2.15;

    strcpy(stocks[2].name, "TSLA");
    stocks[2].price = 739.78;
    stocks[2].change = 1.32;

    strcpy(stocks[3].name, "AMZN");
    stocks[3].price = 3211.01;
    stocks[3].change = 0.45;

    strcpy(stocks[4].name, "FB");
    stocks[4].price = 275.00;
    stocks[4].change = -1.23;

    // Display and update stock data
    printf("Welcome to the Stock Market Tracker!\n\n");
    do {
        printf("Please select an option:\n");
        printf("1. View Stock Data\n");
        printf("2. Update Stock Data\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                printf("Stock Data:\n");
                for(i = 0; i < 5; i++) {
                    printf("%s: $%.2f %+.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
                }
                printf("\n");
                break;
            case 2:
                printf("Which stock would you like to update?\n");
                for(i = 0; i < 5; i++) {
                    printf("%d. %s\n", i+1, stocks[i].name);
                }
                printf("Choice: ");
                scanf("%d", &choice);
                printf("Enter new price: ");
                scanf("%lf", &newPrice);
                stocks[choice-1].change = (newPrice - stocks[choice-1].price) / stocks[choice-1].price * 100;
                stocks[choice-1].price = newPrice;
                printf("\n");
                break;
            case 3:
                printf("Thank you for using the Stock Market Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[20];
    float price;
    int quantity;
} Stock;

void display_menu() {
    printf("\n");
    printf("Stock Market Tracker\n");
    printf("1. Add a new stock\n");
    printf("2. Update stock price\n");
    printf("3. Update stock quantity\n");
    printf("4. View all stocks\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    int choice;
    Stock stocks[100];
    int num_stocks = 0;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_stocks == 100) {
                    printf("Maximum number of stocks reached.\n");
                } else {
                    printf("Enter stock name: ");
                    scanf("%s", stocks[num_stocks].name);
                    printf("Enter stock price: ");
                    scanf("%f", &stocks[num_stocks].price);
                    printf("Enter stock quantity: ");
                    scanf("%d", &stocks[num_stocks].quantity);
                    num_stocks++;
                }
                break;

            case 2:
                printf("Enter stock name: ");
                scanf("%s", stocks[num_stocks].name);
                printf("Enter new stock price: ");
                scanf("%f", &stocks[num_stocks].price);
                break;

            case 3:
                printf("Enter stock name: ");
                scanf("%s", stocks[num_stocks].name);
                printf("Enter new stock quantity: ");
                scanf("%d", &stocks[num_stocks].quantity);
                break;

            case 4:
                printf("\n");
                for (int i = 0; i < num_stocks; i++) {
                    printf("Stock Name: %s\n", stocks[i].name);
                    printf("Stock Price: $%.2f\n", stocks[i].price);
                    printf("Stock Quantity: %d\n\n", stocks[i].quantity);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 5);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void initStock(Stock* stock) {
    strcpy(stock->name, "");
    stock->price = 0.0;
    stock->quantity = 0;
}

void printStock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Price: $%.2f\n", stock.price);
    printf("Quantity: %d\n\n", stock.quantity);
}

int main() {
    int choice;
    char input[100];
    Stock stocks[MAX_STOCKS];

    initStock(&stocks[0]);

    while(1) {
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Stock\n");
        printf("4. View Stocks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the stock: ");
                scanf("%s", input);
                strcpy(stocks[0].name, input);
                printf("Enter the price of the stock: ");
                scanf("%f", &stocks[0].price);
                printf("Enter the quantity of the stock: ");
                scanf("%d", &stocks[0].quantity);
                printf("\nStock added successfully!\n");
                break;
            case 2:
                printf("Enter the name of the stock you want to remove: ");
                scanf("%s", input);
                for(int i=0; i<MAX_STOCKS; i++) {
                    if(strcmp(stocks[i].name, input) == 0) {
                        printf("\nStock removed successfully!\n");
                        initStock(&stocks[i]);
                    }
                }
                break;
            case 3:
                printf("Enter the name of the stock you want to update: ");
                scanf("%s", input);
                for(int i=0; i<MAX_STOCKS; i++) {
                    if(strcmp(stocks[i].name, input) == 0) {
                        printf("Enter the new price of the stock: ");
                        scanf("%f", &stocks[i].price);
                        printf("Enter the new quantity of the stock: ");
                        scanf("%d", &stocks[i].quantity);
                        printf("\nStock updated successfully!\n");
                    }
                }
                break;
            case 4:
                printf("\nCurrent Stocks:\n");
                for(int i=0; i<MAX_STOCKS; i++) {
                    if(strcmp(stocks[i].name, "")!= 0) {
                        printStock(stocks[i]);
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
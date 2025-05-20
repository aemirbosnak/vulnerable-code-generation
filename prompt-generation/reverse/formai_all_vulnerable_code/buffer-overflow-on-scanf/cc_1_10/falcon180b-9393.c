//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct Stock {
    char name[50];
    float price;
    int quantity;
};

void addStock(struct Stock stocks[], int size, char name[], float price, int quantity) {
    for (int i = 0; i < size; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].price += price;
            stocks[i].quantity += quantity;
            return;
        }
    }
    stocks[size].name[0] = '\0';
    strcpy(stocks[size].name, name);
    stocks[size].price = price;
    stocks[size].quantity = quantity;
    size++;
}

void removeStock(struct Stock stocks[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i].name[0] = '\0';
            stocks[i].price = 0;
            stocks[i].quantity = 0;
            return;
        }
    }
}

void displayStocks(struct Stock stocks[], int size) {
    printf("Name\tPrice\tQuantity\n");
    for (int i = 0; i < size; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%s\t%.2f\t%d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
        }
    }
}

int main() {
    struct Stock stocks[100];
    int size = 0;
    int choice;
    char name[50];
    float price;
    int quantity;

    do {
        printf("1. Add Stock\n2. Remove Stock\n3. Display Stocks\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter stock quantity: ");
                scanf("%d", &quantity);
                addStock(stocks, size, name, price, quantity);
                break;
            case 2:
                printf("Enter stock name: ");
                scanf("%s", name);
                removeStock(stocks, size, name);
                break;
            case 3:
                displayStocks(stocks, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
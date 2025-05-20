//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 10
#define MAX_NAME 20
#define MAX_QUANTITY 5

typedef struct {
    char name[MAX_NAME];
    int quantity;
} Stock;

void initStock(Stock *stock) {
    strcpy(stock->name, "");
    stock->quantity = 0;
}

void addStock(Stock *stock, char *name, int quantity) {
    strcpy(stock->name, name);
    stock->quantity += quantity;
}

void removeStock(Stock *stock, int quantity) {
    stock->quantity -= quantity;
}

void printStock(Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Quantity: %d\n", stock->quantity);
}

int main() {
    Stock stock[MAX_STOCK];
    int i, choice, quantity;
    char name[MAX_NAME];

    for (i = 0; i < MAX_STOCK; i++) {
        initStock(&stock[i]);
    }

    while (1) {
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Print stock\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name of stock: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addStock(&stock[0], name, quantity);
            break;
        case 2:
            printf("Enter name of stock: ");
            scanf("%s", name);
            printf("Enter quantity to remove: ");
            scanf("%d", &quantity);
            removeStock(&stock[0], quantity);
            break;
        case 3:
            printf("Name\tQuantity\n");
            for (i = 0; i < MAX_STOCK; i++) {
                printStock(&stock[i]);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
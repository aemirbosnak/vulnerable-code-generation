//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[20];
    int quantity;
    float price;
    int reorderLevel;
} Stock;

void addItem(Stock *stock, char *name, int quantity, float price, int reorderLevel) {
    strcpy(stock->name, name);
    stock->quantity = quantity;
    stock->price = price;
    stock->reorderLevel = reorderLevel;
}

void displayStock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Quantity: %d\n", stock.quantity);
    printf("Price: $%.2f\n", stock.price);
    printf("Reorder Level: %d\n", stock.reorderLevel);
}

int main() {
    Stock stock;
    char choice;
    int i = 0;
    do {
        printf("Medical Store Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Stock\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                printf("Enter the name of the item: ");
                scanf("%s", stock.name);
                printf("Enter the quantity: ");
                scanf("%d", &stock.quantity);
                printf("Enter the price: ");
                scanf("%f", &stock.price);
                printf("Enter the reorder level: ");
                scanf("%d", &stock.reorderLevel);
                printf("Item added successfully!\n");
                break;
            case '2':
                displayStock(stock);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '3');
    return 0;
}
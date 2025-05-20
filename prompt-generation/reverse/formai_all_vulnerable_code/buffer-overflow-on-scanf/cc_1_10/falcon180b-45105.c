//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item items[], int numItems) {
    char input[100];
    printf("Enter item name: ");
    scanf("%s", input);
    strcpy(items[numItems].name, input);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int numItems) {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("\nEnter 1 to add item, 0 to display items, -1 to quit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(items, numItems);
            break;
        case 0:
            displayItems(items, numItems);
            break;
        case -1:
            printf("\nExiting program...\n");
            exit(0);
        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    calculateTotal(items, numItems);

    return 0;
}
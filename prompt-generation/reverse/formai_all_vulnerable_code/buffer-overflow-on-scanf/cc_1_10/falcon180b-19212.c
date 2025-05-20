//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", items[numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[numItems].quantity);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Medieval Expense Tracker!\n");

    while (numItems < MAX_ITEMS) {
        printf("\nEnter 1 to add an item or 0 to display the list and calculate the total:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addItem(items, numItems);
        } else if (choice == 0) {
            displayItems(items, numItems);
            calculateTotal(items, numItems);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
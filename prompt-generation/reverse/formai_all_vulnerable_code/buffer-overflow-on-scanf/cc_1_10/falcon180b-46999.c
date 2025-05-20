//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void addItem(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(Item items[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int size = 0;

    printf("Welcome to Expense Tracker!\n");
    while (1) {
        printf("\n1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size >= MAX_ITEMS) {
                printf("Cannot add more items.\n");
            } else {
                addItem(items, &size);
            }
            break;
        case 2:
            if (size == 0) {
                printf("No items added yet.\n");
            } else {
                displayItems(items, size);
            }
            break;
        case 3:
            if (size == 0) {
                printf("No items added yet.\n");
            } else {
                calculateTotal(items, size);
            }
            break;
        case 4:
            printf("Thank you for using Expense Tracker!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
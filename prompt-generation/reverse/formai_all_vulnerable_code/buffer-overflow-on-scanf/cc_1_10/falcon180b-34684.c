//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} Item;

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item amount: $");
    scanf("%f", &items[*numItems].amount);
    (*numItems)++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItems:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2f\n", items[i].name, items[i].amount);
    }
}

void calculateTotal(Item items[], int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].amount;
    }
    printf("\nTotal: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    printf("Welcome to the Personal Finance Planner!\n\n");

    while (numItems < MAX_ITEMS) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                displayItems(items, numItems);
                break;
            case 3:
                calculateTotal(items, numItems);
                break;
            case 4:
                printf("\nThank you for using the Personal Finance Planner!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
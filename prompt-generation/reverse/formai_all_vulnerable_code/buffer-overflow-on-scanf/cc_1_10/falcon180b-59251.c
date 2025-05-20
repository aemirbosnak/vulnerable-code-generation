//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 //maximum number of items

struct item {
    char name[50];
    float price;
    int quantity;
};

void addItem(struct item items[], int count) {
    printf("Enter item name: ");
    scanf("%s", items[count].name);
    printf("Enter item price: ");
    scanf("%f", &items[count].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[count].quantity);
}

void displayItems(struct item items[], int count) {
    printf("\nItem List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f - %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void calculateTotal(struct item items[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    printf("Welcome to Expense Tracker!\n");
    while (count < MAX_ITEMS) {
        printf("\nDo you want to add an item? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            addItem(items, count);
            count++;
        } else if (choice == 'n' || choice == 'N') {
            printf("\nThank you for using Expense Tracker!\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    displayItems(items, count);
    calculateTotal(items, count);

    return 0;
}
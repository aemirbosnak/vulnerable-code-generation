//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void manageItems() {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price: ");
        scanf("%f", &items[i].price);
    }
}

void displayItems() {
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;

    printf("Welcome to the Charming Medical Store Management System!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Manage Items\n");
        printf("2. Display Items\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageItems();
                break;
            case 2:
                displayItems();
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Thank you for using the Charming Medical Store Management System!\n");
        break;
    }

    return 0;
}
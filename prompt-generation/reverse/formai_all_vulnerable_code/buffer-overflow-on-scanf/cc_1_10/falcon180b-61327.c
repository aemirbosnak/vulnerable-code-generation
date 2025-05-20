//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

struct Item {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
};

void addItem(struct Item items[], int count) {
    printf("Enter item name: ");
    scanf("%s", items[count].name);
    printf("Enter item description: ");
    scanf("%s", items[count].description);
    printf("Enter item quantity: ");
    scanf("%d", &items[count].quantity);
    printf("Enter item price: ");
    scanf("%lf", &items[count].price);
}

void displayItems(struct Item items[], int count) {
    printf("\nItem Name\tItem Description\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t\t%d\t\t$%.2lf\n", items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

int main() {
    struct Item items[MAX_ITEMS];
    int count = 0;
    char choice;

    do {
        printf("\n1. Add Item\n2. Display Items\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (count == MAX_ITEMS) {
                printf("Maximum number of items reached.\n");
            } else {
                addItem(items, count);
                count++;
            }
            break;
        case '2':
            displayItems(items, count);
            break;
        case '3':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}
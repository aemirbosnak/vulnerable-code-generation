//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20
#define MAX_QUANTITY 10

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int numItems) {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    printf("Enter item price: ");
    scanf("%f", &price);

    strcpy(items[numItems].name, name);
    items[numItems].quantity = quantity;
    items[numItems].price = price;

    printf("\nItem added successfully!\n");
}

void displayItems(Item items[], int numItems) {
    int i;

    printf("\nItem List:\n");
    for (i = 0; i < numItems; i++) {
        printf("%s - %d units - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculateTotal(Item items[], int numItems) {
    float total = 0.0;
    int i;

    for (i = 0; i < numItems; i++) {
        total += items[i].price * items[i].quantity;
    }

    printf("\nTotal: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("\nEnter 'a' to add an item or 'c' to calculate total: ");
        char choice = toupper(getchar());

        switch (choice) {
            case 'A':
                addItem(items, numItems);
                break;
            case 'C':
                calculateTotal(items, numItems);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
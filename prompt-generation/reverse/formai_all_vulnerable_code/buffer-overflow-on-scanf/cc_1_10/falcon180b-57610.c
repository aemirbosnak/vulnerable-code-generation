//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter price: ");
    scanf("%f", &items[*size].price);
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\nItems:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %d x %.2f = %.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
    }
}

void calculateTotal(Item items[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("\nTotal: %.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int size = 0;

    addItem(items, &size);
    while (size < MAX_ITEMS) {
        printf("\nDo you want to add more items? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (tolower(choice) == 'y') {
            addItem(items, &size);
        } else {
            displayItems(items, size);
            calculateTotal(items, size);
            break;
        }
    }

    return 0;
}
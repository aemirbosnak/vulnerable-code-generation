//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char name[MAX];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", (*size == 0? items[0].name : items[*size - 1].name));
    printf("Enter quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter price: ");
    scanf("%f", &items[*size].price);
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\nItems:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %d x %.2f = %.2f\n", i+1, items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
    }
}

void calculateTotal(Item items[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("\nTotal: %.2f\n", total);
}

int main() {
    Item items[MAX];
    int size = 0;

    addItem(items, &size);

    while (size > 0) {
        displayItems(items, size);
        calculateTotal(items, size);
        char choice;
        printf("\nDo you want to add more items? (y/n): ");
        scanf(" %c", &choice);
        if (tolower(choice) == 'n') {
            break;
        }
        addItem(items, &size);
    }

    return 0;
}
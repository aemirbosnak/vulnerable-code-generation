//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
} Item;

void addItem(Item items[], int count, char* name, float price) {
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum items reached.\n");
        return;
    }

    strcpy(items[count].name, name);
    items[count].price = price;

    printf("Item added: %s - $%.2f\n", items[count].name, items[count].price);
    count++;
}

void displayItems(Item items[], int count) {
    printf("\nItems:\n");

    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void calculateTotal(Item items[], int count) {
    float total = 0.0;

    for (int i = 0; i < count; i++) {
        total += items[i].price;
    }

    printf("\nTotal: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;

    printf("Welcome to the Expense Tracker!\n\n");

    while (1) {
        printf("\nEnter 'add' to add an item, 'display' to display items, 'total' to calculate total, or 'exit' to quit: ");
        scanf("%s", &items[count].name);

        if (strcmp(items[count].name, "add") == 0) {
            printf("Enter item name: ");
            scanf("%s", items[count].name);

            printf("Enter item price: ");
            scanf("%f", &items[count].price);

            addItem(items, count, items[count].name, items[count].price);
        } else if (strcmp(items[count].name, "display") == 0) {
            displayItems(items, count);
        } else if (strcmp(items[count].name, "total") == 0) {
            calculateTotal(items, count);
        } else if (strcmp(items[count].name, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }

        count++;
    }

    return 0;
}
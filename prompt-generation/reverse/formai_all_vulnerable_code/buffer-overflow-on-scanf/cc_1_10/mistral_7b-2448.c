//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Item;

void addItem(Item items[], char name[], float price, int *numItems);
void printReceipt(const Item items[], int numItems);

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (1) {
        printf("\n1. Add Item\n");
        printf("2. Print Receipt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                float price;
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: ");
                scanf("%f", &price);

                addItem(items, name, price, &numItems);
                break;
            }
            case 2: {
                printReceipt(items, numItems);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}

void addItem(Item items[], char name[], float price, int *numItems) {
    if (*numItems >= MAX_ITEMS) {
        printf("Cannot add more items!\n");
        return;
    }

    strcpy(items[*numItems].name, name);
    items[*numItems].price = price;
    items[*numItems].quantity = 1;

    (*numItems)++;
}

void printReceipt(const Item items[], int numItems) {
    printf("\n=====================\n");
    printf("|   CAFETERIA RECEIPT |\n");
    printf("=====================\n");

    float total = 0;

    for (int i = 0; i < numItems; i++) {
        printf("| %-*s | %6.2f | %d |\n", (int)(strlen(items[i].name) + 2), items[i].name, items[i].price, items[i].quantity);
        total += items[i].price * items[i].quantity;
    }

    printf("|--------------------|-------|------|\n");
    printf("| Subtotal           | %7.2f | %s |\n", total, "|");
    printf("| Tax (10%)           | %7.2f | %s |\n", total * 0.1, "|");
    printf("|--------------------|-------|------|\n");
    printf("| Total              | %7.2f |\n", total + total * 0.1);
}
//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

void addItem(Item items[], int *numItems, char name[], int quantity, float price);
void printBill(const Item items[], int numItems);

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (true) {
        printf("Enter 'A' to add an item, 'B' to print bill, or 'Q' to quit: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'A': {
                char name[MAX_NAME_LEN];
                int quantity;
                float price;

                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);

                addItem(items, &numItems, name, quantity, price);
                break;
            }
            case 'B': {
                printBill(items, numItems);
                break;
            }
            case 'Q': {
                printf("Quitting the system...\n");
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}

void addItem(Item items[], int *numItems, char name[], int quantity, float price) {
    if (*numItems >= MAX_ITEMS) {
        printf("Maximum number of items reached. Cannot add item.\n");
        return;
    }

    strcpy(items[*numItems].name, name);
    items[*numItems].quantity = quantity;
    items[*numItems].price = price;

    (*numItems)++;
}

void printBill(const Item items[], int numItems) {
    printf("\n--- CAFÉ BILLING SYSTEM ---\n");
    printf("------------------------------\n");

    float total = 0;

    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
        total += items[i].quantity * items[i].price;
    }

    printf("------------------------------\n");
    printf("Total:\t%.2f\n", total);
}
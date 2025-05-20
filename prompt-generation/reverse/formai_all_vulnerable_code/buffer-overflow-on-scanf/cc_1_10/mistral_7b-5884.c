//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Item;

void addItem(Item items[]);
void printReceipt(Item items[]);

Item items[MAX_ITEMS];
int numItems = 0;

int main() {
    char choice;

    do {
        printf("\n--- WELCOME TO C CAFE BILLING SYSTEM ---\n");
        printf("\n1. Add Item\n2. Print Receipt\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                addItem(items);
                break;
            case '2':
                printReceipt(items);
                break;
            case '3':
                printf("\nThank you for visiting C Cafe Billing System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    } while(1);

    return 0;
}

void addItem(Item items[]) {
    char name[MAX_NAME_LEN];
    int i, quantity;
    float price;

    if(numItems >= MAX_ITEMS) {
        printf("\nMaximum limit of %d items reached!", MAX_ITEMS);
        return;
    }

    printf("\nEnter item name: ");
    scanf("%s", name);
    strcpy(items[numItems].name, name);

    printf("\nEnter quantity: ");
    scanf("%d", &quantity);
    items[numItems].quantity = quantity;

    printf("\nEnter price per unit: ");
    scanf("%f", &price);
    items[numItems].price = price;

    numItems++;
}

void printReceipt(Item items[]) {
    float total = 0;
    int i;

    printf("\n--- C CAFE BILLING SYSTEM RECEIPT ---\n");
    printf("\nItem\t\tQuantity\tPrice per unit\tTotal\n");

    for(i = 0; i < numItems; i++) {
        printf("\n%s\t\t%d\t\t%.2f\t\t%.2f", items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
        total += items[i].quantity * items[i].price;
    }

    printf("\n\nTotal:\t%.2f", total);
}
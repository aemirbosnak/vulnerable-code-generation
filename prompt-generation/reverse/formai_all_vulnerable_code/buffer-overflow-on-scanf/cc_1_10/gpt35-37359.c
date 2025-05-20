//FormAI DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 50
#define MAX_CHAR 20

struct product {
    char name[MAX_CHAR];
    int quantity;
    float price;
};

int addProduct(struct product inventory[], int numProd);
int removeProduct(struct product inventory[], int numProd);
void printInventory(struct product inventory[], int numProd);

int main(void) {
    struct product inventory[MAX_PROD];
    int numProd = 0;
    char choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add a Product\n");
        printf("2. Remove a Product\n");
        printf("3. Print Inventory\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                numProd = addProduct(inventory, numProd);
                break;
            case '2':
                numProd = removeProduct(inventory, numProd);
                break;
            case '3':
                printInventory(inventory, numProd);
                break;
            case '4':
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice. Try Again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}

int addProduct(struct product inventory[], int numProd) {
    if (numProd < MAX_PROD) {
        printf("\nEnter the product name: ");
        scanf("%s", inventory[numProd].name);
        printf("Enter the product quantity: ");
        scanf("%d", &inventory[numProd].quantity);
        printf("Enter the product price: ");
        scanf("%f", &inventory[numProd].price);
        printf("\nProduct added successfully!\n");
        numProd++;
    } else {
        printf("\nProduct inventory is full.\n");
    }

    return numProd;
}

int removeProduct(struct product inventory[], int numProd) {
    char name[MAX_CHAR];
    int i, found = 0;

    printf("\nEnter the product name: ");
    scanf("%s", name);

    for (i = 0; i < numProd; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            found = 1;
            printf("\n%s removed from inventory.\n", name);
            inventory[i] = inventory[numProd - 1];
            numProd--;
            break;
        }
    }

    if (!found) {
        printf("\n%s not found in inventory.\n", name);
    }

    return numProd;
}

void printInventory(struct product inventory[], int numProd) {
    int i;

    printf("\nInventory\n");
    printf("---------\n");
    printf("Name             Quantity    Price\n");

    for (i = 0; i < numProd; i++) {
        printf("%-16s %-12d $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}
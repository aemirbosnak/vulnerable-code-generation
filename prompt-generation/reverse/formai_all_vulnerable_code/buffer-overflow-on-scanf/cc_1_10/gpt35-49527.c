//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Shape-shifting Warehouse Management System example program */

typedef struct item {
    char name[50];
    float price;
    int quantity;
} Item;

void printItem(Item i);
void addItem(Item *inventory, int *numItems);

int main() {
    int numItems = 0;
    char choice[10];
    Item inventory[100];

    while(1) {
        printf("Enter an option (add, print, exit): ");
        scanf("%s", choice);

        if(strcmp(choice, "add") == 0) {
            addItem(inventory, &numItems);
        } else if(strcmp(choice, "print") == 0) {
            for(int i = 0; i < numItems; i++) {
                printItem(inventory[i]);
            }
        } else if(strcmp(choice, "exit") == 0) {
            printf("Exiting program...");
            break;
        } else { 
            printf("Invalid option!\n"); 
        }
    }

    return 0;
}

void printItem(Item i) {
    printf("-------------------------\n");
    printf("Item: %s\n", i.name);
    printf("Price: $%.2f\n", i.price);
    printf("Quantity: %d\n", i.quantity);
    printf("-------------------------\n");
}

void addItem(Item *inventory, int *numItems) {
    char name[50];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item price: ");
    scanf("%f", &price);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    Item newItem;
    strcpy(newItem.name, name);
    newItem.price = price;
    newItem.quantity = quantity;

    inventory[*numItems] = newItem;
    (*numItems)++;
}
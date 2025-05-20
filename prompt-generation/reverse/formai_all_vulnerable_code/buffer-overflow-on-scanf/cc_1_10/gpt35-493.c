//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 20

struct Item {
    char name[20];
    int quantity;
    float price;
};

typedef struct Item Inventory;

void initialize(Inventory items[], int *numItems);
void addItem(Inventory items[], int *numItems);
void removeItem(Inventory items[], int *numItems);
void display(Inventory items[], int numItems);

int main() {
    Inventory items[MAX_ITEMS];
    int numItems = 0;
    int choice = 0;

    while(choice != 4) {
        printf("WELCOME TO RETRO INVENTORY SYSTEM\n");
        printf("--------------------------------\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Quit\n");
        printf("--------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                removeItem(items, &numItems);
                break;
            case 3:
                display(items, numItems);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

void initialize(Inventory items[], int *numItems) {
    *numItems = 0;
}

void addItem(Inventory items[], int *numItems) {
    if(*numItems < MAX_ITEMS) {
        printf("Enter Item Name: ");
        scanf("%s", items[*numItems].name);

        printf("Enter Item Price: ");
        scanf("%f", &items[*numItems].price);

        printf("Enter Item Quantity: ");
        scanf("%d", &items[*numItems].quantity);

        (*numItems)++;
    }
    else {
        printf("Inventory is full!\n");
    }
}

void removeItem(Inventory items[], int *numItems) {
    char itemName[20];
    int i, index = -1;

    printf("Enter Item Name: ");
    scanf("%s", itemName);

    for(i = 0; i < *numItems; i++) {
        if(strcmp(items[i].name, itemName) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Item not found!\n");
    }
    else {
        for(i = index; i < (*numItems - 1); i++) {
            items[i] = items[i + 1];
        }
        (*numItems)--;
        printf("Item removed from Inventory!\n");
    }
}

void display(Inventory items[], int numItems) {
    int i;

    if(numItems == 0) {
        printf("Inventory is empty!\n");
    }
    else {
        printf("ITEM NAME\tITEM PRICE\tITEM QUANTITY\n");
        for(i = 0; i < numItems; i++) {
            printf("%s\t\t$%.2f\t\t%d\n", items[i].name, items[i].price, items[i].quantity);
        }
    }
}
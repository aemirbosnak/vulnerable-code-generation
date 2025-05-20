//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

enum Options {AddItem, ListItems, UpdatePrice, UpdateQuantity, RemoveItem, QuitProgram};

void clearBuffer() {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void addItem(Item items[], int *numItems) {
    printf("\nEnter item name: ");
    fgets(items[*numItems].name, 50, stdin);
    clearBuffer();

    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    clearBuffer();

    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    clearBuffer();

    (*numItems)++;
}

void listItems(Item items[], int numItems) {
    printf("List of items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %.2f - %d in stock\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void updatePrice(Item items[], int numItems) {
    int index;
    printf("\nEnter index of item to update: ");
    scanf("%d", &index);
    clearBuffer();

    if (index <= 0 || index > numItems) {
        printf("\nInvalid index\n");
        return;
    }

    printf("\nEnter new price for %s: ", items[index-1].name);
    scanf("%f", &items[index-1].price);
    clearBuffer();

    printf("\nPrice updated!\n");
}

void updateQuantity(Item items[], int numItems) {
    int index;
    printf("\nEnter index of item to update: ");
    scanf("%d", &index);
    clearBuffer();

    if (index <= 0 || index > numItems) {
        printf("\nInvalid index\n");
        return;
    }

    printf("\nEnter new quantity for %s: ", items[index-1].name);
    scanf("%d", &items[index-1].quantity);
    clearBuffer();

    printf("\nQuantity updated!\n");
}

void removeItem(Item items[], int *numItems) {
    int index;
    printf("\nEnter index of item to remove: ");
    scanf("%d", &index);
    clearBuffer();

    if (index <= 0 || index > *numItems) {
        printf("\nInvalid index\n");
        return;
    }

    for (int i = index-1; i < *numItems-1; i++) {
        strcpy(items[i].name, items[i+1].name);
        items[i].price = items[i+1].price;
        items[i].quantity = items[i+1].quantity;
    }

    (*numItems)--;

    printf("\nItem removed!\n");
}

int printMenu() {
    int option;
    printf("\n1. Add item");
    printf("\n2. List items");
    printf("\n3. Update item price");
    printf("\n4. Update item quantity");
    printf("\n5. Remove item");
    printf("\n6. Quit program");

    printf("\n\nChoose an option: ");
    scanf("%d", &option);
    clearBuffer();

    return option;
}

int main() {
    Item items[100];
    int numItems = 0;
    int option = 0;

    while (option != QuitProgram) {
        option = printMenu();

        switch (option) {
            case AddItem:
                addItem(items, &numItems);
                break;
            case ListItems:
                listItems(items, numItems);
                break;
            case UpdatePrice:
                updatePrice(items, numItems);
                break;
            case UpdateQuantity:
                updateQuantity(items, numItems);
                break;
            case RemoveItem:
                removeItem(items, &numItems);
                break;
            case QuitProgram:
                printf("\nProgram terminated.\n");
                break;
            default:
                printf("\nInvalid option\n");
                break;
        }
    }

    return 0;
}
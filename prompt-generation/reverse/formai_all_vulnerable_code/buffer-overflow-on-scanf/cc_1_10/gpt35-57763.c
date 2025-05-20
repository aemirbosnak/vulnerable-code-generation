//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declare struct for warehouse item */
typedef struct {
    int item_id;
    char name[100];
    int quantity;
    float price;
} Item;

/* Declare function to add item to warehouse */
void addItem(Item** arr, int* size) {
    Item newItem;

    /* Get user input for new item attributes */
    printf("Enter item ID: ");
    scanf("%d", &newItem.item_id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    /* Reallocate array memory to store new item */
    *arr = realloc(*arr, (*size + 1) * sizeof(Item));
    (*arr)[*size] = newItem;
    (*size)++;
}

/* Declare function to remove item from warehouse */
void removeItem(Item** arr, int* size, int item_id) {
    int i, j;
    for (i = 0; i < *size; i++) {
        if ((*arr)[i].item_id == item_id) {
            /* Shift all elements after the removed item back one index */
            for (j = i; j < *size - 1; j++) {
                (*arr)[j] = (*arr)[j+1];
            }
            /* Decrease array size and reallocate memory */
            (*size)--;
            *arr = realloc(*arr, (*size) * sizeof(Item));
            return;
        }
    }
    printf("Item with ID %d not found.\n", item_id);
}

/* Declare function to display all items in warehouse */
void displayItems(Item* arr, int size) {
    int i;
    printf("Warehouse Inventory:\n");
    for (i = 0; i < size; i++) {
        printf("Item ID: %d\n", arr[i].item_id);
        printf("Item Name: %s\n", arr[i].name);
        printf("Item Quantity: %d\n", arr[i].quantity);
        printf("Item Price: %.2f\n", arr[i].price);
        printf("\n");
    }
}

int main() {
    Item* warehouse = NULL; /* Declare empty array */
    int numItems = 0;
    int choice, id;

    do {
        /* Display menu options */
        printf("Warehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(&warehouse, &numItems);
                break;
            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, &numItems, id);
                break;
            case 3:
                displayItems(warehouse, numItems);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    /* Free memory allocated for warehouse array */
    free(warehouse);

    return 0;
}
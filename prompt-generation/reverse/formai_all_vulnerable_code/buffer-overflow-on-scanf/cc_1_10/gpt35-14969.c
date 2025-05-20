//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define struct for item */
typedef struct item {
    char name[30];
    int quantity;
    float price;
} Item;

/* Function to add items to warehouse */
void add_item(Item warehouse[], int *num_items) {
    Item new_item;

    printf("\nEnter Item Name: ");
    scanf("%s", new_item.name);

    printf("Enter Item Quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter Item Price: ");
    scanf("%f", &new_item.price);

    warehouse[*num_items] = new_item;

    (*num_items)++;
}

/* Function to remove items from warehouse */
void remove_item(Item warehouse[], int *num_items) {
    char item_name[30];
    int i, found = 0;

    printf("\nEnter Item Name: ");
    scanf("%s", item_name);

    for (i = 0; i < *num_items; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < *num_items - 1; i++) {
            warehouse[i] = warehouse[i+1];
        }

        (*num_items)--;
        printf("\n%s Removed from Warehouse\n", item_name);
    } else {
        printf("\n%s Not Found in Warehouse\n", item_name);
    }
}

/* Function to update item's quantity in warehouse */
void update_item_quantity(Item warehouse[], int num_items) {
    char item_name[30];
    int i, found = 0, new_quantity;

    printf("\nEnter Item Name: ");
    scanf("%s", item_name);

    for (i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter New Quantity: ");
        scanf("%d", &new_quantity);

        warehouse[i].quantity = new_quantity;

        printf("\n%s Quantity Updated to %d\n", item_name, new_quantity);
    } else {
        printf("\n%s Not Found in Warehouse\n", item_name);
    }
}

/* Function to display items in warehouse */
void display_items(Item warehouse[], int num_items) {
    int i;

    printf("\nItems in Warehouse:\n");
    printf("-------------------\n");

    for (i = 0; i < num_items; i++) {
        printf("%s\tQuantity: %d\tPrice: %.2f\n", warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

int main() {
    int choice, num_items = 0;
    Item warehouse[100];

    do {
        /* Display menu */
        printf("\nWarehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Display Items\n");
        printf("5. Exit\n");

        /* Get user's choice */
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(warehouse, &num_items);
                break;
            case 2:
                remove_item(warehouse, &num_items);
                break;
            case 3:
                update_item_quantity(warehouse, num_items);
                break;
            case 4:
                display_items(warehouse, num_items);
                break;
            case 5:
                printf("\nExiting Program\n");
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice != 5);

    return 0;
}
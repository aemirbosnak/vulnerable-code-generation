//FormAI DATASET v1.0 Category: Product Inventory System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

/* Structure for each inventory item */
struct inventory_item {
    char name[50];
    int quantity;
    float price;
};

/* Array to hold all inventory items */
struct inventory_item items[MAX_ITEMS];

/* Function prototypes */
void add_item();
void search_item();
void remove_item();
void display_all();

int main() {
    int choice;

    while(1) {
        printf("\n1. Add Item\n2. Search Item\n3. Remove Item\n4. Display All Items\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                search_item();
                break;
            case 3:
                remove_item();
                break;
            case 4:
                display_all();
                break;
            case 5:
                printf("\nThank you for using the inventory system!");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose a valid option.");
        }
    }
    return 0;
}

/* Function to add an item to the inventory */
void add_item() {
    struct inventory_item item;
    int index = -1;

    printf("\nEnter name of item: ");
    scanf(" %[^\n]", item.name);

    printf("Enter quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter price: ");
    scanf("%f", &item.price);

    for(int i=0; i<MAX_ITEMS; i++) {
        if(items[i].quantity == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nInventory full! Cannot add more items.");
        return;
    }

    items[index] = item;
    printf("\nItem added successfully!");
}

/* Function to search for an item in the inventory */
void search_item() {
    char name[50];
    int found = 0;

    printf("\nEnter name of item to search for: ");
    scanf(" %[^\n]", name);

    for(int i=0; i<MAX_ITEMS; i++) {
        if(strcmp(items[i].name, name) == 0) {
            printf("\nItem found!\nName: %s\nQuantity: %d\nPrice: $%.2f\n", items[i].name, items[i].quantity, items[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nItem not found!");
    }
}

/* Function to remove an item from the inventory */
void remove_item() {
    char name[50];
    int found = 0;

    printf("\nEnter name of item to remove: ");
    scanf(" %[^\n]", name);

    for(int i=0; i<MAX_ITEMS; i++) {
        if(strcmp(items[i].name, name) == 0) {
            items[i].quantity = 0;
            memset(items[i].name, 0, sizeof(items[i].name));
            items[i].price = 0.0;
            printf("\nItem removed successfully!");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nItem not found!");
    }
}

/* Function to display all items in the inventory */
void display_all() {
    printf("\nAll Items in Inventory:\n");
    for(int i=0; i<MAX_ITEMS; i++) {
        if(items[i].quantity != 0) {
            printf("Name: %s\nQuantity: %d\nPrice: $%.2f\n\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}
//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining constants for the maximum amount of items and their respective names and prices */
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 1000

/* Defining the Item struct */
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int price;
    int quantity;
} Item;

/* Declaring the functions */
void add_item(Item items[], int *num_items);
void display_items(Item items[], int num_items);
Item* find_item_by_name(Item items[], int num_items, char name[]);

/* The main function */
int main() {
    int choice, num_items = 0;
    Item items[MAX_ITEMS];

    /* The main menu */
    while(1) {
        printf("\nWelcome to the Warehouse Management System!");
        printf("\nPlease choose one of the following options:\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Find Item by Name\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item(items, &num_items);
                break;

            case 2:
                display_items(items, num_items);
                break;

            case 3: {
                char name[MAX_NAME_LENGTH];
                printf("Please enter the name of the item: ");
                scanf("%s", name);
                Item *found_item = find_item_by_name(items, num_items, name);
                if(found_item == NULL)
                    printf("Item not found.\n");
                else
                    printf("Item found! Name: %s, Price: $%d, Quantity: %d\n", found_item->name, found_item->price, found_item->quantity);
                break;
            }

            case 4:
                printf("Thank you for using the Warehouse Management System!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

/* The function to add an item */
void add_item(Item items[], int *num_items) {
    if(*num_items == MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }

    Item new_item;
    printf("Please enter the name of the item: ");
    scanf("%s", new_item.name);
    printf("Please enter the price of the item: ");
    scanf("%d", &new_item.price);
    printf("Please enter the quantity of the item: ");
    scanf("%d", &new_item.quantity);

    if(new_item.price > MAX_PRICE) {
        printf("Price is too high.\n");
        return;
    }

    items[*num_items] = new_item;
    (*num_items)++;

    printf("Item added successfully!\n");
}

/* The function to display all items in the warehouse */
void display_items(Item items[], int num_items) {
    if(num_items == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("Warehouse Items:\n");
    for(int i=0; i<num_items; i++)
        printf("%d. Name: %s, Price: $%d, Quantity: %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
}

/* The function to find an item by name */
Item* find_item_by_name(Item items[], int num_items, char name[]) {
    for(int i=0; i<num_items; i++) {
        if(strcmp(items[i].name, name) == 0)
            return &items[i];
    }

    return NULL;
}
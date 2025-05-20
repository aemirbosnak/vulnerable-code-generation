//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
/* The following program is a Warehouse Management System that uses 
   the concepts of Claude Shannon's Information Theory to optimize 
   the storage and retrieval of items in a warehouse. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20

/* Define a structure that represents each item in the warehouse */
struct item {
    char name[MAX_NAME_LENGTH];
    int quantity;
};

/* Declare a dynamic array of items to hold items */
struct item *items;

/* Declare a function to add a new item to the warehouse */
void add_item(char name[], int quantity);

/* Declare a function to search for an item in the warehouse */
int search_item(char name[]);

/* Declare a function to remove an item from the warehouse */
void remove_item(char name[]);

/* Declare a function to display all items in the warehouse */
void display_items();

/* Define the main function */
int main()
{
    char name[MAX_NAME_LENGTH];
    int quantity, choice;

    /* Allocate memory for the array of items */
    items = (struct item*) malloc (MAX_ITEMS * sizeof(struct item));

    do {
        printf("\n\nWarehouse Management System\n\n");
        printf("1. Add Item\n");
        printf("2. Search Item\n");
        printf("3. Remove Item\n");
        printf("4. Display Items\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("\nEnter the name of the item: ");
                    scanf("%s", name);
                    printf("Enter the quantity of the item: ");
                    scanf("%d", &quantity);
                    add_item(name, quantity);
                    break;

            case 2: printf("\nEnter the name of the item: ");
                    scanf("%s", name);
                    int index = search_item(name);
                    if (index == -1) {
                        printf("\nThe item could not be found.\n");
                    } else {
                        printf("\nThe item is present at index: %d\n", index);
                    }
                    break;

            case 3: printf("\nEnter the name of the item: ");
                    scanf("%s", name);
                    remove_item(name);
                    break;

            case 4: display_items();
                    break;

            case 5: printf("\nExiting...\n");
                    exit(0);

            default: printf("\nInvalid choice.\n");
                     break;
        }
    } while (choice != 5);

    /* Free the memory allocated by the array of items */
    free(items);

    return 0;
}

/* Define the function to add a new item to the warehouse */
void add_item(char name[], int quantity)
{
    /* Check if the item already exists */
    int index = search_item(name);

    if (index == -1) {
        /* The item does not exist, add it */
        int i;
        for (i = 0; i < MAX_ITEMS; i++) {
            if (items[i].quantity == 0) {
                /* Found an empty location, add the item */
                strncpy(items[i].name, name, MAX_NAME_LENGTH);
                items[i].quantity = quantity;
                printf("\nThe item has been added.\n");
                break;
            }
        }
        if (i == MAX_ITEMS) {
            /* The array is full, cannot add the item */
            printf("\nThe warehouse is full, cannot add the item.\n");
        }
    } else {
        /* The item already exists, increase the quantity */
        items[index].quantity += quantity;
        printf("\nThe quantity has been updated.\n");
    }
}

/* Define the function to search for an item in the warehouse */
int search_item(char name[])
{
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            /* Found the item */
            return i;
        }
    }
    /* Item not found */
    return -1;
}

/* Define the function to remove an item from the warehouse */
void remove_item(char name[])
{
    int index = search_item(name);

    if (index == -1) {
        /* Item not found */
        printf("\nThe item could not be found.\n");
    } else {
        /* Item found, set the quantity to zero */
        items[index].quantity = 0;
        printf("\nThe item has been removed.\n");
    }
}

/* Define the function to display all items in the warehouse */
void display_items()
{
    int i;
    printf("\nItems in Warehouse\n");
    printf("-------------------\n");
    printf("Name               Quantity\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity != 0) {
            printf("%-20s %-10d\n", items[i].name, items[i].quantity);
        }
    }
}
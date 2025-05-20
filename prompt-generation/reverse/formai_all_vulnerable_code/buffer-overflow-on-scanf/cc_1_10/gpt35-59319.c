//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Warehouse item structure */
struct Item {
    char name[50];
    int quantity;
    float price;
};

/* Function to add an item to the warehouse */
void add_item(struct Item items[], int *num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*num_items].name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &items[*num_items].quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &items[*num_items].price);
    (*num_items)++;
    printf("The item has been added successfully!\n");
}

/* Function to remove an item from the warehouse */
void remove_item(struct Item items[], int *num_items) {
    int i, index=-1;
    char name[50];
    printf("Enter the name of the item you want to remove: ");
    scanf("%s", name);
    for(i=0; i<*num_items; i++) {
        if(strcmp(items[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("The item was not found in the warehouse.\n");
    } else {
        for(i=index; i<*num_items-1; i++) {
            items[i] = items[i+1];
        }
        (*num_items)--;
        printf("The item has been removed successfully!\n");
    }
}

/* Function to display all items in the warehouse */
void display_items(struct Item items[], int num_items) {
    int i;
    printf("Warehouse items:\n");
    for(i=0; i<num_items; i++) {
        printf("%s - Quantity: %d - Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

/* Main function */
int main() {
    struct Item items[100];
    int num_items = 0, selection;
    char choice = 'y';
    while(choice == 'y' || choice == 'Y') {
        printf("Warehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Enter your selection (1-4): ");
        scanf("%d", &selection);
        switch(selection) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                display_items(items, num_items);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid selection!\n");
        }
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);
    }
    return 0;
}
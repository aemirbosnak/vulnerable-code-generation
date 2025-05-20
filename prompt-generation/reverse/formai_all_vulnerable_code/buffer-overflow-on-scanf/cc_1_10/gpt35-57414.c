//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000 // maximum items allowed in the warehouse
#define MAX_NAME_SIZE 50 // maximum characters allowed in the name of an item

// Definition of an item in the warehouse
typedef struct Item {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Item;

// Array to hold all items in the warehouse
Item items[MAX_ITEMS];

// Variable to hold the total number of items currently in the warehouse
int num_items = 0;

// Function to add a new item to the warehouse
void addItem() {
    if(num_items < MAX_ITEMS) {
        printf("Enter name of item: ");
        scanf("%s", items[num_items].name);
        printf("Enter quantity of item: ");
        scanf("%d", &items[num_items].quantity);
        printf("Enter price of item: ");
        scanf("%f", &items[num_items].price);
        num_items++;
        printf("Item added successfully!\n\n");
    } else {
        printf("Warehouse is full! No more items can be added.\n\n");
    }
}

// Function to remove an item from the warehouse
void removeItem() {
    if(num_items > 0) {
        char name[MAX_NAME_SIZE];
        printf("Enter name of item to be removed: ");
        scanf("%s", name);
        int i, index = -1;
        for(i = 0; i < num_items; i++) {
            if(strcmp(items[i].name, name) == 0) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            printf("Item not found in the warehouse!\n\n");
        } else {
            for(i = index; i < num_items - 1; i++) {
                items[i] = items[i+1];
            }
            num_items--;
            printf("Item removed successfully!\n\n");
        }
    } else {
        printf("Warehouse is empty! No items to remove.\n\n");
    }
}

// Function to display all items in the warehouse
void displayItems() {
    if(num_items == 0) {
        printf("Warehouse is empty! No items to display.\n\n");
    } else {
        printf("Name\tQuantity\tPrice\n");
        int i;
        for(i = 0; i < num_items; i++) {
            printf("%s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Mind-Bending Warehouse Management System!\n");
    int choice;
    while(1) {
        printf("\n1. Add Item\n2. Remove Item\n3. Display Items\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                printf("Thank you for using the Mind-Bending Warehouse Management System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n\n");
        }
    }
    return 0;
}
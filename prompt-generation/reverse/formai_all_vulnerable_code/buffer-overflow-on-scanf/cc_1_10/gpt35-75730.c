//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for each item in the warehouse
struct Item {
    char name[50];
    int quantity;
};

typedef struct Item item;

// Function to add item to the warehouse
void addItem(int n, item *items) {
    printf("Enter item name: ");
    scanf("%s", items[n].name);
    printf("Enter quantity: ");
    scanf("%d", &items[n].quantity);
}

// Function to remove item from the warehouse
void removeItem(int n, item *items) {
    char name[50];
    printf("Enter item name: ");
    scanf("%s", name);
    for(int i=0; i<n; i++) {
        if(strcmp(items[i].name, name) == 0) {
            printf("Item removed succesfully\n");
            items[i].quantity = 0;
        }
    }
}

// Function to display all items in the warehouse
void displayItems(int n, item *items) {
    for(int i=0; i<n; i++) {
        printf("Item name: %s\n", items[i].name);
        printf("Quantity: %d\n\n", items[i].quantity);
    }
}

int main() {
    int n, option;
    printf("Enter number of items in the warehouse: ");
    scanf("%d", &n);
    
    item *items = (item *) malloc(n * sizeof(item));
    
    for(int i=0; i<n; i++) {
        printf("Enter details of item %d:\n", i+1);
        addItem(i, items);
    }
    
    printf("\nWarehouse Management System\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Display all items\n");
    printf("4. Exit\n");
    
    while(1) {
        printf("\nEnter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addItem(n, items);
                n++;
                break;
            case 2:
                removeItem(n, items);
                break;
            case 3:
                displayItems(n, items);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    
    free(items);
    
    return 0;
}
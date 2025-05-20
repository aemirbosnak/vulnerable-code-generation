//FormAI DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100 //Maximum number of items that can be stored in inventory

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item; //Structure to store item details

Item inventory[MAX_ITEMS]; //Global inventory array

int num_items = 0; //Initial number of items in inventory

void add_item() {
    if(num_items < MAX_ITEMS) {
        printf("\nEnter item name: ");
        scanf("%s", inventory[num_items].name);
        printf("Enter item quantity: ");
        scanf("%d", &inventory[num_items].quantity);
        printf("Enter item price: ");
        scanf("%f", &inventory[num_items].price);
        printf("\nItem added successfully!\n");
        num_items++;
    } else {
        printf("\nSorry, inventory is full. Cannot add more items.\n");
    }
}

void remove_item() {
    if(num_items > 0) {
        char name[50];
        int index = -1;
        printf("\nEnter the name of the item you want to remove: ");
        scanf("%s", name);
        for(int i = 0; i < num_items; i++) {
            if(strcmp(name, inventory[i].name) == 0) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            printf("\nSorry, item not found in inventory.\n");
        } else {
            for(int i = index; i < num_items - 1; i++) {
                inventory[i] = inventory[i+1];
            }
            printf("\nItem removed successfully!\n");
            num_items--;
        }
    } else {
        printf("\nSorry, inventory is empty. Cannot remove any items.\n");
    }
}

void view_inventory() {
    if(num_items > 0) {
        printf("\nName\tQuantity\tPrice\n");
        printf("==================================\n");
        for(int i = 0; i < num_items; i++) {
            printf("%s\t%d\t\t%f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    } else {
        printf("\nSorry, inventory is empty. Cannot view any items.\n");
    }
}

int main() {
    int choice;
    printf("\nWelcome to the Inventory System!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                printf("\nThank you for using the Inventory System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(1); //Infinite loop to keep the program running until user exits
    return 0;
}
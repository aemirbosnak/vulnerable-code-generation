//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for medicine item
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

// Define global variables for medicine inventory
struct Medicine inventory[100];
int num_items = 0;

// Function to add a new medicine item to the inventory
void add_item(char *name, int quantity, float price) {
    struct Medicine item;
    strcpy(item.name, name);
    item.quantity = quantity;
    item.price = price;
    inventory[num_items] = item;
    num_items++;
    printf("Medicine added to inventory successfully!\n");
}

// Function to display the entire inventory
void display_inventory() {
    printf("Current inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s | Quantity: %d | Price: $%.2f\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search for a medicine item in the inventory
void search_item(char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found in inventory:\n");
            printf("%s | Quantity: %d | Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine not found in inventory!\n");
}

// Function to update the quantity of a medicine item in the inventory
void update_quantity(char *name, int new_quantity) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = new_quantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found in inventory!\n");
}

// Main function to prompt user for options and execute functions accordingly
int main() {
    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add new medicine item to inventory\n");
        printf("2. Display entire inventory\n");
        printf("3. Search for a medicine item in the inventory\n");
        printf("4. Update the quantity of a medicine item in the inventory\n");
        printf("5. Exit\n");

        int option;
        printf("\nEnter option number: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter name of medicine: ");
                char name[50];
                scanf("%s", name);
                printf("Enter quantity of medicine: ");
                int quantity;
                scanf("%d", &quantity);
                printf("Enter price of medicine: ");
                float price;
                scanf("%f", &price);
                add_item(name, quantity, price);
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                printf("\nEnter name of medicine to search: ");
                scanf("%s", name);
                search_item(name);
                break;
            case 4:
                printf("\nEnter name of medicine to update: ");
                scanf("%s", name);
                printf("Enter new quantity of medicine: ");
                scanf("%d", &quantity);
                update_quantity(name, quantity);
                break;
            case 5:
                printf("\nThank you for using the Medical Store Management System!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    }

    return 0;
}
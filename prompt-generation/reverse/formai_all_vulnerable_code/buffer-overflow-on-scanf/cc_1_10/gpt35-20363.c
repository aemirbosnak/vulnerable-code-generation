//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#define MAX_MEDICINES 100

// Struct for each medicine's details
struct medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

// Array to hold inventory of medicines
struct medicine inventory[MAX_MEDICINES];

// Function to add medicine to inventory
void add_medicine() {
    int n;
    printf("How many medicines would you like to add?\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter medicine name: ");
        scanf("%s", inventory[i].name);
        printf("Enter manufacturer name: ");
        scanf("%s", inventory[i].manufacturer);
        printf("Enter price: ");
        scanf("%f", &inventory[i].price);
        printf("Enter quantity: ");
        scanf("%d", &inventory[i].quantity);
    }
}

// Function to display inventory of medicines
void display_inventory() {
    printf("Medicine Name\t\tManufacturer\t\tPrice\t\tQuantity\n");
    for (int i = 0; i < MAX_MEDICINES; i++) {
        if (strlen(inventory[i].name) > 0) {
            printf("%s\t\t%s\t\t%.2f\t\t%d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
        }
    }
}

// Function to search for medicine by name
void search_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_MEDICINES; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine Name\t\tManufacturer\t\tPrice\t\tQuantity\n");
            printf("%s\t\t%s\t\t%.2f\t\t%d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Medicine %s not found.\n", name);
}

// Function to update quantity of medicine in inventory
void update_quantity() {
    char name[50];
    int new_quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_MEDICINES; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &new_quantity);
            inventory[i].quantity = new_quantity;
            printf("Quantity of %s updated to %d.\n", name, new_quantity);
            return;
        }
    }
    printf("Medicine %s not found.\n", name);
}

int main() {
    int option;
    while(1) {
        printf("\n====== Medical Store Management System ======\n");
        printf("1. Add medicine\n");
        printf("2. Display inventory\n");
        printf("3. Search medicine\n");
        printf("4. Update quantity of medicine\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_quantity();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid option selected.\n");
        }
    }
    return 0;
}
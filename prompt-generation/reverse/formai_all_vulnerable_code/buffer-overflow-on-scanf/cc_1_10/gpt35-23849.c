//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <string.h>

// Define a Product structure
struct Product {
    int id;
    char name[50];
    int quantity;
};

// Declare global variables
struct Product inventory[100];
int count = 0;

// Declare function prototypes
void add_product();
void remove_product();
void update_quantity();
void display_inventory();

int main() {
    int choice;
    do {
        printf("\n===== Product Inventory System =====\n");
        printf("| 1. Add a Product                  |\n");
        printf("| 2. Remove a Product               |\n");
        printf("| 3. Update Quantity of a Product   |\n");
        printf("| 4. Display Inventory              |\n");
        printf("| 5. Exit                           |\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_quantity();
                break;
            case 4:
                display_inventory();
                break;
            case 5:
                printf("\nThank you for using Product Inventory System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

// Function to add a product
void add_product() {
    struct Product p;
    printf("\nEnter Product ID: ");
    scanf("%d", &p.id);
    printf("Enter Product Name: ");
    scanf("%s", p.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &p.quantity);
    inventory[count] = p;
    count++;
    printf("\nProduct added successfully!\n");
}

// Function to remove a product
void remove_product() {
    int id, flag = 0, i;
    printf("\nEnter Product ID to remove: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            inventory[i] = inventory[count - 1];
            count--;
            flag = 1;
        }
    }
    if (flag == 1) {
        printf("\nProduct removed successfully!\n");
    } else {
        printf("\nProduct not found.\n");
    }
}

// Function to update quantity of a product
void update_quantity() {
    int id, quantity, flag = 0, i;
    printf("\nEnter Product ID to update quantity: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            flag = 1;
        }
    }
    if (flag == 1) {
        printf("\nQuantity updated successfully!\n");
    } else {
        printf("\nProduct not found.\n");
    }
}

// Function to display inventory
void display_inventory() {
    printf("\n===== Product Inventory =====\n");
    printf("| ID\t| Name\t\t| Quantity\t|\n");
    printf("===============================\n");
    for (int i = 0; i < count; i++) {
        printf("| %d\t| %s\t| %d\t\t|\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
    printf("===============================\n");
}
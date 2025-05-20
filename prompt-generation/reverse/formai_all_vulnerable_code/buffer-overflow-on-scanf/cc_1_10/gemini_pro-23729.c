//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *count) {
    // Get medicine details from user
    printf("Enter medicine name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter medicine company: ");
    scanf("%s", inventory[*count].company);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*count].price);

    // Increment the count of medicines
    (*count)++;
}

// Function to search for a medicine by name
void searchMedicine(medicine *inventory, int count) {
    char name[50];

    // Get medicine name from user
    printf("Enter medicine name: ");
    scanf("%s", name);

    // Search for the medicine
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Print medicine details
            printf("Medicine name: %s\n", inventory[i].name);
            printf("Medicine company: %s\n", inventory[i].company);
            printf("Medicine quantity: %d\n", inventory[i].quantity);
            printf("Medicine price: %.2f\n", inventory[i].price);

            return;
        }
    }

    // Medicine not found
    printf("Medicine not found.\n");
}

// Function to sell a medicine
void sellMedicine(medicine *inventory, int *count) {
    char name[50];
    int quantity;

    // Get medicine name and quantity from user
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);

    // Search for the medicine
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Check if the quantity is available
            if (inventory[i].quantity >= quantity) {
                // Decrement the quantity
                inventory[i].quantity -= quantity;

                // Calculate the total price
                float total_price = inventory[i].price * quantity;

                // Print the transaction details
                printf("Medicine name: %s\n", inventory[i].name);
                printf("Medicine quantity: %d\n", quantity);
                printf("Medicine price: %.2f\n", inventory[i].price);
                printf("Total price: %.2f\n", total_price);

                return;
            } else {
                // Quantity not available
                printf("Insufficient quantity.\n");
                return;
            }
        }
    }

    // Medicine not found
    printf("Medicine not found.\n");
}

// Function to display the inventory
void displayInventory(medicine *inventory, int count) {
    printf("Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("Medicine name: %s\n", inventory[i].name);
        printf("Medicine company: %s\n", inventory[i].company);
        printf("Medicine quantity: %d\n", inventory[i].quantity);
        printf("Medicine price: %.2f\n", inventory[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the inventory
    medicine inventory[100];
    int count = 0;

    // Display the menu
    int choice;
    do {
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Sell a medicine\n");
        printf("4. Display the inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                searchMedicine(inventory, count);
                break;
            case 3:
                sellMedicine(inventory, &count);
                break;
            case 4:
                displayInventory(inventory, count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *count) {
    // Get the details of the new medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*count].name);
    printf("Enter the company name: ");
    scanf("%s", inventory[*count].company);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*count].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*count].quantity);

    // Increment the count of medicines in the inventory
    (*count)++;
}

// Function to search for a medicine in the inventory
void searchMedicine(medicine *inventory, int count) {
    // Get the name of the medicine to be searched
    char searchName[50];
    printf("Enter the name of the medicine to be searched: ");
    scanf("%s", searchName);

    // Search for the medicine in the inventory
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            // Medicine found
            printf("Medicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Company: %s\n", inventory[i].company);
            printf("Price: %f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    // If medicine not found
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to update the quantity of a medicine in the inventory
void updateQuantity(medicine *inventory, int count) {
    // Get the name of the medicine to be updated
    char updateName[50];
    printf("Enter the name of the medicine to be updated: ");
    scanf("%s", updateName);

    // Search for the medicine in the inventory
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, updateName) == 0) {
            // Medicine found
            printf("Medicine found!\n");

            // Get the new quantity
            int newQuantity;
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);

            // Update the quantity
            inventory[i].quantity = newQuantity;
            found = 1;
            break;
        }
    }

    // If medicine not found
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to display the inventory
void displayInventory(medicine *inventory, int count) {
    // Print the header
    printf("Medicine Inventory\n");
    printf("--------------------\n");
    printf("%-20s%-20s%-10s%-10s\n", "Name", "Company", "Price", "Quantity");

    // Print the details of each medicine
    for (int i = 0; i < count; i++) {
        printf("%-20s%-20s%-10.2f%-10d\n", inventory[i].name, inventory[i].company, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Create an array to store the inventory
    medicine inventory[100];

    // Initialize the count of medicines in the inventory to 0
    int count = 0;

    // Display the menu
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("--------------------------------\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Update the quantity of a medicine\n");
        printf("4. Display the inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                searchMedicine(inventory, count);
                break;
            case 3:
                updateQuantity(inventory, count);
                break;
            case 4:
                displayInventory(inventory, count);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
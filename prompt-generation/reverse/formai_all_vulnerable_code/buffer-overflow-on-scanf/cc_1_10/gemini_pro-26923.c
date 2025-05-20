//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *num_medicines) {
    // Get the details of the new medicine from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*num_medicines].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*num_medicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*num_medicines].quantity);

    // Increment the number of medicines in the inventory
    (*num_medicines)++;
}

// Function to display the inventory of medicines
void displayInventory(medicine *inventory, int num_medicines) {
    // Print the details of each medicine in the inventory
    for (int i = 0; i < num_medicines; i++) {
        printf("Medicine Name: %s\n", inventory[i].name);
        printf("Medicine Price: %.2f\n", inventory[i].price);
        printf("Medicine Quantity: %d\n\n", inventory[i].quantity);
    }
}

// Function to search for a medicine in the inventory
void searchMedicine(medicine *inventory, int num_medicines) {
    // Get the name of the medicine to be searched from the user
    char medicine_name[50];
    printf("Enter the name of the medicine to be searched: ");
    scanf("%s", medicine_name);

    // Search for the medicine in the inventory
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, medicine_name) == 0) {
            // Print the details of the medicine
            printf("Medicine Name: %s\n", inventory[i].name);
            printf("Medicine Price: %.2f\n", inventory[i].price);
            printf("Medicine Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }

    // If the medicine is not found, print an error message
    if (!found) {
        printf("Medicine not found in the inventory.\n");
    }
}

// Function to sell a medicine from the inventory
void sellMedicine(medicine *inventory, int *num_medicines) {
    // Get the name of the medicine to be sold from the user
    char medicine_name[50];
    printf("Enter the name of the medicine to be sold: ");
    scanf("%s", medicine_name);

    // Search for the medicine in the inventory
    int found = 0;
    int index = -1;
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(inventory[i].name, medicine_name) == 0) {
            // Get the quantity of the medicine to be sold from the user
            int quantity;
            printf("Enter the quantity of the medicine to be sold: ");
            scanf("%d", &quantity);

            // Check if the quantity is available in the inventory
            if (inventory[i].quantity >= quantity) {
                // Deduct the quantity from the inventory
                inventory[i].quantity -= quantity;
                found = 1;
                index = i;
                break;
            } else {
                printf("Insufficient quantity in the inventory.\n");
            }
        }
    }

    // If the medicine is not found, print an error message
    if (!found) {
        printf("Medicine not found in the inventory.\n");
    } else {
        // If the medicine is sold, print a success message
        printf("Medicine sold successfully.\n");
        
        // If the quantity of the medicine is 0, remove it from the inventory
        if (inventory[index].quantity == 0) {
            for (int j = index; j < *num_medicines - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*num_medicines)--;
        }
    }
}

// Main function
int main() {
    // Create an array of medicines to store the inventory
    medicine inventory[100];

    // Initialize the number of medicines in the inventory to 0
    int num_medicines = 0;

    // Display the menu of options to the user
    int choice;
    do {
        printf("1. Add a new medicine\n");
        printf("2. Display the inventory of medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Sell a medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                addMedicine(inventory, &num_medicines);
                break;
            case 2:
                displayInventory(inventory, num_medicines);
                break;
            case 3:
                searchMedicine(inventory, num_medicines);
                break;
            case 4:
                sellMedicine(inventory, &num_medicines);
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
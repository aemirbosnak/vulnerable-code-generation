//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines that can be stored
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct medicine {
    char name[50];
    char brand[50];
    float price;
    int quantity;
} medicine;

// Create an array of medicines
medicine medicines[MAX_MEDICINES];

// Initialize the number of medicines to 0
int num_medicines = 0;

// Function to add a new medicine to the store
void add_medicine() {
    // Get the details of the new medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[num_medicines].name);

    printf("Enter the brand of the medicine: ");
    scanf("%s", medicines[num_medicines].brand);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[num_medicines].price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[num_medicines].quantity);

    // Increment the number of medicines
    num_medicines++;
}

// Function to display all the medicines in the store
void display_medicines() {
    // Loop through the array of medicines and print the details of each medicine
    for (int i = 0; i < num_medicines; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Name: %s\n", medicines[i].name);
        printf("Brand: %s\n", medicines[i].brand);
        printf("Price: %f\n", medicines[i].price);
        printf("Quantity: %d\n\n", medicines[i].quantity);
    }
}

// Function to search for a medicine by name
void search_medicine() {
    // Get the name of the medicine to search for
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);

    // Loop through the array of medicines and search for the medicine by name
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // The medicine was found
            found = 1;

            // Print the details of the medicine
            printf("Medicine found:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Brand: %s\n", medicines[i].brand);
            printf("Price: %f\n", medicines[i].price);
            printf("Quantity: %d\n\n", medicines[i].quantity);

            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found!\n\n");
    }
}

// Function to delete a medicine by name
void delete_medicine() {
    // Get the name of the medicine to delete
    char name[50];
    printf("Enter the name of the medicine you want to delete: ");
    scanf("%s", name);

    // Loop through the array of medicines and search for the medicine by name
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // The medicine was found

            // Shift the remaining medicines to the left to fill the gap
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }

            // Decrement the number of medicines
            num_medicines--;

            // Print a success message
            printf("Medicine deleted successfully!\n\n");

            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found!\n\n");
    }
}

// Function to update the quantity of a medicine by name
void update_quantity() {
    // Get the name of the medicine to update
    char name[50];
    printf("Enter the name of the medicine you want to update the quantity of: ");
    scanf("%s", name);

    // Loop through the array of medicines and search for the medicine by name
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // The medicine was found

            // Get the new quantity
            int quantity;
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);

            // Update the quantity
            medicines[i].quantity = quantity;

            // Print a success message
            printf("Quantity updated successfully!\n\n");

            found = 1;
            break;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found!\n\n");
    }
}

// Function to print the menu
void print_menu() {
    printf("-------------------------------------------------\n");
    printf("Medical Store Management System\n");
    printf("-------------------------------------------------\n");
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine by name\n");
    printf("4. Delete a medicine by name\n");
    printf("5. Update the quantity of a medicine by name\n");
    printf("6. Exit\n");
    printf("-------------------------------------------------\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    // Print the menu
    print_menu();

    // Get the user's choice
    int choice;
    scanf("%d", &choice);

    // Loop until the user chooses to exit
    while (choice != 6) {
        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                delete_medicine();
                break;
            case 5:
                update_quantity();
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n\n");
        }

        // Print the menu again
        print_menu();

        // Get the user's choice
        scanf("%d", &choice);
    }

    // Print a goodbye message
    printf("Thank you for using the Medical Store Management System!\n");

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
    int id;
    char name[50];
    char company[50];
    float price;
    int quantity;
} Medicine;

// Array to store medicine details
Medicine medicines[100];

// Function to add a new medicine
void addMedicine() {
    // Get the medicine details from the user
    printf("Enter medicine ID: ");
    scanf("%d", &medicines[0].id);
    printf("Enter medicine name: ");
    scanf("%s", medicines[0].name);
    printf("Enter medicine company: ");
    scanf("%s", medicines[0].company);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[0].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[0].quantity);

    // Increment the number of medicines
    // medicines[0].id++;
}

// Function to display all medicines
void displayMedicines() {
    // Iterate over the array of medicines
    for (int i = 0; i < 1; i++) {
        // Print the medicine details
        printf("Medicine ID: %d\n", medicines[i].id);
        printf("Medicine Name: %s\n", medicines[i].name);
        printf("Medicine Company: %s\n", medicines[i].company);
        printf("Medicine Price: %f\n", medicines[i].price);
        printf("Medicine Quantity: %d\n\n", medicines[i].quantity);
    }
}

// Function to search for a medicine by name
void searchMedicineByName() {
    // Get the medicine name from the user
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);

    // Iterate over the array of medicines
    for (int i = 0; i < 1; i++) {
        // Check if the medicine name matches the user's input
        if (strcmp(medicines[i].name, name) == 0) {
            // Print the medicine details
            printf("Medicine ID: %d\n", medicines[i].id);
            printf("Medicine Name: %s\n", medicines[i].name);
            printf("Medicine Company: %s\n", medicines[i].company);
            printf("Medicine Price: %f\n", medicines[i].price);
            printf("Medicine Quantity: %d\n\n", medicines[i].quantity);
            return;
        }
    }

    // If the medicine is not found, print an error message
    printf("Medicine not found.\n");
}

// Function to search for a medicine by ID
void searchMedicineByID() {
    // Get the medicine ID from the user
    int id;
    printf("Enter medicine ID: ");
    scanf("%d", &id);

    // Iterate over the array of medicines
    for (int i = 0; i < 1; i++) {
        // Check if the medicine ID matches the user's input
        if (medicines[i].id == id) {
            // Print the medicine details
            printf("Medicine ID: %d\n", medicines[i].id);
            printf("Medicine Name: %s\n", medicines[i].name);
            printf("Medicine Company: %s\n", medicines[i].company);
            printf("Medicine Price: %f\n", medicines[i].price);
            printf("Medicine Quantity: %d\n\n", medicines[i].quantity);
            return;
        }
    }

    // If the medicine is not found, print an error message
    printf("Medicine not found.\n");
}

// Function to update a medicine
void updateMedicine() {
    // Get the medicine ID from the user
    int id;
    printf("Enter medicine ID: ");
    scanf("%d", &id);

    // Iterate over the array of medicines
    for (int i = 0; i < 1; i++) {
        // Check if the medicine ID matches the user's input
        if (medicines[i].id == id) {
            // Get the new medicine details from the user
            printf("Enter new medicine name: ");
            scanf("%s", medicines[i].name);
            printf("Enter new medicine company: ");
            scanf("%s", medicines[i].company);
            printf("Enter new medicine price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new medicine quantity: ");
            scanf("%d", &medicines[i].quantity);
            return;
        }
    }

    // If the medicine is not found, print an error message
    printf("Medicine not found.\n");
}

// Function to delete a medicine
void deleteMedicine() {
    // Get the medicine ID from the user
    int id;
    printf("Enter medicine ID: ");
    scanf("%d", &id);

    // Iterate over the array of medicines
    for (int i = 0; i < 1; i++) {
        // Check if the medicine ID matches the user's input
        if (medicines[i].id == id) {
            // Shift the remaining medicines to the left
            for (int j = i; j < 1 - 1; j++) {
                medicines[j] = medicines[j + 1];
            }

            // Decrease the number of medicines
            // medicines[0].id--;
            return;
        }
    }

    // If the medicine is not found, print an error message
    printf("Medicine not found.\n");
}

// Function to get the total value of all medicines
float getTotalValue() {
    // Initialize the total value to 0
    float totalValue = 0;

    // Iterate over the array of medicines
    for (int i = 0; i < 1; i++) {
        // Add the value of each medicine to the total value
        totalValue += medicines[i].price * medicines[i].quantity;
    }

    // Return the total value
    return totalValue;
}

// Main function
int main() {
    // Display the menu
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine by name\n");
    printf("4. Search for a medicine by ID\n");
    printf("5. Update a medicine\n");
    printf("6. Delete a medicine\n");
    printf("7. Get the total value of all medicines\n");
    printf("0. Exit\n");

    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Execute the user's choice
    while (choice != 0) {
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicineByName();
                break;
            case 4:
                searchMedicineByID();
                break;
            case 5:
                updateMedicine();
                break;
            case 6:
                deleteMedicine();
                break;
            case 7:
                printf("Total value of all medicines: %f\n", getTotalValue());
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 7.\n");
        }

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}
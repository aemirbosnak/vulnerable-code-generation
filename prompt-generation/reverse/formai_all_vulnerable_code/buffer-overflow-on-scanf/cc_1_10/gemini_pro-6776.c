//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

// Function to add a new medicine to the store
void addMedicine(Medicine *medicines, int *numMedicines) {
    // Get the details of the new medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[*numMedicines].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[*numMedicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[*numMedicines].price);

    // Increment the number of medicines in the store
    (*numMedicines)++;
}

// Function to search for a medicine in the store
void searchMedicine(Medicine *medicines, int numMedicines) {
    // Get the name of the medicine to search for
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);

    // Search for the medicine in the store
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Medicine found
            found = 1;

            // Display the details of the medicine
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %f\n", medicines[i].price);

            break;
        }
    }

    // If the medicine was not found, display an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to update the quantity of a medicine in the store
void updateMedicine(Medicine *medicines, int numMedicines) {
    // Get the name of the medicine to update
    char name[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    // Search for the medicine in the store
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Medicine found
            found = 1;

            // Get the new quantity of the medicine
            int newQuantity;
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &newQuantity);

            // Update the quantity of the medicine
            medicines[i].quantity = newQuantity;

            break;
        }
    }

    // If the medicine was not found, display an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to delete a medicine from the store
void deleteMedicine(Medicine *medicines, int *numMedicines) {
    // Get the name of the medicine to delete
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    // Search for the medicine in the store
    int found = 0;
    int index = -1;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            // Medicine found
            found = 1;
            index = i;
            break;
        }
    }

    // If the medicine was not found, display an error message
    if (!found) {
        printf("Medicine not found.\n");
        return;
    }

    // Delete the medicine from the store
    for (int i = index; i < *numMedicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    // Decrement the number of medicines in the store
    (*numMedicines)--;
}

// Function to display the details of all the medicines in the store
void displayMedicines(Medicine *medicines, int numMedicines) {
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t%d\t%f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Main function
int main() {
    // Create an array of medicines
    Medicine medicines[100];

    // Initialize the number of medicines in the store to 0
    int numMedicines = 0;

    // Main loop
    int choice;
    do {
        // Display the menu
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Update the quantity of a medicine\n");
        printf("4. Delete a medicine\n");
        printf("5. Display the details of all the medicines\n");
        printf("6. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                searchMedicine(medicines, numMedicines);
                break;
            case 3:
                updateMedicine(medicines, numMedicines);
                break;
            case 4:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 5:
                displayMedicines(medicines, numMedicines);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
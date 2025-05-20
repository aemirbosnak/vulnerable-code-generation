//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the store
void addMedicine(medicine *store, int *numMedicines) {
    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*numMedicines].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*numMedicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*numMedicines].quantity);

    // Increment the number of medicines in the store
    (*numMedicines)++;
}

// Function to display the details of all the medicines in the store
void displayMedicines(medicine *store, int numMedicines) {
    // Print the header
    printf("Name\t\tPrice\t\tQuantity\n");

    // Print the details of each medicine
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t\t%.2f\t\t%d\n", store[i].name, store[i].price, store[i].quantity);
    }
}

// Function to search for a medicine by name
medicine *searchMedicine(medicine *store, int numMedicines, char *name) {
    // Iterate over the medicines in the store
    for (int i = 0; i < numMedicines; i++) {
        // Check if the medicine name matches the search term
        if (strcmp(store[i].name, name) == 0) {
            // Return the medicine
            return &store[i];
        }
    }

    // Return NULL if the medicine is not found
    return NULL;
}

// Function to update the quantity of a medicine
void updateQuantity(medicine *store, int numMedicines, char *name, int quantity) {
    // Search for the medicine by name
    medicine *medicine = searchMedicine(store, numMedicines, name);

    // Check if the medicine was found
    if (medicine != NULL) {
        // Update the quantity
        medicine->quantity = quantity;
    } else {
        // Print an error message
        printf("Medicine not found!\n");
    }
}

// Function to delete a medicine from the store
void deleteMedicine(medicine *store, int *numMedicines, char *name) {
    // Search for the medicine by name
    medicine *medicine = searchMedicine(store, *numMedicines, name);

    // Check if the medicine was found
    if (medicine != NULL) {
        // Shift the medicines after the deleted medicine to the left
        for (int i = medicine - store; i < *numMedicines - 1; i++) {
            store[i] = store[i + 1];
        }

        // Decrement the number of medicines in the store
        (*numMedicines)--;
    } else {
        // Print an error message
        printf("Medicine not found!\n");
    }
}

// Main function
int main() {
    // Initialize the medicine store
    medicine store[100];
    int numMedicines = 0;

    // Add some medicines to the store
    addMedicine(store, &numMedicines);
    addMedicine(store, &numMedicines);
    addMedicine(store, &numMedicines);

    // Display the medicines in the store
    displayMedicines(store, numMedicines);

    // Search for a medicine by name
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);
    medicine *medicine = searchMedicine(store, numMedicines, name);

    // Check if the medicine was found
    if (medicine != NULL) {
        // Print the details of the medicine
        printf("Name: %s\n", medicine->name);
        printf("Price: %.2f\n", medicine->price);
        printf("Quantity: %d\n", medicine->quantity);
    } else {
        // Print an error message
        printf("Medicine not found!\n");
    }

    // Update the quantity of a medicine
    int quantity;
    printf("Enter the name of the medicine to update the quantity for: ");
    scanf("%s", name);
    printf("Enter the new quantity: ");
    scanf("%d", &quantity);
    updateQuantity(store, numMedicines, name, quantity);

    // Display the medicines in the store
    displayMedicines(store, numMedicines);

    // Delete a medicine from the store
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);
    deleteMedicine(store, &numMedicines, name);

    // Display the medicines in the store
    displayMedicines(store, numMedicines);

    return 0;
}
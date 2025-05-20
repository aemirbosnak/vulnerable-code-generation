//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the store
void addMedicine(medicine *store, int *numMedicines) {
    // Get the details of the new medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*numMedicines].name);
    printf("Enter the company of the medicine: ");
    scanf("%s", store[*numMedicines].company);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*numMedicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*numMedicines].quantity);

    // Increment the number of medicines in the store
    (*numMedicines)++;
}

// Function to search for a medicine in the store
int searchMedicine(medicine *store, int numMedicines, char *name) {
    // Iterate over the medicines in the store
    for (int i = 0; i < numMedicines; i++) {
        // If the name of the medicine matches the search term, return its index
        if (strcmp(store[i].name, name) == 0) {
            return i;
        }
    }

    // If the medicine was not found, return -1
    return -1;
}

// Function to display the details of a medicine
void displayMedicine(medicine medicine) {
    // Print the details of the medicine
    printf("Name: %s\n", medicine.name);
    printf("Company: %s\n", medicine.company);
    printf("Price: %f\n", medicine.price);
    printf("Quantity: %d\n", medicine.quantity);
}

// Main function
int main() {
    // Create an array of medicines to store the medicines in the store
    medicine store[100];

    // Initialize the number of medicines in the store to 0
    int numMedicines = 0;

    // Add some sample medicines to the store
    addMedicine(store, &numMedicines);
    addMedicine(store, &numMedicines);
    addMedicine(store, &numMedicines);

    // Search for a medicine in the store
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);
    int index = searchMedicine(store, numMedicines, name);

    // If the medicine was found, display its details
    if (index != -1) {
        displayMedicine(store[index]);
    } else {
        printf("Medicine not found.\n");
    }

    return 0;
}
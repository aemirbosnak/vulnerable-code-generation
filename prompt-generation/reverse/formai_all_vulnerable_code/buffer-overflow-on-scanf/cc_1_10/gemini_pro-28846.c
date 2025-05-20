//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the store
void addMedicine(medicine *store, int *numMedicines) {
    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*numMedicines].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*numMedicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*numMedicines].price);

    // Increment the number of medicines in the store
    (*numMedicines)++;
}

// Function to sell a medicine from the store
void sellMedicine(medicine *store, int *numMedicines) {
    // Get the name of the medicine to be sold
    char name[50];
    printf("Enter the name of the medicine to be sold: ");
    scanf("%s", name);

    // Find the medicine in the store
    int index = -1;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(store[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the medicine is not found, print an error message
    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    // Get the quantity of the medicine to be sold
    int quantity;
    printf("Enter the quantity of the medicine to be sold: ");
    scanf("%d", &quantity);

    // If the quantity is greater than the available quantity, print an error message
    if (quantity > store[index].quantity) {
        printf("Insufficient quantity.\n");
        return;
    }

    // Update the quantity of the medicine in the store
    store[index].quantity -= quantity;

    // If the quantity of the medicine becomes zero, remove it from the store
    if (store[index].quantity == 0) {
        for (int i = index; i < *numMedicines - 1; i++) {
            store[i] = store[i + 1];
        }
        (*numMedicines)--;
    }
}

// Function to print the details of all the medicines in the store
void printMedicines(medicine *store, int numMedicines) {
    printf("\n\nMedicine Details:\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Name", "Quantity", "Price");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("| %-20s | %-10d | %-10.2f |\n", store[i].name, store[i].quantity, store[i].price);
    }
    printf("----------------------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Create an array of medicines
    medicine store[100];

    // Initialize the number of medicines in the store to zero
    int numMedicines = 0;

    // Add some initial medicines to the store
    addMedicine(store, &numMedicines);
    addMedicine(store, &numMedicines);
    addMedicine(store, &numMedicines);

    // Print the details of all the medicines in the store
    printMedicines(store, numMedicines);

    // Sell some medicines from the store
    sellMedicine(store, &numMedicines);
    sellMedicine(store, &numMedicines);

    // Print the details of all the medicines in the store
    printMedicines(store, numMedicines);

    return 0;
}
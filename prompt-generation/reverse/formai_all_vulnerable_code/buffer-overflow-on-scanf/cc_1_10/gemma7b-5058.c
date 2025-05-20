//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medicine information
typedef struct Medicine {
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

// Define a function to add a new medicine to the store
void addMedicine(Medicine *medicines, int *numMedics) {
    // Allocate memory for a new medicine
    medicines = (Medicine *)realloc(medicines, (*numMedics + 1) * sizeof(Medicine));

    // Get the medicine name, dosage, quantity, and price
    printf("Enter the medicine name: ");
    scanf("%s", medicines[*numMedics].name);

    printf("Enter the dosage: ");
    scanf("%s", medicines[*numMedics].dosage);

    printf("Enter the quantity: ");
    scanf("%d", &medicines[*numMedics].quantity);

    printf("Enter the price: ");
    scanf("%f", &medicines[*numMedics].price);

    // Increment the number of medicines
    (*numMedics)++;
}

// Define a function to search for a medicine
void searchMedicine(Medicine *medicines, int numMedics) {
    // Get the medicine name
    char searchName[50];
    printf("Enter the medicine name: ");
    scanf("%s", searchName);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedics; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            // Print the medicine information
            printf("Name: %s\n", medicines[i].name);
            printf("Dosage: %s\n", medicines[i].dosage);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Define a function to update the quantity of a medicine
void updateQuantity(Medicine *medicines, int numMedics) {
    // Get the medicine name
    char updateName[50];
    printf("Enter the medicine name: ");
    scanf("%s", updateName);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedics; i++) {
        if (strcmp(medicines[i].name, updateName) == 0) {
            // Get the new quantity
            int newQuantity;
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);

            // Update the medicine quantity
            medicines[i].quantity = newQuantity;

            // Print the updated medicine information
            printf("Name: %s\n", medicines[i].name);
            printf("Dosage: %s\n", medicines[i].dosage);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Define a function to delete a medicine
void deleteMedicine(Medicine *medicines, int *numMedics) {
    // Get the medicine name
    char deleteName[50];
    printf("Enter the medicine name: ");
    scanf("%s", deleteName);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < *numMedics; i++) {
        if (strcmp(medicines[i].name, deleteName) == 0) {
            // Delete the medicine
            medicines[i] = medicines[*numMedics - 1];
            (*numMedics)--;

            // Print the updated medicine list
            for (int j = 0; j < *numMedics; j++) {
                printf("Name: %s\n", medicines[j].name);
                printf("Dosage: %s\n", medicines[j].dosage);
                printf("Quantity: %d\n", medicines[j].quantity);
                printf("Price: %.2f\n", medicines[j].price);
            }

            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found) {
        printf("Medicine not found.\n");
    }
}

int main() {
    // Create an array of medicines
    Medicine *medicines = NULL;
    int numMedics = 0;

    // Add some medicines to the store
    addMedicine(medicines, &numMedics);
    addMedicine(medicines, &numMedics);
    addMedicine(medicines, &numMedics);

    // Search for a medicine
    searchMedicine(medicines, numMedics);

    // Update the quantity of a medicine
    updateQuantity(medicines, numMedics);

    // Delete a medicine
    deleteMedicine(medicines, &numMedics);

    return 0;
}
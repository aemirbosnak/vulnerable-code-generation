//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

// Define the function to add a medicine to the store
void addMedicine(Medicine *medicines, int *numMedics) {
    // Allocate memory for a new medicine
    medicines = (Medicine *)realloc(medicines, (*numMedics + 1) * sizeof(Medicine));

    // Get the medicine name, dosage, quantity, and price
    printf("Enter the medicine name: ");
    scanf("%s", medicines[*numMedics].name);

    printf("Enter the medicine dosage: ");
    scanf("%s", medicines[*numMedics].dosage);

    printf("Enter the medicine quantity: ");
    scanf("%d", &medicines[*numMedics].quantity);

    printf("Enter the medicine price: ");
    scanf("%f", &medicines[*numMedics].price);

    // Increment the number of medicines
    (*numMedics)++;
}

// Define the function to search for a medicine
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

// Define the function to update the medicine quantity
void updateMedicineQuantity(Medicine *medicines, int numMedics) {
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

// Define the function to delete a medicine
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
    // Define an array of medicines
    Medicine *medicines = NULL;

    // Define the number of medicines
    int numMedics = 0;

    // Loop until the user chooses to exit
    int choice;
    printf("Enter 1 to add a medicine, 2 to search for a medicine, 3 to update the medicine quantity, or 4 to delete a medicine: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMedicine(medicines, &numMedics);
            break;
        case 2:
            searchMedicine(medicines, numMedics);
            break;
        case 3:
            updateMedicineQuantity(medicines, numMedics);
            break;
        case 4:
            deleteMedicine(medicines, &numMedics);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
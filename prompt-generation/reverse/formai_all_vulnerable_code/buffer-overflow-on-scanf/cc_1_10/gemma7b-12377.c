//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medicine information
struct Medicine {
    char name[20];
    int quantity;
    float price;
};

// Create a function to add a medicine to the store
void addMedicine(struct Medicine *medicine) {
    printf("Enter the name of the medicine: ");
    scanf("%s", medicine->name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine->quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine->price);
}

// Create a function to display all medicines in the store
void displayMedicines(struct Medicine *medicine) {
    printf("List of medicines:\n");
    for (int i = 0; i < medicine->quantity; i++) {
        printf("%s - %d - %.2f\n", medicine->name, medicine->quantity, medicine->price);
    }
}

// Create a function to search for a medicine in the store
struct Medicine *searchMedicine(struct Medicine *medicine, char *name) {
    for (int i = 0; i < medicine->quantity; i++) {
        if (strcmp(medicine->name, name) == 0) {
            return medicine;
        }
    }

    return NULL;
}

int main() {
    // Create an array of medicines
    struct Medicine medicine[100];

    // Add some medicines to the store
    addMedicine(medicine);
    addMedicine(medicine);
    addMedicine(medicine);

    // Display all medicines in the store
    displayMedicines(medicine);

    // Search for a medicine in the store
    struct Medicine *foundMedicine = searchMedicine(medicine, "Medicine 2");

    // If the medicine was found, display its information
    if (foundMedicine) {
        printf("Found medicine: %s - %d - %.2f\n", foundMedicine->name, foundMedicine->quantity, foundMedicine->price);
    } else {
        printf("Medicine not found.\n");
    }

    return 0;
}
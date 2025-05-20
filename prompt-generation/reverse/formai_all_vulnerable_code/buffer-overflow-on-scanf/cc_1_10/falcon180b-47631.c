//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a medicine
typedef struct {
    char name[50];
    char description[100];
    float price;
    int quantity;
} Medicine;

// Function to add a medicine to the store
void addMedicine(Medicine medicines[], int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", &(medicines[*size].name));

    printf("Enter the description of the medicine: ");
    scanf("%s", &(medicines[*size].description));

    printf("Enter the price of the medicine: ");
    scanf("%f", &(medicines[*size].price));

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &(medicines[*size].quantity));

    (*size)++;
}

// Function to display all medicines in the store
void displayMedicines(Medicine medicines[], int size) {
    printf("Name\tDescription\tPrice\tQuantity\n");

    for (int i = 0; i < size; i++) {
        printf("%s\t%s\t%.2f\t%d\n", medicines[i].name, medicines[i].description, medicines[i].price, medicines[i].quantity);
    }
}

// Function to search for a medicine by name
int searchMedicine(Medicine medicines[], int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to update the quantity of a medicine
void updateQuantity(Medicine medicines[], int size, int index, int newQuantity) {
    if (index >= 0 && index < size) {
        medicines[index].quantity = newQuantity;
    } else {
        printf("Invalid medicine index.\n");
    }
}

// Function to remove a medicine from the store
void removeMedicine(Medicine medicines[], int *size, char *name) {
    int index = searchMedicine(medicines, *size, name);

    if (index >= 0) {
        for (int i = index; i < (*size) - 1; i++) {
            medicines[i] = medicines[i + 1];
        }

        (*size)--;
    } else {
        printf("Medicine not found.\n");
    }
}

int main() {
    int size = 0;
    Medicine medicines[100];

    // Initialize the store with some medicines
    addMedicine(medicines, &size);
    addMedicine(medicines, &size);
    addMedicine(medicines, &size);

    // Display all medicines in the store
    displayMedicines(medicines, size);

    // Search for a medicine by name
    char name[50] = "Paracetamol";
    int index = searchMedicine(medicines, size, name);

    if (index >= 0) {
        printf("Found medicine: %s\n", medicines[index].name);
    } else {
        printf("Medicine not found.\n");
    }

    // Update the quantity of a medicine
    int quantity = 10;
    updateQuantity(medicines, size, index, quantity);

    // Display all medicines in the store
    displayMedicines(medicines, size);

    // Remove a medicine from the store
    removeMedicine(medicines, &size, name);

    // Display all medicines in the store
    displayMedicines(medicines, size);

    return 0;
}
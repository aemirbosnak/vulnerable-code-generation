//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

// Function to add a new medicine to the store
void addMedicine(Medicine *medicines, int *numMedicines) {
    // Get medicine details from the user
    printf("Enter medicine ID: ");
    scanf("%d", &medicines[*numMedicines].id);
    printf("Enter medicine name: ");
    scanf("%s", medicines[*numMedicines].name);
    printf("Enter manufacturer name: ");
    scanf("%s", medicines[*numMedicines].manufacturer);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[*numMedicines].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*numMedicines].quantity);

    // Increment the number of medicines in the store
    (*numMedicines)++;
}

// Function to search for a medicine by ID
Medicine *searchMedicineById(Medicine *medicines, int numMedicines, int id) {
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].id == id) {
            return &medicines[i];
        }
    }

    return NULL;
}

// Function to sell a medicine
void sellMedicine(Medicine *medicines, int *numMedicines, int id, int quantity) {
    // Search for the medicine by ID
    Medicine *medicine = searchMedicineById(medicines, *numMedicines, id);

    // If the medicine is not found, display an error message
    if (medicine == NULL) {
        printf("Medicine not found!\n");
        return;
    }

    // If the quantity is greater than the available quantity, display an error message
    if (quantity > medicine->quantity) {
        printf("Insufficient quantity!\n");
        return;
    }

    // Sell the medicine
    medicine->quantity -= quantity;
}

// Function to display all medicines in the store
void displayAllMedicines(Medicine *medicines, int numMedicines) {
    printf("ID\tName\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
}

// Main function
int main() {
    // Create an array of medicines
    Medicine medicines[100];

    // Initialize the number of medicines in the store to 0
    int numMedicines = 0;

    // Add some sample medicines to the store
    addMedicine(medicines, &numMedicines);
    addMedicine(medicines, &numMedicines);
    addMedicine(medicines, &numMedicines);

    // Display all medicines in the store
    displayAllMedicines(medicines, numMedicines);

    // Search for a medicine by ID
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    Medicine *medicine = searchMedicineById(medicines, numMedicines, id);

    // If the medicine is found, display its details
    if (medicine != NULL) {
        printf("Medicine found:\n");
        printf("ID: %d\n", medicine->id);
        printf("Name: %s\n", medicine->name);
        printf("Manufacturer: %s\n", medicine->manufacturer);
        printf("Price: %.2f\n", medicine->price);
        printf("Quantity: %d\n", medicine->quantity);
    } else {
        printf("Medicine not found!\n");
    }

    // Sell a medicine
    int quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    sellMedicine(medicines, &numMedicines, id, quantity);

    // Display all medicines in the store after selling
    displayAllMedicines(medicines, numMedicines);

    return 0;
}
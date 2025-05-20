//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    int id;
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the store
void addMedicine(medicine *store, int *numMedicines) {
    // Get the medicine details from the user
    printf("Enter medicine ID: ");
    scanf("%d", &store[*numMedicines].id);
    printf("Enter medicine name: ");
    scanf("%s", store[*numMedicines].name);
    printf("Enter medicine price: ");
    scanf("%f", &store[*numMedicines].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &store[*numMedicines].quantity);

    // Increment the number of medicines in the store
    (*numMedicines)++;
}

// Function to sell a medicine from the store
void sellMedicine(medicine *store, int *numMedicines) {
    // Get the medicine ID from the user
    int id;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);

    // Find the medicine in the store
    int index = -1;
    for (int i = 0; i < *numMedicines; i++) {
        if (store[i].id == id) {
            index = i;
            break;
        }
    }

    // If the medicine was found, decrement the quantity and print the bill
    if (index != -1) {
        int quantity;
        printf("Enter quantity to sell: ");
        scanf("%d", &quantity);
        if (quantity <= store[index].quantity) {
            store[index].quantity -= quantity;
            float bill = quantity * store[index].price;
            printf("Bill: %.2f\n", bill);
        } else {
            printf("Insufficient quantity in stock.\n");
        }
    } else {
        printf("Medicine not found.\n");
    }
}

// Function to print the inventory of the store
void printInventory(medicine *store, int numMedicines) {
    printf("Medicine Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", store[i].id, store[i].name, store[i].price, store[i].quantity);
    }
}

// Main function
int main() {
    // Create an array of medicines
    medicine store[100];

    // Initialize the number of medicines to 0
    int numMedicines = 0;

    // Get the user's choice
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add a new medicine\n");
        printf("2. Sell a medicine\n");
        printf("3. Print inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                addMedicine(store, &numMedicines);
                break;
            case 2:
                sellMedicine(store, &numMedicines);
                break;
            case 3:
                printInventory(store, numMedicines);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
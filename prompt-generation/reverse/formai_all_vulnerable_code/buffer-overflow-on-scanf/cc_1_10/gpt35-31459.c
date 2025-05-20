//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding medicine data
typedef struct Medicine {
    char name[50]; // Name of medicine
    float price;   // Price of medicine
    int quantity;  // Quantity of medicine in stock
} Medicine;

// Function to display inventory
void displayInventory(Medicine *medicines, int numMedicines) {
    printf("\nCurrent Inventory:\n");
    printf("Name\t\tPrice\tQuantity\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%-15s $%.2f\t%d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Function to add a new medicine to inventory
void addMedicine(Medicine *medicines, int *numMedicines) {
    char name[50];
    float price;
    int quantity;

    printf("Enter name of medicine: ");
    scanf("%s", name);
    printf("Enter price of medicine: ");
    scanf("%f", &price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &quantity);

    // Create new medicine struct and add to array
    Medicine newMedicine = { strcpy(newMedicine.name, name), price, quantity };
    medicines[*numMedicines] = newMedicine;

    // Increment number of medicines
    (*numMedicines)++;

    printf("\nAdded new medicine to inventory!\n");
}

// Main function
int main() {
    printf("Welcome to the C Medical Store Management System!\n\n");

    // Create array to hold medicines
    Medicine medicines[10] = {
        { "Aspirin", 4.99, 50 },
        { "Ibuprofen", 7.99, 30 },
        { "Acetaminophen", 5.99, 25 },
        { "Antacid", 3.99, 40 },
        { "Cough Syrup", 9.99, 20 }
    };

    // Keep track of number of medicines
    int numMedicines = 5;

    // Display main menu
    char choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Display Inventory\n");
        printf("2. Add New Medicine\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': // Display inventory
                displayInventory(medicines, numMedicines);
                break;
            case '2': // Add new medicine
                addMedicine(medicines, &numMedicines);
                break;
            case '3': // Quit
                printf("\nThank you for using the C Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}
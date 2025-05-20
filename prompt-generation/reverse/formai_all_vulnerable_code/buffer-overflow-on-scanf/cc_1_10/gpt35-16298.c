//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Global variables
int numMedicines = 0;

// Structure definition for medicines
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to display main menu and get user choice
int getMenuChoice() {
    int choice;
    printf("\n\n\tMEDICAL STORE MANAGEMENT SYSTEM\n");
    printf("\t1. Add New Medicine\n");
    printf("\t2. View Medicine Details\n");
    printf("\t3. Update Medicine Details\n");
    printf("\t4. Delete Medicine\n");
    printf("\t5. Exit\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new medicine
void addMedicine(struct Medicine *medicines) {
    printf("\n\n\tADDING NEW MEDICINE\n");
    printf("\tEnter medicine name: ");
    scanf("%s", &medicines[numMedicines].name);
    printf("\tEnter medicine price: ");
    scanf("%f", &medicines[numMedicines].price);
    printf("\tEnter quantity available: ");
    scanf("%d", &medicines[numMedicines].quantity);
    // Set id to current index
    medicines[numMedicines].id = numMedicines;
    numMedicines++;
    printf("\n\tMedicine added successfully!\n");
}

// Function to view medicine details
void viewMedicine(struct Medicine *medicines) {
    int id;
    printf("\n\n\tVIEW MEDICINE DETAILS\n");
    printf("\tEnter medicine id: ");
    scanf("%d", &id);
    // Check if medicine exists
    if (id >= 0 && id < numMedicines) {
        printf("\n\tMedicine ID: %d\n", medicines[id].id);
        printf("\tMedicine Name: %s\n", medicines[id].name);
        printf("\tPrice: %.2f\n", medicines[id].price);
        printf("\tQuantity Available: %d\n", medicines[id].quantity);
    } else {
        printf("\n\tError: Medicine not found!\n");
    }
}

// Function to update medicine details
void updateMedicine(struct Medicine *medicines) {
    int id;
    printf("\n\n\tUPDATE MEDICINE DETAILS\n");
    printf("\tEnter medicine id: ");
    scanf("%d", &id);
    // Check if medicine exists
    if (id >= 0 && id < numMedicines) {
        printf("\tMedicine Name (%s): ", medicines[id].name);
        scanf("%s", &medicines[id].name);
        printf("\tPrice (%.2f): ", medicines[id].price);
        scanf("%f", &medicines[id].price);
        printf("\tQuantity Available (%d): ", medicines[id].quantity);
        scanf("%d", &medicines[id].quantity);
        printf("\n\tMedicine details updated successfully!\n");
    } else {
        printf("\n\tError: Medicine not found!\n");
    }
}

// Function to delete a medicine
void deleteMedicine(struct Medicine *medicines) {
    int id, i;
    printf("\n\n\tDELETE MEDICINE\n");
    printf("\tEnter medicine id: ");
    scanf("%d", &id);
    // Check if medicine exists
    if (id >= 0 && id < numMedicines) {
        // Shift remaining medicines to fill deleted medicine
        for (i = id; i < numMedicines - 1; i++) {
            medicines[i] = medicines[i+1];
        }
        numMedicines--;
        printf("\n\tMedicine deleted successfully!\n");
    } else {
        printf("\n\tError: Medicine not found!\n");
    }
}

// Main function
int main() {
    struct Medicine medicines[50];
    int choice;
    // Display menu and get user choice
    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                addMedicine(medicines);
                break;
            case 2:
                viewMedicine(medicines);
                break;
            case 3:
                updateMedicine(medicines);
                break;
            case 4:
                deleteMedicine(medicines);
                break;
            case 5:
                printf("\n\tExiting...\n");
                break;
            default:
                printf("\n\tInvalid choice! Try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
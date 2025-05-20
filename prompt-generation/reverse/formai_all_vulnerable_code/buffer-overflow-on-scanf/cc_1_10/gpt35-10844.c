//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of medicines that can be stored
#define MAX_MEDICINES 100

// Define maximum length of medicine name
#define MAX_NAME_LENGTH 50

// Define structure for Medicine details
struct Medicine {
    char name[MAX_NAME_LENGTH];
    float price_per_unit;
    int quantity;
};

// Declare function prototypes
void addMedicine(struct Medicine[], int*);
void removeMedicine(struct Medicine[], int*);
void displayMedicineList(struct Medicine[], int);
void searchMedicine(struct Medicine[], int);

int main() {
    // Initialize array of Medicines
    struct Medicine medicines[MAX_MEDICINES];
    
    // Initialize number of Medicines
    int numMedicines = 0;
    
    // Initialize user choice variable
    int choice = 0;
    
    // Display welcome message
    printf("Welcome to the Medical Store Management System\n");
    
    do {
        // Display menu options
        printf("\nPlease choose from the following options:\n"
               "1. Add Medicine to Store\n"
               "2. Remove Medicine from Store\n"
               "3. Display List of Medicines in Store\n"
               "4. Search for a Medicine\n"
               "5. Exit\n");
        
        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Add Medicine to Store
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                // Remove Medicine from Store
                removeMedicine(medicines, &numMedicines);
                break;
            case 3:
                // Display List of Medicines in Store
                displayMedicineList(medicines, numMedicines);
                break;
            case 4:
                // Search for a Medicine
                searchMedicine(medicines, numMedicines);
                break;
            case 5:
                // Exit program
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a valid choice (1-5).\n");
        }
    
    } while(choice != 5);
    
    return 0;
}

void addMedicine(struct Medicine medicines[], int* numMedicines) {
    // Check if maximum number of Medicines already stored
    if(*numMedicines == MAX_MEDICINES) {
        printf("The store is full and cannot store any more Medicines.\n");
        return;
    }
    
    // Temporary variable to store new Medicine details
    struct Medicine newMedicine;
    
    // Get new Medicine details from user
    printf("\nEnter details of new Medicine:\n");
    printf("Name (up to %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", newMedicine.name);
    printf("Price per unit: ");
    scanf("%f", &newMedicine.price_per_unit);
    printf("Quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    // Add new Medicine to array
    medicines[*numMedicines] = newMedicine;
    
    // Increase number of Medicines stored
    (*numMedicines)++;
    
    printf("\nThe Medicine has been added successfully!\n");
}

void removeMedicine(struct Medicine medicines[], int* numMedicines) {
    // Check if any Medicines are stored
    if(*numMedicines == 0) {
        printf("There are no Medicines in the store to remove!\n");
        return;
    }
    
    // Temporary variable to store name of Medicine to remove
    char nameToRemove[MAX_NAME_LENGTH];
    
    // Get name of Medicine to remove from user
    printf("\nEnter name of Medicine to remove: ");
    scanf("%s", nameToRemove);
    
    // Find index of Medicine to remove
    int removeIndex = -1;
    for(int i = 0; i < *numMedicines; i++) {
        if(strcmp(medicines[i].name, nameToRemove) == 0) {
            removeIndex = i;
            break;
        }
    }
    
    // Check if Medicine was found
    if(removeIndex == -1) {
        printf("Medicine not found in store!\n");
        return;
    }
    
    // Remove Medicine from array
    for(int i = removeIndex; i < (*numMedicines) - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    (*numMedicines)--;
    
    printf("\nThe Medicine has been removed successfully!\n");
}

void displayMedicineList(struct Medicine medicines[], int numMedicines) {
    // Check if any Medicines are stored
    if(numMedicines == 0) {
        printf("There are no Medicines in the store to display!\n");
        return;
    }
    
    // Display list of Medicines
    printf("\nList of Medicines in the store:\n");
    printf("%-20s%-20s%-20s\n", "Name", "Price per Unit", "Quantity");
    for(int i = 0; i < numMedicines; i++) {
        printf("%-20s%-20.2f%-20d\n", medicines[i].name, medicines[i].price_per_unit, medicines[i].quantity);
    }
}

void searchMedicine(struct Medicine medicines[], int numMedicines) {
    // Check if any Medicines are stored
    if(numMedicines == 0) {
        printf("There are no Medicines in the store to search!\n");
        return;
    }
    
    // Temporary variable to store name of Medicine to search
    char nameToSearch[MAX_NAME_LENGTH];
    
    // Get name of Medicine to search from user
    printf("\nEnter name of Medicine to search: ");
    scanf("%s", nameToSearch);
    
    // Find Medicine in array
    int searchIndex = -1;
    for(int i = 0; i < numMedicines; i++) {
        if(strcmp(medicines[i].name, nameToSearch) == 0) {
            searchIndex = i;
            break;
        }
    }
    
    // Check if Medicine was found
    if(searchIndex == -1) {
        printf("Medicine not found in store!\n");
        return;
    }
    
    // Display Medicine details
    printf("\nDetails of Medicine %s:\n", medicines[searchIndex].name);
    printf("Price per Unit: %.2f\n", medicines[searchIndex].price_per_unit);
    printf("Quantity: %d\n", medicines[searchIndex].quantity);
}
//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum values
#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 999

// Define a struct for storing medicine information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

// Declare an array of Medicine structs to hold all medicines
Medicine medicines[MAX_MEDICINES];

// Declare a variable to keep track of the number of medicines in stock
int numMedicines = 0;

// Function to add a new medicine to the inventory
void addMedicine() {
    // Check if there is still space in the inventory
    if (numMedicines == MAX_MEDICINES) {
        printf("Error: Maximum number of medicines reached.\n");
        return;
    }
    
    // Ask user for the name of the medicine to add
    char name[MAX_NAME_LENGTH];
    printf("Enter name of medicine to add: ");
    scanf("%s", name);
    
    // Check if a medicine with the same name already exists
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Error: Medicine with name already exists.\n");
            return;
        }
    }
    
    // Ask user for quantity and price of the medicine to add
    int quantity;
    float price;
    printf("Enter quantity of medicine to add: ");
    scanf("%d", &quantity);
    
    if (quantity > MAX_QUANTITY) {
        printf("Error: Maximum quantity exceeded.\n");
        return;
    }
    
    printf("Enter price of medicine to add: ");
    scanf("%f", &price);
    
    // Add the new medicine to the inventory
    strcpy(medicines[numMedicines].name, name);
    medicines[numMedicines].quantity = quantity;
    medicines[numMedicines].price = price;
    numMedicines++;
    
    printf("Medicine added successfully.\n");
}

// Function to remove a medicine from the inventory
void removeMedicine() {
    // Ask user for the name of the medicine to remove
    char name[MAX_NAME_LENGTH];
    printf("Enter name of medicine to remove: ");
    scanf("%s", name);
    
    // Search for the medicine in the array
    int indexToRemove = -1;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            indexToRemove = i;
            break;
        }
    }
    
    // Check if the medicine was found
    if (indexToRemove == -1) {
        printf("Error: Medicine not found.\n");
        return;
    }
    
    // Remove the medicine from the array and shift all other elements up
    for (int i = indexToRemove; i < numMedicines - 1; i++) {
        strcpy(medicines[i].name, medicines[i + 1].name);
        medicines[i].quantity = medicines[i + 1].quantity;
        medicines[i].price = medicines[i + 1].price;
    }
    
    // Decrease the number of medicines in stock
    numMedicines--;
    
    printf("Medicine removed successfully.\n");
}

// Function to display the current inventory of medicines
void displayInventory() {
    printf("Current inventory:\n");
    printf("NAME\tQUANTITY\tPRICE\n");
    
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Main function to run the program
int main() {
    int choice;
    
    while (1) {
        printf("\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("1. Add new medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
    
    return 0;
}
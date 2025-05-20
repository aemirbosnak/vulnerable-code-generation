//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct {
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the store
void addMedicine(medicine *store, int *numMedicines) {
    printf("\nEnter the name of the medicine: ");
    scanf("%s", store[*numMedicines].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*numMedicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*numMedicines].quantity);
    (*numMedicines)++;
}

// Function to search for a medicine in the store
void searchMedicine(medicine *store, int numMedicines) {
    char name[50];
    printf("\nEnter the name of the medicine you want to search for: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("\nMedicine found!\n");
            printf("Name: %s\n", store[i].name);
            printf("Price: %f\n", store[i].price);
            printf("Quantity: %d\n", store[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found.\n");
    }
}

// Function to sell a medicine from the store
void sellMedicine(medicine *store, int *numMedicines) {
    char name[50];
    int quantity;
    printf("\nEnter the name of the medicine you want to sell: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &quantity);
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(store[i].name, name) == 0) {
            if (store[i].quantity < quantity) {
                printf("\nInsufficient quantity of medicine in stock.\n");
                return;
            }
            store[i].quantity -= quantity;
            printf("\nMedicine sold successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found.\n");
    }
}

// Function to display the inventory of the store
void displayInventory(medicine *store, int numMedicines) {
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < numMedicines; i++) {
        printf("%-5d %-20s %-10.2f %-10d\n", i + 1, store[i].name, store[i].price, store[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the medicine store
    medicine store[100];
    int numMedicines = 0;

    // Display the menu
    int choice;
    do {
        printf("\n***** Welcome to the Medical Store Management System *****\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Sell a medicine\n");
        printf("4. Display the inventory\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
        case 1:
            addMedicine(store, &numMedicines);
            break;
        case 2:
            searchMedicine(store, numMedicines);
            break;
        case 3:
            sellMedicine(store, &numMedicines);
            break;
        case 4:
            displayInventory(store, numMedicines);
            break;
        case 5:
            printf("\nThank you for using the Medical Store Management System.\n");
            break;
        default:
            printf("\nInvalid choice. Please enter a valid choice (1-5).\n");
        }
    } while (choice != 5);
    return 0;
}
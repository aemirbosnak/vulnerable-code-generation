//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
struct Medicine {
    int id;
    char name[50];
    char company[50];
    float price;
    int quantity;
};

// Function to display the menu
void displayMenu() {
    printf("\n\n***** Medical Store Management System *****\n");
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine by name\n");
    printf("4. Update medicine details\n");
    printf("5. Delete a medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new medicine
void addMedicine(struct Medicine *medicines, int *numMedicines) {
    printf("\n\nEnter medicine details:\n");

    // Get the medicine id
    printf("Enter ID: ");
    scanf("%d", &medicines[*numMedicines].id);

    // Get the medicine name
    printf("Enter name: ");
    scanf(" %[^\n]%*c", medicines[*numMedicines].name); // Read the entire line with spaces

    // Get the medicine company
    printf("Enter company: ");
    scanf(" %[^\n]%*c", medicines[*numMedicines].company);

    // Get the medicine price
    printf("Enter price: ");
    scanf("%f", &medicines[*numMedicines].price);

    // Get the medicine quantity
    printf("Enter quantity: ");
    scanf("%d", &medicines[*numMedicines].quantity);

    (*numMedicines)++; // Increment the number of medicines
}

// Function to display all medicines
void displayAllMedicines(struct Medicine *medicines, int numMedicines) {
    printf("\n\n***** List of Medicines *****\n");
    printf("ID\tName\t\tCompany\tPrice\tQuantity\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%d\t%-20s%-20s%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
    }
}

// Function to search for a medicine by name
void searchMedicineByName(struct Medicine *medicines, int numMedicines) {
    char name[50];

    // Get the medicine name
    printf("\nEnter the name of the medicine: ");
    scanf(" %[^\n]%*c", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("\n***** Medicine Found *****\n");
            printf("ID: %d\n", medicines[i].id);
            printf("Name: %s\n", medicines[i].name);
            printf("Company: %s\n", medicines[i].company);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            found = 1;
            break;
        }
    }

    // If the medicine was not found
    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Function to update medicine details
void updateMedicineDetails(struct Medicine *medicines, int numMedicines) {
    int id;

    // Get the medicine id
    printf("\nEnter the ID of the medicine to update: ");
    scanf("%d", &id);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].id == id) {
            // Get the updated medicine details
            printf("\nEnter the updated medicine details:\n");

            // Get the medicine name
            printf("Enter name: ");
            scanf(" %[^\n]%*c", medicines[i].name);

            // Get the medicine company
            printf("Enter company: ");
            scanf(" %[^\n]%*c", medicines[i].company);

            // Get the medicine price
            printf("Enter price: ");
            scanf("%f", &medicines[i].price);

            // Get the medicine quantity
            printf("Enter quantity: ");
            scanf("%d", &medicines[i].quantity);

            found = 1;
            break;
        }
    }

    // If the medicine was not found
    if (!found) {
        printf("\nMedicine not found!\n");
    } else {
        printf("\nMedicine details updated successfully!\n");
    }
}

// Function to delete a medicine
void deleteMedicine(struct Medicine *medicines, int *numMedicines) {
    int id;

    // Get the medicine id
    printf("\nEnter the ID of the medicine to delete: ");
    scanf("%d", &id);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (medicines[i].id == id) {
            // Delete the medicine
            for (int j = i; j < *numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*numMedicines)--; // Decrement the number of medicines
            found = 1;
            break;
        }
    }

    // If the medicine was not found
    if (!found) {
        printf("\nMedicine not found!\n");
    } else {
        printf("\nMedicine deleted successfully!\n");
    }
}

int main() {
    // Array to store the medicines
    struct Medicine medicines[100];

    // Number of medicines
    int numMedicines = 0;

    // Main loop
    int choice;
    do {
        // Display the menu
        displayMenu();

        // Get the user's choice
        scanf("%d", &choice);

        // Switch on the user's choice
        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                displayAllMedicines(medicines, numMedicines);
                break;
            case 3:
                searchMedicineByName(medicines, numMedicines);
                break;
            case 4:
                updateMedicineDetails(medicines, numMedicines);
                break;
            case 5:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 6:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
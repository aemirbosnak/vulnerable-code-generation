//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
struct Medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
};

// Function to display the menu
void displayMenu() {
    printf("\nMedical Store Management System\n");
    printf("--------------------------------\n");
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine\n");
    printf("4. Update medicine details\n");
    printf("5. Delete a medicine\n");
    printf("6. Exit\n");
    printf("--------------------------------\n");
    printf("Enter your choice: ");
}

// Function to add a new medicine
void addMedicine(struct Medicine *medicines, int *numMedicines) {
    printf("Enter medicine name: ");
    scanf(" %s", medicines[*numMedicines].name);
    printf("Enter medicine company: ");
    scanf(" %s", medicines[*numMedicines].company);
    printf("Enter medicine quantity: ");
    scanf(" %d", &medicines[*numMedicines].quantity);
    printf("Enter medicine price: ");
    scanf(" %f", &medicines[*numMedicines].price);
    (*numMedicines)++;
}

// Function to display all medicines
void displayAllMedicines(struct Medicine *medicines, int numMedicines) {
    printf("\nAll medicines:\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-10s | %-10s |\n", "Name", "Company", "Quantity", "Price");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("| %-20s | %-20s | %-10d | %-10.2f |\n", medicines[i].name, medicines[i].company, medicines[i].quantity, medicines[i].price);
    }
    printf("-------------------------------------------------------------------------------------------------------------\n");
}

// Function to search for a medicine
void searchMedicine(struct Medicine *medicines, int numMedicines) {
    char name[50];
    printf("Enter medicine name: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("-------------------------------------------------------------------------------------------------------------\n");
            printf("| %-20s | %-20s | %-10s | %-10s |\n", "Name", "Company", "Quantity", "Price");
            printf("-------------------------------------------------------------------------------------------------------------\n");
            printf("| %-20s | %-20s | %-10d | %-10.2f |\n", medicines[i].name, medicines[i].company, medicines[i].quantity, medicines[i].price);
            printf("-------------------------------------------------------------------------------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to update medicine details
void updateMedicine(struct Medicine *medicines, int numMedicines) {
    char name[50];
    printf("Enter medicine name: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter new medicine name: ");
            scanf(" %s", medicines[i].name);
            printf("Enter new medicine company: ");
            scanf(" %s", medicines[i].company);
            printf("Enter new medicine quantity: ");
            scanf(" %d", &medicines[i].quantity);
            printf("Enter new medicine price: ");
            scanf(" %f", &medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to delete a medicine
void deleteMedicine(struct Medicine *medicines, int *numMedicines) {
    char name[50];
    printf("Enter medicine name: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*numMedicines)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    // Array of medicines
    struct Medicine medicines[100];
    int numMedicines = 0;

    // Main loop
    int choice;
    do {
        displayMenu();
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                displayAllMedicines(medicines, numMedicines);
                break;
            case 3:
                searchMedicine(medicines, numMedicines);
                break;
            case 4:
                updateMedicine(medicines, numMedicines);
                break;
            case 5:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
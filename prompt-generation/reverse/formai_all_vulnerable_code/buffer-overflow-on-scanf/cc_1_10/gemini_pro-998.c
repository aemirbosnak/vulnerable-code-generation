//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: careful
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

// Function to display the menu
void displayMenu() {
    printf("\n\n\t\t**************************************************");
    printf("\n\t\t\t\tWelcome to the Medical Store Management System");
    printf("\n\t\t**************************************************");
    printf("\n\n\t\t1. Add a new medicine");
    printf("\n\t\t2. Display all medicines");
    printf("\n\t\t3. Search for a medicine");
    printf("\n\t\t4. Update a medicine");
    printf("\n\t\t5. Delete a medicine");
    printf("\n\t\t6. Exit");
    printf("\n\n\t\tPlease enter your choice: ");
}

// Function to add a new medicine
void addMedicine(medicine *medicines, int *numMedicines) {
    // Get the medicine details from the user
    printf("\nEnter the medicine ID: ");
    scanf("%d", &medicines[*numMedicines].id);
    printf("Enter the medicine name: ");
    scanf("%s", medicines[*numMedicines].name);
    printf("Enter the medicine price: ");
    scanf("%f", &medicines[*numMedicines].price);
    printf("Enter the medicine quantity: ");
    scanf("%d", &medicines[*numMedicines].quantity);

    // Increment the number of medicines
    (*numMedicines)++;
}

// Function to display all medicines
void displayAllMedicines(medicine *medicines, int numMedicines) {
    printf("\n\n\t\t**************************************************");
    printf("\n\t\t\t\t\tAll Medicines");
    printf("\n\t\t**************************************************");
    printf("\n\n\t\tID\tName\t\tPrice\tQuantity");
    printf("\n\t\t---------------------------------------------------");
    for (int i = 0; i < numMedicines; i++) {
        printf("\n\t\t%d\t%s\t\t%.2f\t%d", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Function to search for a medicine
void searchMedicine(medicine *medicines, int numMedicines) {
    // Get the medicine ID from the user
    int id;
    printf("\nEnter the medicine ID to search for: ");
    scanf("%d", &id);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].id == id) {
            printf("\n\n\t\t**************************************************");
            printf("\n\t\t\t\tMedicine Found");
            printf("\n\t\t**************************************************");
            printf("\n\n\t\tID\tName\t\tPrice\tQuantity");
            printf("\n\t\t---------------------------------------------------");
            printf("\n\t\t%d\t%s\t\t%.2f\t%d", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }

    // If the medicine was not found, display an error message
    if (!found) {
        printf("\n\n\t\tMedicine not found!");
    }
}

// Function to update a medicine
void updateMedicine(medicine *medicines, int numMedicines) {
    // Get the medicine ID from the user
    int id;
    printf("\nEnter the medicine ID to update: ");
    scanf("%d", &id);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].id == id) {
            // Get the updated medicine details from the user
            printf("\nEnter the new medicine name: ");
            scanf("%s", medicines[i].name);
            printf("Enter the new medicine price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter the new medicine quantity: ");
            scanf("%d", &medicines[i].quantity);
            found = 1;
            break;
        }
    }

    // If the medicine was not found, display an error message
    if (!found) {
        printf("\n\n\t\tMedicine not found!");
    }
}

// Function to delete a medicine
void deleteMedicine(medicine *medicines, int *numMedicines) {
    // Get the medicine ID from the user
    int id;
    printf("\nEnter the medicine ID to delete: ");
    scanf("%d", &id);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (medicines[i].id == id) {
            // Shift the remaining medicines to the left
            for (int j = i; j < *numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }

            // Decrement the number of medicines
            (*numMedicines)--;
            found = 1;
            break;
        }
    }

    // If the medicine was not found, display an error message
    if (!found) {
        printf("\n\n\t\tMedicine not found!");
    }
}

// Main function
int main() {
    // Declare an array of medicines
    medicine medicines[100];

    // Initialize the number of medicines to 0
    int numMedicines = 0;

    // Display the menu
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        // Perform the selected action
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
                printf("\n\n\t\tThank you for using the Medical Store Management System!");
                break;
            default:
                printf("\n\n\t\tInvalid choice!");
        }
    } while (choice != 6);

    return 0;
}
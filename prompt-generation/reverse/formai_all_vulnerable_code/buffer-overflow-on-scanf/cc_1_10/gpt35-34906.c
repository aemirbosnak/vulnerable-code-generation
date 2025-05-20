//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines that can be stored in the system
#define MAX_MEDICINES 100

// Define a structure for a medicine
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

// Define a function to add a new medicine to the system
void addMedicine(struct Medicine medicines[], int *numMedicines) {
    char name[50];
    int quantity;
    float price;

    // Get the details of the new medicine from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &price);

    // Create a new medicine and add it to the system
    struct Medicine newMedicine;
    strcpy(newMedicine.name, name);
    newMedicine.quantity = quantity;
    newMedicine.price = price;
    medicines[*numMedicines] = newMedicine;
    (*numMedicines)++;

    printf("Medicine added successfully.\n\n");
}

// Define a function to remove a medicine from the system
void removeMedicine(struct Medicine medicines[], int *numMedicines) {
    char name[50];

    // Get the name of the medicine to remove from the user
    printf("Enter the name of the medicine to remove: ");
    scanf("%s", name);

    // Find the medicine to remove in the system
    int index = -1;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n\n");
    } else {
        // Remove the medicine from the system
        for (int i = index; i < *numMedicines - 1; i++) {
            medicines[i] = medicines[i+1];
        }
        (*numMedicines)--;

        printf("Medicine removed successfully.\n\n");
    }
}

// Define a function to update the details of a medicine in the system
void updateMedicine(struct Medicine medicines[], int numMedicines) {
    char name[50];

    // Get the name of the medicine to update from the user
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    // Find the medicine to update in the system
    int index = -1;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n\n");
    } else {
        // Get the updated details of the medicine from the user
        int quantity;
        float price;
        printf("Enter the new quantity of the medicine: ");
        scanf("%d", &quantity);
        printf("Enter the new price of the medicine: ");
        scanf("%f", &price);

        // Update the medicine in the system
        medicines[index].quantity = quantity;
        medicines[index].price = price;

        printf("Medicine updated successfully.\n\n");
    }
}

// Define a function to display all medicines in the system
void displayMedicines(struct Medicine medicines[], int numMedicines) {
    if (numMedicines == 0) {
        printf("No medicines found.\n\n");
    } else {
        printf("List of medicines:\n");
        printf("------------------\n");

        for (int i = 0; i < numMedicines; i++) {
            printf("%s - Quantity: %d - Price: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
        }

        printf("\n");
    }
}

int main() {
    struct Medicine medicines[MAX_MEDICINES];
    int numMedicines = 0;
    int choice;

    do {
        // Display the menu of options to the user
        printf("Welcome to the Medical Store Management System.\n");
        printf("Please choose an option:\n");
        printf("1. Add a new medicine\n");
        printf("2. Remove a medicine\n");
        printf("3. Update a medicine\n");
        printf("4. Display all medicines\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                removeMedicine(medicines, &numMedicines);
                break;
            case 3:
                updateMedicine(medicines, numMedicines);
                break;
            case 4:
                displayMedicines(medicines, numMedicines);
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System.\n");
                return 0;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while (1);
}
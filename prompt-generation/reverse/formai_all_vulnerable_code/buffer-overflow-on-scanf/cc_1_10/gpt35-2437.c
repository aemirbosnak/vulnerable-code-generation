//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing medicine information
typedef struct Medicine {
    char name[50];
    char company[30];
    float price;
    int quantity;
} Medicine;

// Function prototypes
int menu();
void addNewMedicine(Medicine **, int *);
void removeMedicine(Medicine **, int *);
void displayMedicine(Medicine *, int);
void searchMedicine(Medicine *, int);

int main() {
    Medicine *medicines = NULL;
    int totalMedicines = 0;

    int choice;
    do {
        choice = menu();

        switch(choice) {
            case 1:
                addNewMedicine(&medicines, &totalMedicines);
                break;
            case 2:
                removeMedicine(&medicines, &totalMedicines);
                break;
            case 3:
                displayMedicine(medicines, totalMedicines);
                break;
            case 4:
                searchMedicine(medicines, totalMedicines);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// Displays the main menu and returns user's choice
int menu() {
    int choice;
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add New Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Display All Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Exit Program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Adds a new medicine to the inventory
void addNewMedicine(Medicine **medicines, int *totalMedicines) {
    printf("\n--- Add New Medicine ---\n");

    // Reallocates memory for new medicine
    *medicines = (Medicine*)realloc(*medicines, (*totalMedicines + 1) * sizeof(Medicine));

    // Takes input for new medicine information and adds it to array
    printf("Name: ");
    scanf("%s", (*medicines)[*totalMedicines].name);
    printf("Company: ");
    scanf("%s", (*medicines)[*totalMedicines].company);
    printf("Price: ");
    scanf("%f", &((*medicines)[*totalMedicines].price));
    printf("Quantity: ");
    scanf("%d", &((*medicines)[*totalMedicines].quantity));

    // Updates total medicine count
    (*totalMedicines)++;

    printf("Medicine added successfully!\n");
}

// Removes a medicine from the inventory
void removeMedicine(Medicine **medicines, int *totalMedicines) {
    printf("\n--- Remove Medicine ---\n");

    // Takes input for medicine name to be removed
    char name[50];
    printf("Enter medicine name to be removed: ");
    scanf("%s", name);

    int found = 0;

    // Removes the medicine from array if found
    for(int i=0; i<*totalMedicines; i++) {
        if(strcmp((*medicines)[i].name, name) == 0) {
            for(int j=i; j<(*totalMedicines)-1; j++) {
                (*medicines)[j] = (*medicines)[j+1];
            }
            // Reallocates memory to update total medicine count
            *medicines = (Medicine*)realloc(*medicines, (*totalMedicines - 1) * sizeof(Medicine));
            (*totalMedicines)--;
            found = 1;
            printf("Medicine removed successfully!\n");
            break;
        }
    }

    if(!found) {
        printf("Medicine not found!\n");
    }
}

// Displays all medicines in the inventory
void displayMedicine(Medicine *medicines, int totalMedicines) {
    printf("\n--- Display All Medicine ---\n");

    if(totalMedicines == 0) {
        printf("No medicine found!\n");
        return;
    }

    printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Price", "Quantity");
    for(int i=0; i<totalMedicines; i++) {
        printf("%-20s %-20s %-10.2f %-10d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
    }
}

// Searches for a medicine by name and displays its information
void searchMedicine(Medicine *medicines, int totalMedicines) {
    printf("\n--- Search Medicine ---\n");

    if(totalMedicines == 0) {
        printf("No medicine found!\n");
        return;
    }

    // Takes input for medicine name to be searched
    char name[50];
    printf("Enter medicine name to be searched: ");
    scanf("%s", name);

    int found = 0;

    // Displays medicine information if found
    for(int i=0; i<totalMedicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Price", "Quantity");
            printf("%-20s %-20s %-10.2f %-10d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Medicine not found!\n");
    }
}
//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum number of medicines that can be stored
#define MAX_MEDICINES 5

// Defining the structure for medicines
typedef struct Medicine {
    char name[50];
    char category[50];
    float price;
    int quantity;
} Medicine;

// Function to display the menu options
void displayMenu() {
    printf("\n\n *** C MEDICAL STORE MANAGEMENT SYSTEM *** \n\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Display Available Medicines\n");
    printf("6. Exit\n\n");
}

// Function to add new medicine
void addMedicine(Medicine* medicines[], int* numMedicines) {
    if (*numMedicines == MAX_MEDICINES) {
        printf("Cannot add more medicines.\n");
        return;
    }
    // Creating a new medicine object
    Medicine* newMedicine = (Medicine*) malloc(sizeof(Medicine));
    printf("\nEnter the details of the new medicine: \n");
    printf("Name: ");
    scanf("%s", newMedicine->name);
    printf("Category: ");
    scanf("%s", newMedicine->category);
    printf("Price: ");
    scanf("%f", &newMedicine->price);
    printf("Quantity: ");
    scanf("%d", &newMedicine->quantity);
    // Adding the new medicine to the array
    medicines[*numMedicines] = newMedicine;
    // Incrementing the number of medicines
    (*numMedicines)++;
    printf("Medicine added successfully.\n");
}

// Function to update an existing medicine
void updateMedicine(Medicine* medicines[], int numMedicines) {
    char name[50];
    printf("\nEnter the name of the medicine you want to update: ");
    scanf("%s", name);
    // Searching for the medicine in the array
    for(int i=0; i<numMedicines; i++) {
        if(strcmp(name, medicines[i]->name) == 0) {
            printf("Enter the new details of the medicine: \n");
            printf("Name: ");
            scanf("%s", medicines[i]->name);
            printf("Category: ");
            scanf("%s", medicines[i]->category);
            printf("Price: ");
            scanf("%f", &medicines[i]->price);
            printf("Quantity: ");
            scanf("%d", &medicines[i]->quantity);
            printf("Medicine updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to delete an existing medicine
void deleteMedicine(Medicine* medicines[], int* numMedicines) {
    char name[50];
    printf("\nEnter the name of the medicine you want to delete: ");
    scanf("%s", name);
    // Searching for the medicine in the array
    for(int i=0; i<*numMedicines; i++) {
        if(strcmp(name, medicines[i]->name) == 0) {
            // Deleting the medicine by shifting the elements to the left
            for(int j=i; j<(*numMedicines)-1; j++) {
                medicines[j] = medicines[j+1];
            }
            // Decrementing the number of medicines
            (*numMedicines)--;
            printf("Medicine deleted successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to search for a medicine by name
void searchMedicine(Medicine* medicines[], int numMedicines) {
    char name[50];
    printf("\nEnter the name of the medicine you want to search: ");
    scanf("%s", name);
    // Searching for the medicine in the array
    for(int i=0; i<numMedicines; i++) {
        if(strcmp(name, medicines[i]->name) == 0) {
            printf("\nDetails of the medicine: \n");
            printf("Name: %s\n", medicines[i]->name);
            printf("Category: %s\n", medicines[i]->category);
            printf("Price: %.2f\n", medicines[i]->price);
            printf("Quantity: %d\n", medicines[i]->quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to display all the available medicines
void displayMedicines(Medicine* medicines[], int numMedicines) {
    printf("\nAvailable Medicines: \n");
    for(int i=0; i<numMedicines; i++) {
        printf("\nDetails of Medicine %d: \n", i+1);
        printf("Name: %s\n", medicines[i]->name);
        printf("Category: %s\n", medicines[i]->category);
        printf("Price: %.2f\n", medicines[i]->price);
        printf("Quantity: %d\n", medicines[i]->quantity);
    }
}

int main() {
    // Initializing the array of medicines and the number of medicines
    Medicine* medicines[MAX_MEDICINES];
    int numMedicines = 0;

    while(1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                updateMedicine(medicines, numMedicines);
                break;
            case 3:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 4:
                searchMedicine(medicines, numMedicines);
                break;
            case 5:
                displayMedicines(medicines, numMedicines);
                break;
            case 6:
                printf("Thank you for using C Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
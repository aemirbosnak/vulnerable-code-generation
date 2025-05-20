//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICATIONS 100
#define NAME_SIZE 50

// Structure for Medication
typedef struct {
    int id;
    char name[NAME_SIZE];
    int quantity;
    float price;
} Medication;

// Function prototypes
void addMedication(Medication meds[], int *count);
void viewMedications(Medication meds[], int count);
void modifyMedication(Medication meds[], int count);
void deleteMedication(Medication meds[], int *count);
void displayMenu();

int main() {
    Medication medications[MAX_MEDICATIONS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedication(medications, &count);
                break;
            case 2:
                viewMedications(medications, count);
                break;
            case 3:
                modifyMedication(medications, count);
                break;
            case 4:
                deleteMedication(medications, &count);
                break;
            case 5:
                printf("Exiting the program. Take care!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medication\n");
    printf("2. View Medications\n");
    printf("3. Modify Medication\n");
    printf("4. Delete Medication\n");
    printf("5. Exit\n");
}

void addMedication(Medication meds[], int *count) {
    if (*count >= MAX_MEDICATIONS) {
        printf("Cannot add more medications. Inventory full!\n");
        return;
    }
    
    Medication newMed;
    newMed.id = *count + 1; // Auto increment ID on addition
    
    printf("Enter medication name: ");
    scanf("%s", newMed.name);
    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);
    printf("Enter price: ");
    scanf("%f", &newMed.price);

    meds[*count] = newMed;
    (*count)++;
    printf("Medication added successfully!\n");
}

void viewMedications(Medication meds[], int count) {
    if (count == 0) {
        printf("No medications available in the store.\n");
        return;
    }
    
    printf("\n===== List of Medications =====\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               meds[i].id, meds[i].name, meds[i].quantity, meds[i].price);
    }
}

void modifyMedication(Medication meds[], int count) {
    int id;
    printf("Enter the ID of the medication to modify: ");
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Medication not found!\n");
        return;
    }

    printf("Enter new medication name: ");
    scanf("%s", meds[id - 1].name);
    printf("Enter new quantity: ");
    scanf("%d", &meds[id - 1].quantity);
    printf("Enter new price: ");
    scanf("%f", &meds[id - 1].price);
    
    printf("Medication updated successfully!\n");
}

void deleteMedication(Medication meds[], int *count) {
    int id;
    printf("Enter the ID of the medication to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > *count) {
        printf("Medication not found!\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        meds[i] = meds[i + 1]; // Shift all medications one index up
    }
    (*count)--; // Decrease the count of medications
    printf("Medication deleted successfully!\n");
}
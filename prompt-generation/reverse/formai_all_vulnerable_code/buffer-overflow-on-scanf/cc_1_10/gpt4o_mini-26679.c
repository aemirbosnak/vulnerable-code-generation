//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Structure to hold medication data
typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Medication;

// Function prototypes
void displayMenu();
void addMedication(Medication meds[], int *count);
void viewMedications(Medication meds[], int count);
void deleteMedication(Medication meds[], int *count);
int isValidId(int id, Medication meds[], int count);

int main() {
    Medication medications[MAX_ITEMS];
    int count = 0;
    int choice;

    printf("Welcome to the Medical Store Management System!\n");
    
    do {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedication(medications, &count);
                break;
            case 2:
                viewMedications(medications, count);
                break;
            case 3:
                deleteMedication(medications, &count);
                break;
            case 4:
                printf("Exiting the system. Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Medical Store Management Menu ---\n");
    printf("1. Add Medication\n");
    printf("2. View Medications\n");
    printf("3. Delete Medication\n");
    printf("4. Exit\n");
}

// Function to add medication
void addMedication(Medication meds[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Cannot add any more medications. Max limit reached.\n");
        return;
    }

    Medication newMed;
    newMed.id = *count + 1; // Assign an ID based on current count
    printf("Enter medication name: ");
    scanf(" %[^\n]%*c", newMed.name);
    printf("Enter medication price: ");
    scanf("%f", &newMed.price);
    printf("Enter medication quantity: ");
    scanf("%d", &newMed.quantity);

    meds[*count] = newMed;
    (*count)++;
    printf("Medication added successfully.\n");
}

// Function to view all medications
void viewMedications(Medication meds[], int count) {
    if (count == 0) {
        printf("No medications available to display.\n");
        return;
    }

    printf("\n--- Medication List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", meds[i].id, meds[i].name, meds[i].price, meds[i].quantity);
    }
}

// Function to delete medication
void deleteMedication(Medication meds[], int *count) {
    if (*count == 0) {
        printf("No medications available to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the medication to delete: ");
    scanf("%d", &id);

    if (!isValidId(id, meds, *count)) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < *count - 1; i++) {
        meds[i] = meds[i + 1]; // Move medications up to fill the gap
    }
    (*count)--;
    printf("Medication deleted successfully.\n");
}

// Function to validate if an ID exists
int isValidId(int id, Medication meds[], int count) {
    return (id > 0 && id <= count);
}
//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICATIONS 100

typedef struct {
    char name[50];
    char type[50];
    int quantity;
    float price;
} Medication;

Medication store[MAX_MEDICATIONS];
int medicationCount = 0;

void addMedication();
void displayMedications();
void updateMedication();
void deleteMedication();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medication\n");
    printf("2. Display Medications\n");
    printf("3. Update Medication\n");
    printf("4. Delete Medication\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMedication();
            break;
        case 2:
            displayMedications();
            break;
        case 3:
            updateMedication();
            break;
        case 4:
            deleteMedication();
            break;
        case 5:
            printf("Exiting the system. Goodbye!\n");
            return;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
    menu();  // Recursive call to show the menu again
}

void addMedication() {
    if (medicationCount >= MAX_MEDICATIONS) {
        printf("Memory full! Cannot add more medications.\n");
        return;
    }

    Medication med;
    printf("Enter medication name: ");
    scanf("%s", med.name);
    printf("Enter medication type: ");
    scanf("%s", med.type);
    printf("Enter medication quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter medication price: ");
    scanf("%f", &med.price);

    store[medicationCount++] = med;
    printf("Medication added successfully!\n");
}

void displayMedications() {
    if (medicationCount == 0) {
        printf("No medications available!\n");
    } else {
        printf("\n--- Medications ---\n");
        for (int i = 0; i < medicationCount; i++) {
            printf("ID: %d, Name: %s, Type: %s, Quantity: %d, Price: %.2f\n",
                   i + 1, store[i].name, store[i].type, store[i].quantity, store[i].price);
        }
    }
}

void updateMedication() {
    int id;
    printf("Enter medication ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > medicationCount) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    Medication med;
    printf("Enter new medication name: ");
    scanf("%s", med.name);
    printf("Enter new medication type: ");
    scanf("%s", med.type);
    printf("Enter new medication quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter new medication price: ");
    scanf("%f", &med.price);

    store[id - 1] = med;
    printf("Medication updated successfully!\n");
}

void deleteMedication() {
    int id;
    printf("Enter medication ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > medicationCount) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < medicationCount - 1; i++) {
        store[i] = store[i + 1];  // Shift medications left
    }
    medicationCount--;
    printf("Medication deleted successfully!\n");
}
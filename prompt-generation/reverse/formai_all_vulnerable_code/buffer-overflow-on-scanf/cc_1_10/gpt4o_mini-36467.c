//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum sizes for medicine data
#define MAX_MEDICINES 100
#define MAX_NAME_LEN 50
#define MAX_COMPANY_LEN 50

// Medicine Structure
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    float price;
    int quantity;
} Medicine;

// Global array to store medicines
Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

// Function Declarations
void addMedicine();
void updateMedicine();
void deleteMedicine();
void displayMedicines();
void showMenu();

// Main Function
int main() {
    while (1) {
        showMenu();
    }
    return 0;
}

// Function to display menu
void showMenu() {
    int choice;

    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. Display Medicines\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: addMedicine(); break;
        case 2: updateMedicine(); break;
        case 3: deleteMedicine(); break;
        case 4: displayMedicines(); break;
        case 5: exit(0); break;
        default: printf("Invalid choice! Please try again.\n");
    }
}

// Function to add a medicine to the store
void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }

    Medicine med;
    med.id = medicineCount + 1; // Assign ID automatically
    printf("Enter Medicine Name: ");
    scanf("%s", med.name);
    printf("Enter Company Name: ");
    scanf("%s", med.company);
    printf("Enter Price: ");
    scanf("%f", &med.price);
    printf("Enter Quantity: ");
    scanf("%d", &med.quantity);

    medicines[medicineCount++] = med;
    printf("Medicine added successfully!\n");
}

// Function to update existing medicine details
void updateMedicine() {
    int id;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > medicineCount) {
        printf("Medicine with ID %d does not exist.\n", id);
        return;
    }

    Medicine *med = &medicines[id - 1];

    printf("Updating details for Medicine ID %d:\n", med->id);
    printf("Current Name: %s\n", med->name);
    printf("Enter new Name: ");
    scanf("%s", med->name);
    printf("Current Company: %s\n", med->company);
    printf("Enter new Company: ");
    scanf("%s", med->company);
    printf("Current Price: %.2f\n", med->price);
    printf("Enter new Price: ");
    scanf("%f", &med->price);
    printf("Current Quantity: %d\n", med->quantity);
    printf("Enter new Quantity: ");
    scanf("%d", &med->quantity);

    printf("Medicine updated successfully!\n");
}

// Function to delete a medicine from the store
void deleteMedicine() {
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > medicineCount) {
        printf("Medicine with ID %d does not exist.\n", id);
        return;
    }

    for (int i = id - 1; i < medicineCount - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    
    medicineCount--;
    printf("Medicine deleted successfully!\n");
}

// Function to display all medicines in the system
void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in the store.\n");
        return;
    }

    printf("\nID\tName\t\tCompany\t\tPrice\tQuantity\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        Medicine med = medicines[i];
        printf("%d\t%s\t\t%s\t%.2f\t%d\n", med.id, med.name, med.company, med.price, med.quantity);
    }
}
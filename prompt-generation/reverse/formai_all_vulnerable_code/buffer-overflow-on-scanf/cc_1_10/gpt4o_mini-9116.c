//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int stock;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} Pharmacy;

// Function prototypes
void addMedicine(Pharmacy *pharmacy);
void displayMedicines(const Pharmacy *pharmacy);
void sellMedicine(Pharmacy *pharmacy);
void searchMedicine(const Pharmacy *pharmacy);
void displayMenu();

int main() {
    Pharmacy pharmacy = {.count = 0};
    int choice;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                addMedicine(&pharmacy);
                break;
            case 2: 
                displayMedicines(&pharmacy);
                break;
            case 3: 
                sellMedicine(&pharmacy);
                break;
            case 4: 
                searchMedicine(&pharmacy);
                break;
            case 5: 
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addMedicine(Pharmacy *pharmacy) {
    if (pharmacy->count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter stock of medicine: ");
    scanf("%d", &newMedicine.stock);
    printf("Enter price of medicine: ");
    scanf("%f", &newMedicine.price);
    
    pharmacy->medicines[pharmacy->count] = newMedicine;
    pharmacy->count++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(const Pharmacy *pharmacy) {
    if (pharmacy->count == 0) {
        printf("No medicines to display.\n");
        return;
    }
    
    printf("\nAvailable Medicines:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Stock", "Price");
    for (int i = 0; i < pharmacy->count; i++) {
        printf("%-20s %-10d $%-9.2f\n", pharmacy->medicines[i].name, pharmacy->medicines[i].stock, pharmacy->medicines[i].price);
    }
}

void sellMedicine(Pharmacy *pharmacy) {
    char name[NAME_LEN];
    int quantity;

    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < pharmacy->count; i++) {
        if (strcmp(pharmacy->medicines[i].name, name) == 0) {
            if (pharmacy->medicines[i].stock >= quantity) {
                pharmacy->medicines[i].stock -= quantity;
                printf("Sold %d units of %s for $%.2f\n", quantity, name, pharmacy->medicines[i].price * quantity);
            } else {
                printf("Insufficient stock for %s. Available: %d\n", name, pharmacy->medicines[i].stock);
            }
            return;
        }
    }
    printf("Medicine %s not found in inventory.\n", name);
}

void searchMedicine(const Pharmacy *pharmacy) {
    char name[NAME_LEN];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (int i = 0; i < pharmacy->count; i++) {
        if (strcmp(pharmacy->medicines[i].name, name) == 0) {
            printf("Medicine found: %s | Stock: %d | Price: $%.2f\n", pharmacy->medicines[i].name, pharmacy->medicines[i].stock, pharmacy->medicines[i].price);
            return;
        }
    }
    printf("Medicine %s not found in inventory.\n", name);
}

void displayMenu() {
    printf("\n--- Pharmacy Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
}
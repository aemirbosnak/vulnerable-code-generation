//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char expiryDate[11]; // Format: YYYY-MM-DD
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} Pharmacy;

void addMedicine(Pharmacy *pharmacy) {
    if (pharmacy->count >= MAX_MEDICINES) {
        printf("The pharmacy is full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine newMedicine;

    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    
    printf("Enter expiry date (YYYY-MM-DD): ");
    scanf("%s", newMedicine.expiryDate);
    
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    
    pharmacy->medicines[pharmacy->count] = newMedicine;
    pharmacy->count++;
    
    printf("Medicine added successfully!\n");
}

void displayMedicines(Pharmacy *pharmacy) {
    if (pharmacy->count == 0) {
        printf("No medicines to display.\n");
        return;
    }
    
    printf("\nList of Medicines:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s%-15s%-15s%-10s\n", "Name", "Expiry Date", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < pharmacy->count; i++) {
        Medicine m = pharmacy->medicines[i];
        printf("%-20s%-15s%-15d%-10.2f\n", m.name, m.expiryDate, m.quantity, m.price);
    }
}

void processSale(Pharmacy *pharmacy) {
    char medicineName[50];
    int quantity;
    
    printf("Enter medicine name to sell: ");
    scanf("%s", medicineName);
    
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < pharmacy->count; i++) {
        if (strcmp(pharmacy->medicines[i].name, medicineName) == 0) {
            if (pharmacy->medicines[i].quantity >= quantity) {
                pharmacy->medicines[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining: %d\n", quantity, medicineName, pharmacy->medicines[i].quantity);
                return;
            } else {
                printf("Not enough quantity available.\n");
                return;
            }
        }
    }
    printf("Medicine not found.\n");
}

void removeExpiredMedicines(Pharmacy *pharmacy) {
    char currentDate[11] = "2023-10-01"; // For simplicity, using a static date
    int i, j;

    for (i = 0; i < pharmacy->count; i++) {
        if (strcmp(pharmacy->medicines[i].expiryDate, currentDate) < 0) {
            // Found an expired medicine, remove it
            printf("Removing expired medicine: %s\n", pharmacy->medicines[i].name);
            for (j = i; j < pharmacy->count - 1; j++) {
                pharmacy->medicines[j] = pharmacy->medicines[j + 1];
            }
            pharmacy->count--;
            i--; // Check this index again
        }
    }
}

void mainMenu() {
    Pharmacy pharmacy = { .count = 0 };
    int choice;

    do {
        printf("\n--- Pharmacy Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Remove Expired Medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&pharmacy);
                break;
            case 2:
                displayMedicines(&pharmacy);
                break;
            case 3:
                processSale(&pharmacy);
                break;
            case 4:
                removeExpiredMedicines(&pharmacy);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    mainMenu();
    return 0;
}
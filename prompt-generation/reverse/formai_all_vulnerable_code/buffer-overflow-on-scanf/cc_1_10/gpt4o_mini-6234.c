//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char expiryDate[10];
    float price;
    int stock;
} Medicine;

Medicine medicineList[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Inventory full!\n");
        return;
    }
    
    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter expiry date (DD-MM-YYYY): ");
    scanf("%s", m.expiryDate);
    printf("Enter price: ");
    scanf("%f", &m.price);
    printf("Enter stock: ");
    scanf("%d", &m.stock);

    medicineList[medicineCount++] = m;
    printf("Medicine added successfully.\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    printf("\nMedicine Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-12s | %-6s | %-7s |\n", "Name", "Expiry Date", "Price", "Stock");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < medicineCount; i++) {
        printf("| %-20s | %-12s | %.2f  | %-7d |\n", 
                medicineList[i].name, medicineList[i].expiryDate, 
                medicineList[i].price, medicineList[i].stock);
    }
    printf("--------------------------------------------------\n");
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            printf("Updating medicine %s:\n", name);
            printf("Enter new expiry date (DD-MM-YYYY): ");
            scanf("%s", medicineList[i].expiryDate);
            printf("Enter new price: ");
            scanf("%f", &medicineList[i].price);
            printf("Enter new stock: ");
            scanf("%d", &medicineList[i].stock);
            printf("Medicine updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicineList[j] = medicineList[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            printf("Medicine found: %s, Expiry: %s, Price: %.2f, Stock: %d\n", 
                    medicineList[i].name, medicineList[i].expiryDate, 
                    medicineList[i].price, medicineList[i].stock);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void menu() {
    while (1) {
        int choice;
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: updateMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: searchMedicine(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
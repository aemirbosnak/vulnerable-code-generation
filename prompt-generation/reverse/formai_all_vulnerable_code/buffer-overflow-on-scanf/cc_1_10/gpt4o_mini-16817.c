//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define CODE_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine();
void viewMedicines();
void updateMedicine();
void deleteMedicine();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n======== Medical Store Management System ========\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: updateMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: printf("Exiting the system...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 5);
}

void addMedicine() {
    if (medicineCount < MAX_MEDICINES) {
        Medicine m;
        printf("Enter medicine name: ");
        scanf("%s", m.name);
        printf("Enter medicine code: ");
        scanf("%s", m.code);
        printf("Enter quantity: ");
        scanf("%d", &m.quantity);
        printf("Enter price: ");
        scanf("%f", &m.price);
        
        medicines[medicineCount] = m;
        medicineCount++;
        
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add more medicines. Storage full!\n");
    }
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }
    
    printf("\n======= List of Medicines =======\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("Name: %s\n", medicines[i].name);
        printf("Code: %s\n", medicines[i].code);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Price: %.2f\n", medicines[i].price);
        printf("-----------------------------------\n");
    }
}

void updateMedicine() {
    char code[CODE_LENGTH];
    printf("Enter the medicine code to update: ");
    scanf("%s", code);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            printf("Updating medicine: %s\n", medicines[i].name);
            printf("Current Quantity: %d\n", medicines[i].quantity);
            printf("Current Price: %.2f\n", medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    
    printf("Medicine with code %s not found!\n", code);
}

void deleteMedicine() {
    char code[CODE_LENGTH];
    printf("Enter the medicine code to delete: ");
    scanf("%s", code);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    
    printf("Medicine with code %s not found!\n", code);
}
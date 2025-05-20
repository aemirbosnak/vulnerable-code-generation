//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char type[NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage full!\n");
        return;
    }

    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter medicine type: ");
    scanf("%s", m.type);
    printf("Enter medicine price: ");
    scanf("%f", &m.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m.quantity);

    medicines[medicineCount++] = m;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\nList of Medicines:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Medicine %d:\n", i + 1);
        printf("  Name: %s\n", medicines[i].name);
        printf("  Type: %s\n", medicines[i].type);
        printf("  Price: %.2f\n", medicines[i].price);
        printf("  Quantity: %d\n\n", medicines[i].quantity);
    }
}

void searchMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("  Name: %s\n", medicines[i].name);
            printf("  Type: %s\n", medicines[i].type);
            printf("  Price: %.2f\n", medicines[i].price);
            printf("  Quantity: %d\n\n", medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

int menu() {
    int choice;
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    while (1) {
        int choice = menu();
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}
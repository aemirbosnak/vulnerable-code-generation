//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached!\n");
        return;
    }
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf(" %[^\n]", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    medicines[medicineCount] = newMedicine;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("\n%20s %10s %10s\n", "Medicine Name", "Quantity", "Price");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%20s %10d %10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("----------------------------------------------------\n");
}

void updateMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the medicine name to update its stock: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine stock updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the medicine name to delete: ");
    scanf(" %[^\n]", name);
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

void statistics() {
    int totalQuantity = 0;
    float totalValue = 0.0;
    for (int i = 0; i < medicineCount; i++) {
        totalQuantity += medicines[i].quantity;
        totalValue += (medicines[i].quantity * medicines[i].price);
    }
    printf("\nStatistics:\n");
    printf("Total number of medicines: %d\n", medicineCount);
    printf("Total quantity of medicines: %d\n", totalQuantity);
    printf("Total stock value: %.2f\n", totalValue);
}

int main() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Display Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                statistics();
                break;
            case 6:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
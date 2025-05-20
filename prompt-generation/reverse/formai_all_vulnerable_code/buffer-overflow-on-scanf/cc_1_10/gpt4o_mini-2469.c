//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }

    Medicine new_medicine;

    printf("Enter medicine ID: ");
    scanf("%d", &new_medicine.id);
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_medicine.quantity);

    medicines[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void sellMedicine() {
    int id, quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            if (medicines[i].quantity >= quantity) {
                medicines[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", quantity, medicines[i].name, medicines[i].quantity);
                return;
            } else {
                printf("Not enough quantity in stock!\n");
                return;
            }
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine() {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            printf("Medicine found: ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", 
                medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            printf("Updating details for %s:\n", medicines[i].name);
            printf("Enter new name (current: %s): ", medicines[i].name);
            scanf("%s", medicines[i].name);
            printf("Enter new price (current: %.2f): ", medicines[i].price);
            scanf("%f", &medicines[i].price);
            printf("Enter new quantity (current: %d): ", medicines[i].quantity);
            scanf("%d", &medicines[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Update Medicine\n");
    printf("6. Delete Medicine\n");
    printf("7. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
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
                sellMedicine();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                updateMedicine();
                break;
            case 6:
                deleteMedicine();
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
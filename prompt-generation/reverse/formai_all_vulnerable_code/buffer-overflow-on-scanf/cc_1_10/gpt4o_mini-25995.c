//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }

    Medicine med;
    printf("Enter medicine ID: ");
    scanf("%d", &med.id);
    printf("Enter medicine name: ");
    getchar();  // To consume the newline character left by scanf
    fgets(med.name, MAX_NAME_LENGTH, stdin);
    med.name[strcspn(med.name, "\n")] = '\0';  // Remove the newline character
    printf("Enter medicine price: ");
    scanf("%f", &med.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &med.quantity);

    inventory[medicineCount] = med;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }
    
    printf("\nMedicines in Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void sellMedicine() {
    int id, quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Sold %d of %s\n", quantity, inventory[i].name);
                return;
            } else {
                printf("Not enough quantity available to sell.\n");
                return;
            }
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void searchMedicine() {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            printf("Medicine found!\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating details for %s\n", inventory[i].name);
            printf("Enter new medicine name: ");
            getchar();  // To consume the newline character left by scanf
            fgets(inventory[i].name, MAX_NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = '\0';  // Remove the newline
            printf("Enter new medicine price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new medicine quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found for update.\n", id);
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < medicineCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicineCount--;
            printf("Medicine with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

int main() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Update Medicine\n");
        printf("6. Delete Medicine\n");
        printf("7. Exit\n");
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
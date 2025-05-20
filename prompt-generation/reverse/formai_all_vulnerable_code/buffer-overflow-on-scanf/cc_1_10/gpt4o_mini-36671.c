//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    Medicine m;
    m.id = medicineCount + 1;

    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter price per unit: ");
    scanf("%f", &m.price);

    inventory[medicineCount] = m;
    medicineCount++;
    printf("Medicine '%s' added successfully!\n\n", m.name);
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in the inventory!\n\n");
        return;
    }
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void sellMedicine() {
    int id, quantity;
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    if (id <= 0 || id > medicineCount) {
        printf("Invalid medicine ID!\n\n");
        return;
    }
    if (inventory[id - 1].quantity < quantity) {
        printf("Not enough stock available for '%s'!\n\n", inventory[id - 1].name);
        return;
    }

    inventory[id - 1].quantity -= quantity;
    printf("Sold %d units of medicine '%s'.\nTotal Price: %.2f\n\n", quantity, inventory[id - 1].name, inventory[id - 1].price * quantity);
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < medicineCount; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("No medicine found with name '%s'\n\n", name);
    } else {
        printf("\n");
    }
}

void displayMenu() {
    printf("**** Medical Store Management System ****\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Sell Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}
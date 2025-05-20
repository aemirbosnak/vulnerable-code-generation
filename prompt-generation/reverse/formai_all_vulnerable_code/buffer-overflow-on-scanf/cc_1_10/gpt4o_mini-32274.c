//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int id;
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX];
int count = 0;

void addMedicine() {
    if (count >= MAX) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine med;

    printf("Enter medicine name: ");
    getchar(); // to consume the newline character
    fgets(med.name, sizeof(med.name), stdin);
    med.name[strcspn(med.name, "\n")] = 0; // remove newline character

    printf("Enter medicine ID: ");
    scanf("%d", &med.id);

    printf("Enter medicine price: ");
    scanf("%f", &med.price);

    printf("Enter quantity: ");
    scanf("%d", &med.quantity);

    inventory[count++] = med;
    printf("Medicine added successfully!\n");
}

void listMedicines() {
    if (count == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void searchMedicine() {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Medicine found: %s, Price: %.2f, Quantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("Medicine with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Updating medicine: %s\n", inventory[i].name);
            printf("Enter new medicine name: ");
            getchar(); // consume newline
            fgets(inventory[i].name, sizeof(inventory[i].name), stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // remove newline character

            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void displayMenu() {
    printf("\n====== Medical Store Management System ======\n");
    printf("1. Add Medicine\n");
    printf("2. List Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("==============================================\n");
    printf("Choose an option: ");
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
                listMedicines();
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
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LEN 50
#define CODE_LEN 20

typedef struct {
    char name[NAME_LEN];
    char code[CODE_LEN];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int numMedicines = 0;

void addMedicine() {
    if (numMedicines < MAX_MEDICINES) {
        Medicine newMedicine;
        
        printf("Enter Medicine Name: ");
        scanf("%s", newMedicine.name);
        printf("Enter Medicine Code: ");
        scanf("%s", newMedicine.code);
        printf("Enter Quantity: ");
        scanf("%d", &newMedicine.quantity);
        printf("Enter Price: ");
        scanf("%f", &newMedicine.price);
        
        inventory[numMedicines++] = newMedicine;
        printf("Medicine added successfully!\n");
    } else {
        printf("Inventory full! Cannot add more medicines.\n");
    }
}

void displayMedicines() {
    if (numMedicines == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }

    printf("\nAvailable Medicines:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Medicine Name", "Code", "Quantity", "Price");
    for (int i = 0; i < numMedicines; i++) {
        printf("%-20s %-10s %-10d %-10.2f\n", inventory[i].name, inventory[i].code, inventory[i].quantity, inventory[i].price);
    }
}

void deleteMedicine() {
    char code[CODE_LEN];
    printf("Enter Medicine Code to delete: ");
    scanf("%s", code);
    
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            for (int j = i; j < numMedicines - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            numMedicines--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void updateMedicine() {
    char code[CODE_LEN];
    printf("Enter Medicine Code to update: ");
    scanf("%s", code);
    
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Updating Medicine: %s\n", inventory[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void searchMedicine() {
    char code[CODE_LEN];
    printf("Enter Medicine Code to search: ");
    scanf("%s", code);

    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(inventory[i].code, code) == 0) {
            printf("Medicine found: %s, Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void showMenu() {
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("===========================================\n");
}

int main() {
    int choice;
    
    do {
        showMenu();
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
                searchMedicine();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
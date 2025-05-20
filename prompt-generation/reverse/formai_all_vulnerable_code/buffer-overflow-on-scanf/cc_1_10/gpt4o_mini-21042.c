//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: lively
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

Medicine inventory[MAX_MEDICINES];
int medCount = 0;

void addMedicine() {
    if (medCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine newMed;
    printf("Enter medicine name: ");
    getchar();  // To consume newline left by previous input
    fgets(newMed.name, NAME_LENGTH, stdin);
    newMed.name[strcspn(newMed.name, "\n")] = 0;  // Remove newline

    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);
    
    printf("Enter price: ");
    scanf("%f", &newMed.price);
    
    inventory[medCount++] = newMed;
    printf("Medicine %s added to the inventory!\n", newMed.name);
}

void displayInventory() {
    if (medCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    printf("\n--- Inventory ---\n");
    for (int i = 0; i < medCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n",
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------\n");
}

void sellMedicine() {
    char medName[NAME_LENGTH];
    int sellQty;

    printf("Enter medicine name to sell: ");
    getchar();
    fgets(medName, NAME_LENGTH, stdin);
    medName[strcspn(medName, "\n")] = 0;  // Remove newline

    printf("Enter quantity to sell: ");
    scanf("%d", &sellQty);

    for (int i = 0; i < medCount; i++) {
        if (strcmp(inventory[i].name, medName) == 0) {
            if (inventory[i].quantity >= sellQty) {
                inventory[i].quantity -= sellQty;
                printf("Sold %d units of %s\n", sellQty, medName);
                return;
            } else {
                printf("Insufficient stock! Only %d units available.\n", inventory[i].quantity);
                return;
            }
        }
    }
    
    printf("Medicine %s not found in inventory.\n", medName);
}

void removeMedicine() {
    char medName[NAME_LENGTH];
    
    printf("Enter medicine name to remove: ");
    getchar();
    fgets(medName, NAME_LENGTH, stdin);
    medName[strcspn(medName, "\n")] = 0;  // Remove newline
    
    for (int i = 0; i < medCount; i++) {
        if (strcmp(inventory[i].name, medName) == 0) {
            for (int j = i; j < medCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medCount--;
            printf("Medicine %s removed from inventory.\n", medName);
            return;
        }
    }
    
    printf("Medicine %s not found in inventory.\n", medName);
}

void menu() {
    int choice;
    do {
        printf("\n=== Medical Store Management System ===\n");
        printf("1. Add Medicine\n");
        printf("2. Display Inventory\n");
        printf("3. Sell Medicine\n");
        printf("4. Remove Medicine\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                removeMedicine();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
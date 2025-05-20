//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Drug;

Drug inventory[MAX_DRUGS];
int drugCount = 0;

void addDrug() {
    if (drugCount >= MAX_DRUGS) {
        printf("Inventory full! Cannot add more drugs.\n");
        return;
    }
    Drug newDrug;
    printf("Enter drug ID: ");
    scanf("%d", &newDrug.id);
    printf("Enter drug name: ");
    scanf("%s", newDrug.name);
    printf("Enter quantity: ");
    scanf("%d", &newDrug.quantity);
    printf("Enter price: ");
    scanf("%f", &newDrug.price);
    
    inventory[drugCount++] = newDrug;
    printf("Drug added successfully!\n");
}

void removeDrug() {
    int id, i, found = 0;
    printf("Enter drug ID to remove: ");
    scanf("%d", &id);
    
    for (i = 0; i < drugCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < drugCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            drugCount--;
            printf("Drug removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Drug with ID %d not found!\n", id);
    }
}

void viewDrugs() {
    if (drugCount == 0) {
        printf("No drugs in inventory.\n");
        return;
    }
    
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < drugCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void editDrug() {
    int id, i, found = 0;
    printf("Enter drug ID to edit: ");
    scanf("%d", &id);
    
    for (i = 0; i < drugCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Editing drug ID %d\n", id);
            printf("Enter new name: ");
            scanf("%s", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Drug details updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Drug with ID %d not found!\n", id);
    }
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Drug\n");
    printf("2. Remove Drug\n");
    printf("3. View Drugs\n");
    printf("4. Edit Drug\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDrug();
                break;
            case 2:
                removeDrug();
                break;
            case 3:
                viewDrugs();
                break;
            case 4:
                editDrug();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
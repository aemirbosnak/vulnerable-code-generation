//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LEN 50
#define CODE_LEN 10

typedef struct {
    char name[NAME_LEN];
    char code[CODE_LEN];
    int quantity;
    float price;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    
    Medicine new_medicine;
    printf("Enter Medicine Name: ");
    scanf("%s", new_medicine.name);
    printf("Enter Medicine Code: ");
    scanf("%s", new_medicine.code);
    printf("Enter Quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter Price: ");
    scanf("%f", &new_medicine.price);

    inventory[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicine_count == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }
    
    printf("\nCurrent Medicines in Inventory:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Code", "Quantity", "Price");
    for (int i = 0; i < medicine_count; i++) {
        printf("%-20s %-10s %-10d $%-9.2f\n", inventory[i].name, inventory[i].code,
               inventory[i].quantity, inventory[i].price);
    }
}

void searchMedicine() {
    char search_code[CODE_LEN];
    printf("Enter Medicine Code to search: ");
    scanf("%s", search_code);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].code, search_code) == 0) {
            printf("Medicine found: %s, Code: %s, Quantity: %d, Price: $%.2f\n",
                   inventory[i].name, inventory[i].code, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    
    printf("Medicine with code %s not found.\n", search_code);
}

void deleteMedicine() {
    char delete_code[CODE_LEN];
    printf("Enter Medicine Code to delete: ");
    scanf("%s", delete_code);

    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].code, delete_code) == 0) {
            for (int j = i; j < medicine_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicine_count--;
            printf("Medicine with code %s has been deleted from the inventory.\n", delete_code);
            return;
        }
    }
    
    printf("Medicine with code %s not found.\n", delete_code);
}

void displayMenu() {
    printf("\n---- Medical Store Management System ----\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("------------------------------------------\n");
    printf("Select an option: ");
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
                searchMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Medicine inventory[MAX];
int count = 0;

void addMedicine() {
    if (count >= MAX) {
        printf("Inventory is full!\n");
        return;
    }
    printf("Enter Medicine ID: ");
    scanf("%d", &inventory[count].id);
    printf("Enter Medicine Name: ");
    scanf("%s", inventory[count].name);
    printf("Enter Quantity: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter Price: ");
    scanf("%f", &inventory[count].price);
    count++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    printf("\nInventory List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    if(count == 0) {
        printf("No medicines in inventory.\n");
    }
}

void searchMedicine() {
    int id, found = 0;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Medicine Found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

void deleteMedicine() {
    int id, found = 0;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("Medicine deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: deleteMedicine(); break;
            case 5: 
                printf("Exiting...\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
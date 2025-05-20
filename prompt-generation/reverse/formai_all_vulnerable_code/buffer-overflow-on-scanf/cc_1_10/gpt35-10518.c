//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int quantity;
    float price;
} Medicine;

// Function to add a medicine to the inventory
void add_medicine(Medicine inventory[], int *inventory_size) {
    Medicine m;
    printf("Enter name of medicine: ");
    scanf("%s", m.name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &m.quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &m.price);
    inventory[*inventory_size] = m;
    *inventory_size = *inventory_size + 1;
    printf("Medicine added successfully!\n");
}

// Function to remove a medicine from the inventory
void remove_medicine(Medicine inventory[], int *inventory_size) {
    char name[30];
    printf("Enter name of medicine to remove: ");
    scanf("%s", name);
    int i, j, found = 0;
    for (i = 0; i < *inventory_size; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = i; j < *inventory_size - 1; j++) {
            inventory[j] = inventory[j + 1];
        }
        *inventory_size = *inventory_size - 1;
        printf("Medicine removed successfully!\n");
    } else {
        printf("Medicine not found!\n");
    }
}

// Function to display the inventory
void display_inventory(Medicine inventory[], int inventory_size) {
    if (inventory_size == 0) {
        printf("Inventory is empty!\n");
    } else {
        printf("Name\t\tQuantity\tPrice\n");
        int i;
        for (i = 0; i < inventory_size; i++) {
            printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

int main() {
    Medicine inventory[100];
    int inventory_size = 0, choice;
    do {
        printf("Enter 1 to add a medicine to the inventory\n");
        printf("Enter 2 to remove a medicine from the inventory\n");
        printf("Enter 3 to display the inventory\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(inventory, &inventory_size);
                break;
            case 2:
                remove_medicine(inventory, &inventory_size);
                break;
            case 3:
                display_inventory(inventory, inventory_size);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
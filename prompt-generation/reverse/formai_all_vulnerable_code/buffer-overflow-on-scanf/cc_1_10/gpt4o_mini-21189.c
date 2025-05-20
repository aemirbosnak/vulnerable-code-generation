//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold medicine information
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Maximum number of medicines
#define MAX_MEDICINES 100

struct Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

// Function to add a medicine to the inventory
void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory full. Cannot add more medicines!\n");
        return;
    }
    
    struct Medicine new_medicine;
    printf("Enter Medicine ID: ");
    scanf("%d", &new_medicine.id);
    printf("Enter Medicine Name: ");
    scanf(" %[^\n]%*c", new_medicine.name);
    printf("Enter Medicine Price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &new_medicine.quantity);
    
    inventory[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

// Function to view the inventory
void view_inventory() {
    if (medicine_count == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }
    
    printf("Current Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", 
                inventory[i].id,
                inventory[i].name,
                inventory[i].price,
                inventory[i].quantity);
    }
}

// Function to remove a medicine from the inventory
void remove_medicine() {
    int id;
    printf("Enter Medicine ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicine_count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < medicine_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            medicine_count--;
            printf("Medicine removed successfully!\n");
            return;
        }
    }
    printf("Medicine ID not found!\n");
}

// Function to display menu options
void display_menu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Inventory\n");
    printf("3. Remove Medicine\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

// Main function
int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                remove_medicine();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
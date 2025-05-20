//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} medicine;

// Function to display the menu and get the user's choice
int getChoice() {
    int choice;
    printf("\n\nMedical Store Management System\n");
    printf("------------------------------------\n");
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine\n");
    printf("4. Update the quantity of a medicine\n");
    printf("5. Delete a medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *count) {
    printf("Enter the name of the medicine: ");
    scanf(" %[^\n]%*c", inventory[*count].name);
    printf("Enter the manufacturer of the medicine: ");
    scanf(" %[^\n]%*c", inventory[*count].manufacturer);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*count].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*count].quantity);
    (*count)++;
}

// Function to display all the medicines in the inventory
void displayInventory(medicine *inventory, int count) {
    printf("\n\nMedicine Inventory\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-20s | %-10s | %-10s |\n", "ID", "Name", "Manufacturer", "Price", "Quantity");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-5d | %-20s | %-20s | %-10.2f | %-10d |\n", i + 1, inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
}

// Function to search for a medicine in the inventory
void searchMedicine(medicine *inventory, int count) {
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf(" %[^\n]%*c", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Manufacturer: %s\n", inventory[i].manufacturer);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Function to update the quantity of a medicine in the inventory
void updateQuantity(medicine *inventory, int count) {
    char name[50];
    int quantity;
    printf("Enter the name of the medicine you want to update the quantity of: ");
    scanf(" %[^\n]%*c", name);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Function to delete a medicine from the inventory
void deleteMedicine(medicine *inventory, int *count) {
    char name[50];
    printf("Enter the name of the medicine you want to delete: ");
    scanf(" %[^\n]%*c", name);
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

// Main function
int main() {
    // Initialize the inventory with a maximum capacity of 100 medicines
    medicine inventory[100];
    int count = 0;
    
    int choice;
    do {
        choice = getChoice();
        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                searchMedicine(inventory, count);
                break;
            case 4:
                updateQuantity(inventory, count);
                break;
            case 5:
                deleteMedicine(inventory, &count);
                break;
            case 6:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
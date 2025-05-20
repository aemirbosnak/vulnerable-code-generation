//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

// Structure to store medicine information
struct Medicine {
    char name[50];
    char category[20];
    int quantity;
    float price;
};

// Function to print menu and get user choice
int showMenu() {
    int choice;
    printf("\n\n------ Medical Store Management System ------\n");
    printf("1. Add a new medicine\n");
    printf("2. Search for a medicine\n");
    printf("3. Show all medicines\n");
    printf("4. Sell a medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new medicine to the inventory
void addMedicine(struct Medicine inventory[], int *count) {
    if (*count == MAX_MEDICINES) {
        printf("\nInventory is full. Cannot add more medicines.\n");
        return;
    }
    struct Medicine newMedicine;
    printf("\nEnter details of new medicine:\n");
    printf("Name: ");
    scanf("%s", newMedicine.name);
    printf("Category: ");
    scanf("%s", newMedicine.category);
    printf("Quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Price: ");
    scanf("%f", &newMedicine.price);
    inventory[*count] = newMedicine;
    *count += 1;
    printf("\nNew medicine added to inventory.\n");
}

// Function to search for a medicine in the inventory
void searchMedicine(struct Medicine inventory[], int count) {
    char searchName[50];
    printf("\nEnter the name of medicine to search: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            found = 1;
            printf("\nMedicine found.\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Category: %s\n", inventory[i].category);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found.\n");
    }
}

// Function to display all the medicines in the inventory
void displayMedicines(struct Medicine inventory[], int count) {
    printf("\n---------- Inventory ----------\n");
    printf("Name\tCategory\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].category, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------------------\n");
}

// Function to sell a medicine
void sellMedicine(struct Medicine inventory[], int count) {
    char sellName[50];
    printf("\nEnter the name of medicine to sell: ");
    scanf("%s", sellName);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(sellName, inventory[i].name) == 0) {
            found = 1;
            int sellQuantity;
            printf("\nEnter the quantity to sell: ");
            scanf("%d", &sellQuantity);
            if (sellQuantity > inventory[i].quantity) {
                printf("\nNot enough medicines in stock.\n");
            } else {
                inventory[i].quantity -= sellQuantity;
                float totalPrice = sellQuantity * inventory[i].price;
                printf("\nSold %d units of %s for %.2f.\n", sellQuantity, inventory[i].name, totalPrice);
            }
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found.\n");
    }
}

int main() {
    struct Medicine inventory[MAX_MEDICINES];
    int count = 0;
    int choice = showMenu();
    while (choice != 5) {
        switch (choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                searchMedicine(inventory, count);
                break;
            case 3:
                displayMedicines(inventory, count);
                break;
            case 4:
                sellMedicine(inventory, count);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        choice = showMenu();
    }
    printf("\nThank you for using Medical Store Management System.\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
// C Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum capacity for inventory
#define MAX_INVENTORY_CAPACITY 1000

// Structure definition for medicine
struct Medicine
{
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

// Global variables
struct Medicine inventory[MAX_INVENTORY_CAPACITY];
int totalMedicines = 0;

// Function to display menu
void displayMenu()
{
    printf("\n\nMedical Store Management System\n\n");
    printf("1. Add Medicine\n");
    printf("2. Sell Medicine\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to add medicine to inventory
void addMedicine()
{
    if (totalMedicines == MAX_INVENTORY_CAPACITY)
    {
        printf("\n\nInventory is full!\n\n");
        return;
    }

    struct Medicine medicine;

    printf("\n\nEnter Medicine Details:\n");
    printf("Name: ");
    scanf("%s", medicine.name);

    printf("Manufacturer: ");
    scanf("%s", medicine.manufacturer);

    printf("Price: ");
    scanf("%f", &medicine.price);

    printf("Quantity: ");
    scanf("%d", &medicine.quantity);

    inventory[totalMedicines++] = medicine;

    printf("\n\nMedicine added to inventory!\n\n");
}

// Function to sell medicine from inventory
void sellMedicine()
{
    char name[50];
    printf("\n\nEnter Medicine Name: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < totalMedicines; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            int quantity;
            printf("Enter Quantity: ");
            scanf("%d", &quantity);

            if (inventory[i].quantity < quantity)
            {
                printf("\n\nInsufficient Quantity!\n\n");
                return;
            }

            inventory[i].quantity -= quantity;
            printf("\n\nMedicine Sold Successfully!\n\n");
            return;
        }
    }

    printf("\n\nMedicine not found in inventory!\n\n");
}

// Function to display inventory
void displayInventory()
{
    if (totalMedicines == 0)
    {
        printf("\n\nInventory is empty!\n\n");
        return;
    }

    printf("\n\nMedicine Details:\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Price", "Quantity");

    int i;
    for (i = 0; i < totalMedicines; i++)
    {
        printf("%-20s %-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }

    printf("\n\n");
}

// Main function
int main()
{
    int choice;
    while (1)
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addMedicine();
                break;

            case 2:
                sellMedicine();
                break;

            case 3:
                displayInventory();
                break;

            case 4:
                exit(0);

            default:
                printf("\n\nInvalid choice!\n\n");
                break;
        }
    }

    return 0;
}
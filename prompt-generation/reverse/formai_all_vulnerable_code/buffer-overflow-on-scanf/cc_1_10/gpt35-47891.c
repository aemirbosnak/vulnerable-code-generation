//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a medicine to the inventory
void add_medicine(int *inventory, int size)
{
    char name[50];
    int quantity, price;

    printf("\nEnter name of medicine: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%d", &price);

    // Check if there is enough space to add the medicine
    if (size < 50)
    {
        // Add the medicine to the inventory
        inventory[size * 3] = size + 1;
        sprintf(&inventory[(size * 3) + 1], "%s", name);
        inventory[(size * 3) + 2] = quantity;
        inventory[(size * 3) + 3] = price;

        printf("Medicine added to inventory successfully!\n");
    }
    else
    {
        printf("The inventory is full. Cannot add medicine.\n");
    }
}

// Function to search for a medicine in the inventory
void search_medicine(int *inventory, int size)
{
    char name[50];
    printf("\nEnter name of medicine: ");
    scanf("%s", name);

    // Search for the medicine in the inventory
    for (int i = 0; i < size; i++)
    {
        if (strcmp(&inventory[(i * 3) + 1], name) == 0)
        {
            printf("Medicine found! Details:\n");
            printf("ID: %d\n", inventory[i * 3]);
            printf("Name: %s\n", &inventory[(i * 3) + 1]);
            printf("Quantity: %d\n", inventory[(i * 3) + 2]);
            printf("Price: %d\n", inventory[(i * 3) + 3]);
            return;
        }
    }

    printf("Medicine not found in inventory.\n");
}

// Function to remove a medicine from the inventory
void remove_medicine(int *inventory, int size)
{
    int id;
    printf("\nEnter ID of medicine: ");
    scanf("%d", &id);

    // Check if the medicine exists in the inventory
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (inventory[i * 3] == id)
        {
            found = 1;

            // Remove the medicine from the inventory
            for (int j = i; j < size - 1; j++)
            {
                inventory[j * 3] = inventory[(j + 1) * 3];
                sprintf(&inventory[(j * 3) + 1], "%s", &inventory[((j + 1) * 3) + 1]);
                inventory[(j * 3) + 2] = inventory[((j + 1) * 3) + 2];
                inventory[(j * 3) + 3] = inventory[((j + 1) * 3) + 3];
            }

            printf("Medicine removed from inventory successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Medicine not found in inventory.\n");
    }
}

// Function to print the inventory
void print_inventory(int *inventory, int size)
{
    printf("\nInventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%s\t\t%d\t\t%d\n", inventory[i * 3], &inventory[(i * 3) + 1], inventory[(i * 3) + 2], inventory[(i * 3) + 3]);
    }
}

int main()
{
    int inventory[150] = {0};
    int size = 0, choice;

    printf("Welcome to the Medical Store Management System!\n");

    do
    {
        printf("\nMenu:\n");
        printf("1. Add medicine to inventory\n");
        printf("2. Search for a medicine in inventory\n");
        printf("3. Remove medicine from inventory\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_medicine(inventory, size);
                size++;
                break;

            case 2:
                search_medicine(inventory, size);
                break;

            case 3:
                remove_medicine(inventory, size);
                size--;
                break;

            case 4:
                print_inventory(inventory, size);
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
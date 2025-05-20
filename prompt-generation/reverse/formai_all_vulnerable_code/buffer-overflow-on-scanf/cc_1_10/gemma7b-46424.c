//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
typedef struct Medicine
{
    char name[50];
    int quantity;
    float price;
} Medicine;

// Define the inventory management function
void inventory_management(Medicine *medicines, int size)
{
    // Display the inventory
    printf("Inventory:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s - %d - %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }

    // Update the inventory
    printf("Enter the name of the medicine you want to update:");
    char name[50];
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            found = 1;
            printf("Enter the new quantity:");
            int new_quantity;
            scanf("%d", &new_quantity);
            medicines[i].quantity = new_quantity;
        }
    }

    // If the medicine was not found, display an error message
    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

int main()
{
    // Create an array of medicines
    Medicine medicines[] = {
        {"Acetaminophen", 100, 5.0},
        {"Ibuprofen", 50, 6.0},
        {"Tylenol", 25, 7.0},
    };

    // Manage the inventory
    inventory_management(medicines, 3);

    return 0;
}
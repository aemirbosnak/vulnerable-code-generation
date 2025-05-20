//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a medicine item
typedef struct MedicineItem
{
    char name[20];
    int quantity;
    float price;
} MedicineItem;

// Create a function to add a medicine item to the store
void addItem(MedicineItem *item)
{
    printf("Enter the name of the medicine item: ");
    scanf("%s", item->name);

    printf("Enter the quantity of the medicine item: ");
    scanf("%d", &item->quantity);

    printf("Enter the price of the medicine item: ");
    scanf("%f", &item->price);
}

// Create a function to display all medicine items in the store
void displayItems(MedicineItem *items, int numItems)
{
    for (int i = 0; i < numItems; i++)
    {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Create a function to find a medicine item in the store
void findItem(MedicineItem *items, int numItems, char *name)
{
    for (int i = 0; i < numItems; i++)
    {
        if (strcmp(items[i].name, name) == 0)
        {
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

int main()
{
    // Create an array of medicine items
    MedicineItem items[10];

    // Initialize the number of items to 0
    int numItems = 0;

    // Add some medicine items to the store
    addItem(&items[numItems++]);
    addItem(&items[numItems++]);
    addItem(&items[numItems++]);

    // Display all medicine items in the store
    displayItems(items, numItems);

    // Find a medicine item in the store
    findItem(items, numItems, "Medicine A");

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medicine information
struct medicine
{
    char name[20];
    char dosage[20];
    int quantity;
    float price;
};

// Create a function to add a medicine to the store
void addMedicine(struct medicine *med)
{
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter medicine dosage: ");
    scanf("%s", med->dosage);

    printf("Enter medicine quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter medicine price: ");
    scanf("%f", &med->price);
}

// Create a function to display all medicines in the store
void displayMedicines(struct medicine *med)
{
    printf("List of medicines:\n");
    for (int i = 0; i < med->quantity; i++)
    {
        printf("%s - %s, Quantity: %d, Price: %.2f\n", med->name, med->dosage, med->quantity, med->price);
    }
}

// Create a function to search for a medicine in the store
void searchMedicine(struct medicine *med)
{
    char searchName[20];

    printf("Enter medicine name: ");
    scanf("%s", searchName);

    for (int i = 0; i < med->quantity; i++)
    {
        if (strcmp(searchName, med->name) == 0)
        {
            printf("Found medicine: %s - %s, Quantity: %d, Price: %.2f\n", med->name, med->dosage, med->quantity, med->price);
        }
    }
}

int main()
{
    struct medicine med;

    // Add a medicine to the store
    addMedicine(&med);

    // Display all medicines in the store
    displayMedicines(&med);

    // Search for a medicine in the store
    searchMedicine(&med);

    return 0;
}
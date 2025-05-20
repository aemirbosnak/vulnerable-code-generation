//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine
{
    char name[20];
    char dosage[20];
    char frequency[20];
    int quantity;
} Medicine;

// Define the function to add a medicine to the store
void addMedicine(Medicine *medicineList, int *medicineListSize)
{
    // Allocate memory for a new medicine
    medicineList = (Medicine *)realloc(medicineList, (*medicineListSize + 1) * sizeof(Medicine));

    // Get the medicine name, dosage, frequency, and quantity
    printf("Enter the medicine name: ");
    scanf("%s", medicineList[*medicineListSize].name);

    printf("Enter the dosage: ");
    scanf("%s", medicineList[*medicineListSize].dosage);

    printf("Enter the frequency: ");
    scanf("%s", medicineList[*medicineListSize].frequency);

    printf("Enter the quantity: ");
    scanf("%d", &medicineList[*medicineListSize].quantity);

    // Increment the medicine list size
    (*medicineListSize)++;
}

// Define the function to search for a medicine
void searchMedicine(Medicine *medicineList, int medicineListSize)
{
    // Get the medicine name
    printf("Enter the medicine name: ");
    char searchName[20];
    scanf("%s", searchName);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < medicineListSize; i++)
    {
        if (strcmp(medicineList[i].name, searchName) == 0)
        {
            // Print the medicine information
            printf("Name: %s\n", medicineList[i].name);
            printf("Dosage: %s\n", medicineList[i].dosage);
            printf("Frequency: %s\n", medicineList[i].frequency);
            printf("Quantity: %d\n", medicineList[i].quantity);
            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

// Define the function to update a medicine
void updateMedicine(Medicine *medicineList, int medicineListSize)
{
    // Get the medicine name
    printf("Enter the medicine name: ");
    char updateName[20];
    scanf("%s", updateName);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < medicineListSize; i++)
    {
        if (strcmp(medicineList[i].name, updateName) == 0)
        {
            // Get the new medicine information
            printf("Enter the new dosage: ");
            scanf("%s", medicineList[i].dosage);

            printf("Enter the new frequency: ");
            scanf("%s", medicineList[i].frequency);

            printf("Enter the new quantity: ");
            scanf("%d", &medicineList[i].quantity);

            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

int main()
{
    // Create a list of medicines
    Medicine *medicineList = NULL;
    int medicineListSize = 0;

    // Add some medicines to the store
    addMedicine(medicineList, &medicineListSize);
    addMedicine(medicineList, &medicineListSize);
    addMedicine(medicineList, &medicineListSize);

    // Search for a medicine
    searchMedicine(medicineList, medicineListSize);

    // Update a medicine
    updateMedicine(medicineList, medicineListSize);

    return 0;
}
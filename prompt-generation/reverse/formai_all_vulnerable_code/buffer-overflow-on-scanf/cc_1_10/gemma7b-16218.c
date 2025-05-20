//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medicine information
typedef struct Medicine
{
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

// Create an array of medicines
Medicine medicines[100];

// Function to add a medicine to the array
void addMedicine()
{
    // Get the medicine name, dosage, quantity, and price
    printf("Enter the medicine name: ");
    scanf("%s", medicines[0].name);

    printf("Enter the dosage: ");
    scanf("%s", medicines[0].dosage);

    printf("Enter the quantity: ");
    scanf("%d", &medicines[0].quantity);

    printf("Enter the price: ");
    scanf("%f", &medicines[0].price);

    // Increment the index of the array
    int i = 0;
    while (medicines[i].name[0] != '\0')
    {
        i++;
    }
    medicines[i] = medicines[0];
}

// Function to search for a medicine
void searchMedicine()
{
    // Get the medicine name
    char name[50];
    printf("Enter the medicine name: ");
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; medicines[i].name[0] != '\0'; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            // Print the medicine information
            printf("Name: %s\n", medicines[i].name);
            printf("Dosage: %s\n", medicines[i].dosage);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

// Function to update the quantity of a medicine
void updateQuantity()
{
    // Get the medicine name
    char name[50];
    printf("Enter the medicine name: ");
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; medicines[i].name[0] != '\0'; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            // Get the new quantity
            int newQuantity;
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);

            // Update the quantity of the medicine
            medicines[i].quantity = newQuantity;

            // Print the updated medicine information
            printf("Name: %s\n", medicines[i].name);
            printf("Dosage: %s\n", medicines[i].dosage);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

// Function to delete a medicine
void deleteMedicine()
{
    // Get the medicine name
    char name[50];
    printf("Enter the medicine name: ");
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; medicines[i].name[0] != '\0'; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            // Delete the medicine
            medicines[i] = medicines[i + 1];

            // Print the updated medicine list
            for (int j = 0; medicines[j].name[0] != '\0'; j++)
            {
                printf("Name: %s\n", medicines[j].name);
                printf("Dosage: %s\n", medicines[j].dosage);
                printf("Quantity: %d\n", medicines[j].quantity);
                printf("Price: %.2f\n", medicines[j].price);
            }
            found = 1;
        }
    }

    // If the medicine was not found, print an error message
    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

// Main function
int main()
{
    // Add a medicine
    addMedicine();

    // Search for a medicine
    searchMedicine();

    // Update the quantity of a medicine
    updateQuantity();

    // Delete a medicine
    deleteMedicine();

    return 0;
}
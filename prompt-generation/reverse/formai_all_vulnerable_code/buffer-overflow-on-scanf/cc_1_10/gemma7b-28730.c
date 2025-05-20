//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a medicine
typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
} Medicine;

// Define a function to add a medicine to the store
void addMedicine(Medicine *medicines, int *numMedics)
{
    // Allocate memory for a new medicine
    medicines = (Medicine *)realloc(medicines, (*numMedics + 1) * sizeof(Medicine));

    // Get the medicine name, quantity, and price
    printf("Enter the medicine name: ");
    scanf("%s", medicines[*numMedics].name);

    printf("Enter the medicine quantity: ");
    scanf("%d", &medicines[*numMedics].quantity);

    printf("Enter the medicine price: ");
    scanf("%f", &medicines[*numMedics].price);

    // Increment the number of medicines
    (*numMedics)++;
}

// Define a function to search for a medicine
void searchMedicine(Medicine *medicines, int numMedics)
{
    // Get the medicine name
    char name[20];
    printf("Enter the medicine name: ");
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedics; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            // Print the medicine details
            printf("Name: %s\n", medicines[i].name);
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

// Define a function to update the medicine quantity
void updateMedicineQuantity(Medicine *medicines, int numMedics)
{
    // Get the medicine name
    char name[20];
    printf("Enter the medicine name: ");
    scanf("%s", name);

    // Search for the medicine
    int found = 0;
    for (int i = 0; i < numMedics; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            // Get the new quantity
            int newQuantity;
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);

            // Update the medicine quantity
            medicines[i].quantity = newQuantity;

            // Print the updated medicine details
            printf("Name: %s\n", medicines[i].name);
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

int main()
{
    // Define an array of medicines
    Medicine *medicines = NULL;

    // Define the number of medicines
    int numMedics = 0;

    // Add some medicines to the store
    addMedicine(medicines, &numMedics);
    addMedicine(medicines, &numMedics);
    addMedicine(medicines, &numMedics);

    // Search for a medicine
    searchMedicine(medicines, numMedics);

    // Update the medicine quantity
    updateMedicineQuantity(medicines, numMedics);

    return 0;
}
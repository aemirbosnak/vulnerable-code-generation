//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

typedef struct medicine Medicine;

void addMedicine(Medicine* medArr, int size)
{
    printf("\nEnter the details of the medicine:\n");

    // Allow the user to enter the details of the new medicine
    printf("Name: ");
    scanf("%s", medArr[size].name);
    printf("Manufacturer: ");
    scanf("%s", medArr[size].manufacturer);
    printf("Quantity: ");
    scanf("%d", &medArr[size].quantity);
    printf("Price: ");
    scanf("%f", &medArr[size].price);

    printf("\nMedicine added successfully!\n");
}

void sellMedicine(Medicine* medArr, int size)
{
    char name[50];
    int quantity;

    printf("\nEnter the name of the medicine you want to sell: ");
    scanf("%s", name);

    // Find the medicine in the array
    for (int i = 0; i < size; i++)
    {
        if (strcmp(medArr[i].name, name) == 0)
        {
            printf("Enter the quantity to sell: ");
            scanf("%d", &quantity);

            if (medArr[i].quantity >= quantity) // Enough quantity available
            {
                medArr[i].quantity -= quantity;
                printf("\nMedicine sold successfully!\n");
                return;
            }
            else // Not enough quantity available
            {
                printf("\nSorry, only %d units of %s available.\n", medArr[i].quantity, medArr[i].name);
                return;
            }
        }
    }

    // Medicine not found
    printf("\nSorry, %s not found.\n", name);
}

int main()
{
    int size = 0;
    int choice;
    Medicine* medArr = (Medicine*)malloc(sizeof(Medicine));

    // Print the welcome message
    printf("Welcome to the Medical Store Management System!\n");

    do
    {
        // Print the menu
        printf("\nPlease choose an option:\n");
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Add medicine
                size++;
                medArr = (Medicine*)realloc(medArr, (size+1)*sizeof(Medicine));
                addMedicine(medArr, size);
                break;

            case 2:
                // Sell medicine
                sellMedicine(medArr, size);
                break;

            case 3:
                // Exit
                printf("\nThanks for using the Medical Store Management System!\n");
                break;

            default:
                // Invalid choice
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 3);

    free(medArr);
    return 0;
}
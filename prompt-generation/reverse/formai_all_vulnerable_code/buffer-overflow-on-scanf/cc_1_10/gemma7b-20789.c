//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct Medicine
{
    char name[20];
    int quantity;
    float price;
};

int main()
{
    struct Medicine medicines[100];
    int i = 0;
    int choice, quantity, found = 0;
    char name[20];

    // Create a loop to add medicines to the system
    while (i < 100)
    {
        printf("Enter the name of the medicine: ");
        scanf("%s", medicines[i].name);

        printf("Enter the quantity of the medicine: ");
        scanf("%d", &medicines[i].quantity);

        printf("Enter the price of the medicine: ");
        scanf("%f", &medicines[i].price);

        i++;
    }

    // Display the list of medicines
    printf("List of medicines:\n");
    for (i = 0; i < 100; i++)
    {
        printf("%s - %d - %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }

    // Search for a medicine
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);

    // Search for the medicine
    for (i = 0; i < 100; i++)
    {
        if (strcmp(name, medicines[i].name) == 0)
        {
            found = 1;
            printf("Found: %s - %d - %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
        }
    }

    // If the medicine was not found, display an error message
    if (found == 0)
    {
        printf("Medicine not found.\n");
    }

    // Exit the program
    return 0;
}
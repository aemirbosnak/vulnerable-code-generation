//Gemma-7B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_POtions 5

typedef struct Potion
{
    char name[50];
    int quantity;
    double potency;
} Potion;

Potion potions[MAX_POtions];

int main()
{

    // Potion Inventory Management System

    // Create a new potion
    Potion newPotion;
    newPotion.quantity = 10;
    strcpy(newPotion.name, "Healing Potion");
    newPotion.potency = 5.0;

    potions[0] = newPotion;

    // List all potions
    for (int i = 0; i < MAX_POtions; i++)
    {
        if (potions[i].quantity > 0)
        {
            printf("%s (%d) - Potency: %.2lf\n", potions[i].name, potions[i].quantity, potions[i].potency);
        }
    }

    // Drink a potion
    char potionName[50];
    printf("Enter the name of the potion you want to drink: ");
    scanf("%s", potionName);

    for (int i = 0; i < MAX_POtions; i++)
    {
        if (strcmp(potions[i].name, potionName) == 0)
        {
            if (potions[i].quantity > 0)
            {
                potions[i].quantity--;
                printf("You have consumed the %s.\n", potions[i].name);
            }
            else
            {
                printf("Error: The requested potion is out of stock.\n");
            }
        }
    }

    return 0;
}
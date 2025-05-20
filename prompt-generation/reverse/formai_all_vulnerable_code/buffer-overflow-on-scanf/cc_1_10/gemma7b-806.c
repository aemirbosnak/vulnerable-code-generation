//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("CLS");
    printf("You are standing in the Chemical Kingdom, my dear.\n");
    printf("Please select an element from the periodic table below:\n\n");

    // Print the periodic table
    printf("Group 1 ( alkali metals):\n");
    printf("Li | Na | K | Rb | Cs | Fr\n");

    printf("Group 2 ( alkaline earth metals):\n");
    printf("Be | Mg | Ca | Sr | Ba | Ra\n");

    printf("Group 17 ( halogens):\n");
    printf("F | Cl | Br | I | At\n");

    printf("Group 18 ( noble gases):\n");
    printf("He | Ne | Ar | Kr | Rn | Oganesson\n");

    // Get the user's choice
    char element;
    printf("Enter the symbol of the element you want: ");
    scanf("%c", &element);

    // Check if the element is valid
    if (element >= 'a' && element <= 'f')
    {
        printf("You have chosen %c, a noble alkali metal.\n", element);
    }
    else if (element >= 'A' && element <= 'F')
    {
        printf("You have chosen %c, an alkaline earth metal.\n", element);
    }
    else if (element >= 'F' && element <= 'I')
    {
        printf("You have chosen %c, a halogen.\n", element);
    }
    else if (element >= 'H' && element <= 'R')
    {
        printf("You have chosen %c, a noble gas.\n", element);
    }
    else
    {
        printf("Invalid element selection.\n");
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Quirky Periodic Table!\n");
    printf("Please select an element from the list below:\n");
    printf("1. Hydrogen\n");
    printf("2. Helium\n");
    printf("3. Lithium\n");
    printf("4. Sodium\n");
    printf("5. Potassium\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Element: Hydrogen\n");
            printf("Symbol: H\n");
            printf("Atomic Number: 1\n");
            printf("Atomic Mass: 1.00784\n");
            break;

        case 2:
            printf("Element: Helium\n");
            printf("Symbol: He\n");
            printf("Atomic Number: 2\n");
            printf("Atomic Mass: 4.002602\n");
            break;

        case 3:
            printf("Element: Lithium\n");
            printf("Symbol: Li\n");
            printf("Atomic Number: 3\n");
            printf("Atomic Mass: 6.93820\n");
            break;

        case 4:
            printf("Element: Sodium\n");
            printf("Symbol: Na\n");
            printf("Atomic Number: 11\n");
            printf("Atomic Mass: 22.989769\n");
            break;

        case 5:
            printf("Element: Potassium\n");
            printf("Symbol: K\n");
            printf("Atomic Number: 19\n");
            printf("Atomic Mass: 38.99432\n");
            break;

        default:
            printf("Invalid selection.\n");
    }

    printf("Thank you for exploring the Quirky Periodic Table!\n");
    return 0;
}
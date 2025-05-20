//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("------------------------\n");
    printf("Group 1 - Alkali Metals\n");
    printf("------------------------\n");
    printf("1. Lithium\n");
    printf("2. Sodium\n");
    printf("3. Potassium\n");
    printf("Group 2 - Alkaline Earth Metals\n");
    printf("------------------------\n");
    printf("4. Magnesium\n");
    printf("5. Calcium\n");
    printf("Group 17 - Halogens\n");
    printf("------------------------\n");
    printf("6. Fluorine\n");
    printf("7. Chlorine\n");
    printf("8. Bromine\n");
    printf("Group 18 - Noble Gases\n");
    printf("------------------------\n");
    printf("9. Argon\n");
    printf("10. Krypton\n");
    printf("11. Radon\n");
    printf("Please select a number from 1 to 11:\n");
    int number;
    scanf("%d", &number);

    switch (number)
    {
        case 1:
            printf("You selected Lithium!\n");
            break;
        case 2:
            printf("You selected Sodium!\n");
            break;
        case 3:
            printf("You selected Potassium!\n");
            break;
        case 4:
            printf("You selected Magnesium!\n");
            break;
        case 5:
            printf("You selected Calcium!\n");
            break;
        case 6:
            printf("You selected Fluorine!\n");
            break;
        case 7:
            printf("You selected Chlorine!\n");
            break;
        case 8:
            printf("You selected Bromine!\n");
            break;
        case 9:
            printf("You selected Argon!\n");
            break;
        case 10:
            printf("You selected Krypton!\n");
            break;
        case 11:
            printf("You selected Radon!\n");
            break;
        default:
            printf("Invalid input.\n");
    }

    system("pause");
    return 0;
}
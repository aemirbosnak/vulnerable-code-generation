//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

char elements[26][12] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium"};
int elementCount = 12;

int main()
{
    srand(time(0));
    int answer = rand() % elementCount;
    int choice;
    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("Which element is represented by the symbol '%c'?\n", elements[answer][0]);
    while (1)
    {
        printf("1. Hydrogen\n");
        printf("2. Helium\n");
        printf("3. Lithium\n");
        printf("4. Beryllium\n");
        printf("5. Boron\n");
        printf("6. Carbon\n");
        printf("7. Nitrogen\n");
        printf("8. Oxygen\n");
        printf("9. Fluorine\n");
        printf("10. Neon\n");
        printf("11. Sodium\n");
        printf("12. Magnesium\n");
        printf("Enter your choice (1-12): ");
        scanf("%d", &choice);
        if (choice == answer)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Sorry, that's incorrect.\n");
        }
        printf("Would you like to continue (Y/N)? ");
        char c;
        scanf("%c", &c);
        if (c!= 'Y' && c!= 'y')
        {
            break;
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}
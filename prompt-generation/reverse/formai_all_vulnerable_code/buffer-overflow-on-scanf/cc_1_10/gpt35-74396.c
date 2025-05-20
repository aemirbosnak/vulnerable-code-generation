//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char symbol[3];
    char name[21];
    double atomic_mass;
    int atomic_number;
    int group;
    int period;
} Element;

int main()
{
    Element periodic_table[] = {
        {"H", "Hydrogen", 1.008, 1, 1, 1},
        {"He", "Helium", 4.0026, 2, 18, 1},
        {"Li", "Lithium", 6.94, 3, 1, 2},
        {"Be", "Beryllium", 9.0122, 4, 2, 2},
        {"B", "Boron", 10.81, 5, 13, 2},
        {"C", "Carbon", 12.011, 6, 14, 2},
        {"N", "Nitrogen", 14.007, 7, 15, 2},
        {"O", "Oxygen", 15.999, 8, 16, 2},
        {"F", "Fluorine", 18.998, 9, 17, 2},
        {"Ne", "Neon", 20.18, 10, 18, 2},
        {"Na", "Sodium", 22.99, 11, 1, 3},
        {"Mg", "Magnesium", 24.31, 12, 2, 3},
        {"Al", "Aluminium", 26.98, 13, 13, 3},
        {"Si", "Silicon", 28.09, 14, 14, 3},
        {"P", "Phosphorus", 30.97, 15, 15, 3},
        {"S", "Sulfur", 32.07, 16, 16, 3},
        {"Cl", "Chlorine", 35.45, 17, 17, 3},
        {"Ar", "Argon", 39.95, 18, 18, 3}};

    int num_of_elements = sizeof(periodic_table) / sizeof(Element);

    printf("Welcome to the Periodic Table Quiz!\n\n");

    while (1) // infinite loop
    {
        printf("Please enter an atomic number (1-%d) or -1 to quit: ", periodic_table[num_of_elements - 1].atomic_number);
        int answer;
        scanf("%d", &answer);

        if (answer == -1) // quit
            break;

        int i;

        for (i = 0; i < num_of_elements; i++)
        {
            if (periodic_table[i].atomic_number == answer)
            {
                printf("\nCorrect! The element with atomic number %d is %s.\n\n", answer, periodic_table[i].name);
                break;
            }
        }

        if (i == num_of_elements) // incorrect answer
            printf("\nIncorrect. Please try again.\n\n");
    }

    printf("Thanks for playing!\n");

    return 0;
}
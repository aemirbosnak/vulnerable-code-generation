//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int i, j, k;
    int correctAns = 0, totalAns = 0;
    int elementsList[118] = {0};
    char elements[118][3] = {"H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne", "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca", "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int usedElements[10] = {0};
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will have to guess the symbol for 10 randomly chosen elements from the Periodic Table.\n");
    printf("Let's begin!\n\n");

    for(i = 0; i < 10; i++)
    {
        int index = rand() % 118;
        while(elementsList[index] == 1)
        {
            index = rand() % 118;
        }
        usedElements[i] = index;
        elementsList[index] = 1;

        printf("What is the symbol for element number %d?\n", i+1);
        printf("Enter your answer (case sensitive): ");
        char answer[3];
        scanf("%s", answer);

        if(elements[index][0] == answer[0] && elements[index][1] == answer[1])
        {
            printf("Correct!\n\n");
            correctAns++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s.\n\n", elements[index]);
        }
        totalAns++;
    }

    printf("You got %d out of %d answers correct.\n", correctAns, totalAns);
    printf("The elements you were tested on were:\n");

    for(j = 0; j < 10; j++)
    {
        printf("%s ", elements[usedElements[j]]);
    }

    return 0;
}
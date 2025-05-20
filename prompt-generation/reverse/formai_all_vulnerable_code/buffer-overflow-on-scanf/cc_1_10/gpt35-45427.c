//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("\n---------------------------------------------\n");
    printf("--- WELCOME TO THE PERIODIC TABLE QUIZ GAME ---\n");
    printf("---------------------------------------------\n\n");

    printf("Instructions:\n");
    printf("1. You will be given the atomic number of an element and you have to guess its symbol.\n");
    printf("2. You have to type the answer in capital letters.\n");
    printf("3. You have three attempts to guess the correct answer.\n\n");

    char* elements[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int attempts = 3, correct_answers = 0, incorrect_answers = 0;
    char answer[3];
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int random_number = rand() % 118;
        int attempts_left = attempts;
        printf("Question %d: What is the symbol of the element with atomic number %d?\n", i+1, random_number+1);
        while (attempts_left > 0) {
            printf("Attempt %d: ", attempts - attempts_left + 1);
            scanf("%s", answer);
            if (strcmp(answer, elements[random_number]) == 0) {
                printf("Correct!\n");
                correct_answers++;
                break;
            } else {
                printf("Incorrect. ");
                attempts_left--;
                if (attempts_left > 0) {
                    printf("Try again.\n");
                } else {
                    printf("The correct answer was %s.\n", elements[random_number]);
                    incorrect_answers++;
                }
            }
        }
    }
    printf("\nQuiz completed!\n");
    printf("Correct answers: %d\n", correct_answers);
    printf("Incorrect answers: %d\n", incorrect_answers);

    return 0;
}
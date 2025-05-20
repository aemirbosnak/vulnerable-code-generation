//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ELEMENTS 118

const char *elements[MAX_ELEMENTS] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                                      "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
                                      "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
                                      "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe",
                                      "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

char *random_element();

int main()
{
    srand(time(NULL));
    int num_questions, correct, score = 0;
    char answer;
    char *element;

    printf("Welcome to the Periodic Table Quiz\n");

    do {
        printf("How many questions do you want to be asked? (up to %d)\n", MAX_QUESTIONS);
        scanf("%d", &num_questions);
    } while (num_questions <= 0 || num_questions > MAX_QUESTIONS);

    printf("Let's begin! Answer the following questions:\n");

    for (int i = 1; i <= num_questions; i++) {
        element = random_element();
        char *options[MAX_OPTIONS];

        for (int j = 0; j < MAX_OPTIONS; j++) {
            options[j] = random_element();
        }

        // Randomize position of correct answer
        int pos = rand() % MAX_OPTIONS;
        options[pos] = element;

        printf("%d) What is the symbol for %s?\n", i, element);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%c) %s\n", 'A' + j, options[j]);
        }

        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %c", &answer);

        if (answer == 'A' + pos) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c) %s\n", 'A' + pos, element);
        }

        free(element);

        if (i != num_questions) {
            printf("\n");
        }
    }

    printf("End of quiz. You got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}

char * random_element() {
    return strdup(elements[rand() % MAX_ELEMENTS]);
}
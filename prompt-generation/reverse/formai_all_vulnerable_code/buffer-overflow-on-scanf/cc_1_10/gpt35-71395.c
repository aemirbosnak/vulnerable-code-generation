//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given range
int generate_random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {

    // Define the periodic table
    char periodic_table[118][3] = {
        "H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne", 
        "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
        "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
        "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
        "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };

    int score = 0;
    int total_questions = 10;
    int question_count = 1;

    printf("\nWelcome to the C Periodic Table Quiz!\n\n");
    printf("Guess the chemical symbol of the following elements:\n");

    while (question_count <= total_questions) {
        // Generate a random question
        int question_index = generate_random_number(0, 117);

        printf("\nQuestion %d:\n", question_count);
        printf("What is the chemical symbol of %s?\n", periodic_table[question_index]);

        char answer[2];
        scanf("%2s", answer);

        // Check if the answer is correct
        if (answer[0] == periodic_table[question_index][0] && answer[1] == periodic_table[question_index][1]) {
            printf("Congrats! You got it right.\n");
            score++;
        } else {
            printf("Ooops! You got it wrong. The correct answer is %s.\n", periodic_table[question_index]);
        }

        question_count++;
    }

    printf("\nYou answered %d out of %d questions correctly.\n", score, total_questions);

    return 0;
}
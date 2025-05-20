//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int question, answer, score = 0, total_questions = 30;
    char element[100], guess[100];

    // Declare the periodic table
    char periodic_table[][100] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
        "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu",
        "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
        "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag",
        "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba",
        "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
        "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",
        "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi",
        "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf",
        "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh",
        "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv",
        "Ts", "Og"
    };

    // Loop through the periodic table
    for (question = 0; question < total_questions; question++) {
        // Display the question
        printf("%s: ", periodic_table[question]);
        scanf("%s", element);

        // Validate the user's answer
        if (strlen(element) > 0) {
            // Check if the answer is correct
            if (strcmp(element, periodic_table[question]) == 0) {
                score++;
                printf("Correct!\n");
            } else {
                printf("Incorrect. The correct answer is: %s\n", periodic_table[question]);
            }
        } else {
            printf("Please enter a valid element.\n");
        }
    }

    // Display the final score
    printf("Your final score is: %d/%d (%d%%)\n", score, total_questions, (score * 100) / total_questions);

    return 0;
}
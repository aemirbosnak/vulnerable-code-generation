//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu() {
    printf("-----------------------------\n");
    printf("  Welcome to Periodic Table  \n");
    printf("-----------------------------\n\n");
    printf("Menu:\n");
    printf("1. Practice Quiz\n");
    printf("2. Challenge Quiz\n");
    printf("3. Exit\n");
}

void practiceQuiz() {
    printf("----- Practice Quiz -----\n\n");
    printf("Here are the first 10 elements of the periodic table: \n");
    printf("1. Hydrogen (H)\n");
    printf("2. Helium (He)\n");
    printf("3. Lithium (Li)\n");
    printf("4. Beryllium (Be)\n");
    printf("5. Boron (B)\n");
    printf("6. Carbon (C)\n");
    printf("7. Nitrogen (N)\n");
    printf("8. Oxygen (O)\n");
    printf("9. Fluorine (F)\n");
    printf("10. Neon (Ne)\n");
    printf("\n");

    printf("What is the chemical symbol for Hydrogen? ");
    char answer[2];
    scanf("%s", answer);

    if (strcmp(answer, "H") == 0) {
        printf("Correct! Good job!\n");
    } else {
        printf("Oops! That's incorrect. The right answer is H.\n");
    }

    printf("\n");
}

void challengeQuiz() {
    printf("----- Challenge Quiz -----\n\n");

    const char * chemical_symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn"};

    int score = 0;

    for (int i = 0; i < 10; i++) {
        int index = rand() % 86;

        printf("What is the chemical symbol for %s? ", chemical_symbols[index]);
        char answer[2];
        scanf("%s", answer);

        if (strcmp(answer, chemical_symbols[index]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Oops! That's incorrect. The right answer is %s.\n", chemical_symbols[index]);
        }

        printf("\n");
    }

    printf("Your score is %d out of 10. Good job!\n\n", score);
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                practiceQuiz();
                break;
            case 2:
                challengeQuiz();
                break;
            case 3:
                printf("Thanks for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 3);

    return 0;
}
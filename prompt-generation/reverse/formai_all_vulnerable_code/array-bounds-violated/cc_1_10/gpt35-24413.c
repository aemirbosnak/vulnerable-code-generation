//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the periodic table elements
    char *periodicTable[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
                             "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", 
                             "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", 
                             "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", 
                             "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", 
                             "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", 
                             "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", 
                             "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    // Define the correct answers
    char *correctAnswers[] = {"C", "Fe", "O", "Hg", "Na", "I", "Ba", "K", "Zr", "Ne"};

    // Define an array to store the indices of the questions that have been asked
    int askedQuestions[10];

    // Define variables to keep track of the score and the number of questions asked
    int score = 0;
    int numQuestionsAsked = 0;

    // Seed the random number generator for random question generation
    srand(time(NULL));

    // Print a welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked 10 questions about the elements of the periodic table.\n");
    printf("For each question, enter the symbol for the element.\n\n");

    // Ask 10 questions
    while (numQuestionsAsked < 10) {
        // Generate a random number between 0 and 118 (inclusive) to select an element from the periodic table
        int questionIndex;
        do {
            questionIndex = rand() % 119;
        } while (contains(askedQuestions, questionIndex, numQuestionsAsked));
        askedQuestions[numQuestionsAsked] = questionIndex;

        // Print the question and get the user's answer
        printf("Question %d: What is the symbol for %s?\n", numQuestionsAsked + 1, periodicTable[questionIndex]);
        char answer[3];
        scanf("%2s", answer);
        printf("\n");

        // Check the user's answer
        if (strcmp(answer, periodicTable[questionIndex]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", periodicTable[questionIndex]);
        }

        numQuestionsAsked++;
    }

    // Print the final score
    printf("Quiz complete! You scored %d out of 10.\n", score);

    // Print the correct answers
    printf("Correct answers:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, correctAnswers[i]);
    }

    return 0;
}

/*
 * checks if an array contains a specific value
 */
int contains(int arr[], int val, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return 1;
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118  // total number of elements in periodic table
#define MAX_QUESTIONS 10   // maximum number of questions in quiz

// function to generate a random question
int generate_question(int* element_numbers) {
    int random_question;
    // loop to generate a random number that hasn't been used before
    do {
        random_question = rand() % NUM_ELEMENTS;
    } while (element_numbers[random_question] == 1);
    // mark the generated question as used
    element_numbers[random_question] = 1;
    return random_question;
}

int main() {
    int scores[MAX_QUESTIONS] = {0};       // array to store scores for each question
    int element_numbers[NUM_ELEMENTS] = {0};  // array to keep track of used questions
    char* element_symbols[NUM_ELEMENTS] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};  // array to store element symbols
    int num_questions = 0;                  // number of questions asked



    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be asked %d questions. Good luck!\n\n", MAX_QUESTIONS);

    // loop to ask questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int random_question = generate_question(element_numbers);
        char question[50];
        sprintf(question, "What is the symbol for %s?", element_symbols[random_question]);
        printf("Question %d: %s ", i+1, question);
        char answer[3];
        scanf("%s", answer);
        if (strcmp(answer, element_symbols[random_question]) == 0) {
            printf("You are correct!\n\n");
            scores[i] = 1;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", element_symbols[random_question]);
        }
        num_questions++;
    }

    // calculate and display final score
    int final_score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        final_score += scores[i];
    }
    printf("You answered %d out of %d questions correctly.\n", final_score, num_questions);

    return 0;
}
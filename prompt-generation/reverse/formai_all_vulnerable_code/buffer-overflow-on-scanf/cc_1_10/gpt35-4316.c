//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWER_LENGTH 5

// Periodic table elements
char *elements[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
                       "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
                       "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                       "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
                       "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                       "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

// Struct for saving quiz questions
typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} QuizQuestion;

void clear_screen() {
    system("cls||clear");
}

void show_title() {
    printf("************************************\n");
    printf("***** Retro Periodic Table Quiz *****\n");
    printf("************************************\n\n");
}

void show_instruction() {
    printf("Answer the chemical symbol of the element.\n");
    printf("You will be given %d questions.\n\n", MAX_QUESTIONS);
}

void show_score(int correct, int total) {
    printf("\n\n************************************\n");
    printf("Your score: %d/%d\n", correct, total);
    printf("************************************\n");
}

void generate_questions(QuizQuestion quiz_questions[MAX_QUESTIONS]) {
    srand(time(NULL));
    int used_indices[118] = {0};
    int i = 0;
    while (i < MAX_QUESTIONS) {
        int index = rand() % 118;
        if (used_indices[index] == 0) {
            used_indices[index] = 1;
            QuizQuestion q;
            strcpy(q.question, elements[index]);
            printf("%d. What is the symbol of %s? ", i+1, elements[index]);
            scanf("%s", q.answer);
            quiz_questions[i] = q;
            i++;
        }
    }
}

void start_quiz() {
    QuizQuestion quiz_questions[MAX_QUESTIONS];
    generate_questions(quiz_questions);

    int correct = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        QuizQuestion q = quiz_questions[i];
        if (strcmp(q.answer, q.question) == 0) {
            correct++;
            printf("Correct! %s is %s.\n", q.question, q.answer);
        } else {
            printf("Incorrect! %s is %s.\n", q.question, q.answer);
        }
    }

    show_score(correct, MAX_QUESTIONS);
}

int main() {
    clear_screen();
    show_title();
    show_instruction();
    start_quiz();

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_questions = rand() % 6 + 4; // Generate a random number of questions between 4 and 6
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        int element_num = rand() % 118 + 1; // Generate a random element number between 1 and 118
        char element_name[20];
        char element_symbol[10];
        int atomic_num = rand() % 118 + 1; // Generate a random atomic number between 1 and 118

        if (atomic_num == 1) {
            strcpy(element_name, "Hydrogen");
            strcpy(element_symbol, "H");
        } else if (atomic_num == 6) {
            strcpy(element_name, "Carbon");
            strcpy(element_symbol, "C");
        } else if (atomic_num == 7) {
            strcpy(element_name, "Nitrogen");
            strcpy(element_symbol, "N");
        } else if (atomic_num == 8) {
            strcpy(element_name, "Oxygen");
            strcpy(element_symbol, "O");
        } else if (atomic_num == 16) {
            strcpy(element_name, "Sulfur");
            strcpy(element_symbol, "S");
        } else if (atomic_num == 17) {
            strcpy(element_name, "Chlorine");
            strcpy(element_symbol, "Cl");
        } else if (atomic_num == 79) {
            strcpy(element_name, "Gold");
            strcpy(element_symbol, "Au");
        } else if (atomic_num == 83) {
            strcpy(element_name, "Bismuth");
            strcpy(element_symbol, "Bi");
        } else {
            strcpy(element_name, "Unknown");
            strcpy(element_symbol, "???");
        }

        printf("Question %d: What is the name of the element with atomic number %d and symbol %s?\n", i+1, atomic_num, element_symbol);
        char user_answer[20];
        scanf("%s", user_answer);

        if (strcmp(user_answer, element_name) == 0) {
            score++;
        }
    }

    printf("You scored %d out of %d questions correct.\n", score, num_questions);

    return 0;
}
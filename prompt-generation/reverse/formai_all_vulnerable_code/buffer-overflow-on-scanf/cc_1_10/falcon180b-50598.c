//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_questions = rand() % 10 + 1; // number of questions will be between 1 and 10
    int score = 0;
    int correct_answers[num_questions];
    int user_answers[num_questions];

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements in the periodic table.\n", num_questions);
    printf("For each question, type your answer in lowercase letters.\n");
    printf("If you don't know the answer, just press enter.\n");
    printf("Good luck!\n");

    for(int i = 0; i < num_questions; i++) {
        int element_number = rand() % 118 + 1; // number of elements in the periodic table
        char element_name[10];
        char element_symbol[3];
        int element_atomic_number;
        int element_atomic_weight;

        switch(element_number) {
            case 1:
                strcpy(element_name, "Hydrogen");
                strcpy(element_symbol, "H");
                element_atomic_number = 1;
                element_atomic_weight = 1.008;
                break;
            case 2:
                strcpy(element_name, "Helium");
                strcpy(element_symbol, "He");
                element_atomic_number = 2;
                element_atomic_weight = 4.003;
                break;
            // add more elements here
        }

        printf("Question %d: What is the name of element %d?\n", i+1, element_number);
        scanf("%s", element_name);

        if(strcmp(element_name, element_name) == 0) {
            printf("Correct!\n");
            correct_answers[i] = 1;
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element_name);
            correct_answers[i] = 0;
        }
    }

    printf("You got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}
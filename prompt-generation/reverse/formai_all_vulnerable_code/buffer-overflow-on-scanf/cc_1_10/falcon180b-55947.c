//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int atomic_weight;
};

struct element elements[NUM_ELEMENTS] = {
    {"H", 'H', 1, 1.008},
    {"He", 'He', 2, 4.003},
    {"Li", 'L', 3, 6.941},
    {"Be", 'B', 4, 9.012},
    {"B", 'B', 5, 10.811},
    {"C", 'C', 6, 12.011},
    {"N", 'N', 7, 14.007},
    {"O", 'O', 8, 15.999},
    {"F", 'F', 9, 18.998},
    {"Ne", 'N', 10, 20.180}
};

int main() {
    srand(time(NULL));

    int score = 0;
    int questions_answered = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int element_index = rand() % NUM_ELEMENTS;
        struct element* current_element = &elements[element_index];

        char question[50];
        sprintf(question, "What is the symbol for the element with atomic number %d? ", current_element->atomic_number);

        char answer[4];
        strcpy(answer, current_element->symbol);

        char user_answer[4];
        printf("%s: ", question);
        scanf("%s", user_answer);

        if (strcmp(answer, user_answer) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", answer);
        }

        questions_answered++;
    }

    printf("You answered %d out of %d questions correctly.\n", score, NUM_QUESTIONS);

    return 0;
}
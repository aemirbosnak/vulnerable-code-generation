//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define QUESTIONS 10

typedef struct {
    char name[3];
    char symbol;
    int atomic_number;
    int group;
    int period;
} Element;

Element elements[NUM_ELEMENTS] = {
    {"H", 'H', 1, 1, 1},
    {"He", 'He', 2, 18, 1},
    {"Li", 'Li', 3, 1, 2},
    {"Be", 'Be', 4, 2, 2},
    {"B", 'B', 5, 13, 2},
    {"C", 'C', 6, 14, 2},
    {"N", 'N', 7, 15, 2},
    {"O", 'O', 8, 16, 2},
    {"F", 'F', 9, 17, 2},
    {"Ne", 'Ne', 10, 18, 2}
};

int main() {
    srand(time(NULL));
    int score = 0;
    int i, j, k;
    char answer[3];

    for (i = 0; i < QUESTIONS; i++) {
        int index = rand() % NUM_ELEMENTS;
        Element* element = &elements[index];

        printf("Question %d:\n", i + 1);
        printf("What is the symbol for element %d?\n", element->atomic_number);

        scanf(" %s", answer);

        if (strcmp(answer, element->symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", element->symbol);
        }

        printf("\n");
    }

    printf("Your final score is %d out of %d.\n", score, QUESTIONS);

    return 0;
}
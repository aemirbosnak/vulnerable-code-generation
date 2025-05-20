//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS 118
#define QUESTIONS 10
#define POINTS 1

struct element {
    char name[3];
    char symbol[3];
    int atomic_number;
    int group;
    int period;
};

struct element elements[ELEMENTS] = {
    {"H", "H", 1, 1, 1},
    {"He", "He", 2, 18, 1},
    {"Li", "Li", 3, 1, 2},
    {"Be", "Be", 4, 2, 2},
    {"B", "B", 5, 13, 2},
    {"C", "C", 6, 14, 2},
    {"N", "N", 7, 15, 2},
    {"O", "O", 8, 16, 2},
    {"F", "F", 9, 17, 2},
    {"Ne", "Ne", 10, 18, 2}
};

int main() {
    srand(time(NULL));
    int score = 0;
    int i, j, k;
    char answer[4];
    printf("Welcome to the Surrealist Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements.\n", QUESTIONS);
    printf("Each correct answer is worth %d point(s).\n", POINTS);
    for (i = 0; i < QUESTIONS; i++) {
        k = rand() % ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i + 1, elements[k].name);
        scanf("%s", answer);
        if (strcmp(answer, elements[k].symbol) == 0) {
            printf("Correct!\n");
            score += POINTS;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[k].symbol);
        }
    }
    printf("Your final score is %d out of %d.\n", score, QUESTIONS * POINTS);
    return 0;
}
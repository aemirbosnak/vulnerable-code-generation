//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    char category[20];
};

struct element elements[NUM_ELEMENTS] = {
    {"H", 'H', 1, "Nonmetal"},
    {"He", 'He', 2, "Noble gas"},
    {"Li", 'Li', 3, "Metal"},
    {"Be", 'Be', 4, "Metal"},
    {"B", 'B', 5, "Metalloid"},
    {"C", 'C', 6, "Nonmetal"},
    {"N", 'N', 7, "Nonmetal"},
    {"O", 'O', 8, "Nonmetal"},
    {"F", 'F', 9, "Nonmetal"},
    {"Ne", 'Ne', 10, "Noble gas"}
};

int main() {
    srand(time(NULL));

    int score = 0;
    int num_correct = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int index = rand() % NUM_ELEMENTS;
        struct element element = elements[index];

        char symbol[4];
        strcpy(symbol, element.symbol);

        printf("Question %d: What is the symbol for %s?\n", i + 1, element.name);
        char answer[4];
        scanf("%s", answer);

        if (strcmp(answer, symbol) == 0) {
            num_correct++;
            score++;
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", num_correct, NUM_QUESTIONS);

    return 0;
}
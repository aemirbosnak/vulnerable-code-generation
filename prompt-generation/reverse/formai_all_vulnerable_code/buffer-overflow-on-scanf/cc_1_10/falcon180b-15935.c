//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int group;
    int period;
};

struct element elements[NUM_ELEMENTS] = {
    {"H", "Hydrogen", 1, 1, 1},
    {"He", "Helium", 2, 18, 1},
    {"Li", "Lithium", 3, 1, 2},
    {"Be", "Beryllium", 4, 2, 2},
    {"B", "Boron", 5, 13, 2},
    {"C", "Carbon", 6, 14, 2},
    {"N", "Nitrogen", 7, 15, 2},
    {"O", "Oxygen", 8, 16, 2},
    {"F", "Fluorine", 9, 17, 2},
    {"Ne", "Neon", 10, 18, 2}
};

int main() {
    srand(time(0));
    int score = 0;
    int index;
    char input[4];

    printf("Welcome to the Periodic Table Quiz!\n\n");

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        index = rand() % NUM_ELEMENTS;
        printf("Question %d: What is the symbol for the element with atomic number %d?\n", i + 1, elements[index].atomic_number);
        scanf("%s", input);

        if (strcmp(input, elements[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }
    }

    printf("\nYour final score is %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}
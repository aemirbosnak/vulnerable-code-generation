//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

struct element {
    char symbol[3];
    char name[30];
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
    srand(time(NULL));
    int score = 0;
    int num_correct = 0;
    int num_incorrect = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int index = rand() % NUM_ELEMENTS;
        struct element element = elements[index];

        printf("Question %d: What is the symbol for the element with atomic number %d?\n", i + 1, element.atomic_number);
        char answer[4];
        scanf("%s", answer);

        if (strcmp(answer, element.symbol) == 0) {
            num_correct++;
            score++;
        } else {
            num_incorrect++;
        }
    }

    printf("You got %d out of %d correct.\n", num_correct, NUM_QUESTIONS);
    return 0;
}
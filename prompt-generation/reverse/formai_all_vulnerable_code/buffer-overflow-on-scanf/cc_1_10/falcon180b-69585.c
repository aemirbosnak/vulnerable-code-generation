//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS_COUNT 118
#define QUESTIONS_COUNT 10

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int group;
    int period;
};

struct element elements[ELEMENTS_COUNT] = {
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
    int questions_left = QUESTIONS_COUNT;

    printf("\nWelcome to the Cyberpunk Periodic Table Quiz!\n");
    printf("Answer %d questions correctly to prove your knowledge.\n", QUESTIONS_COUNT);

    while (questions_left > 0 && score < QUESTIONS_COUNT) {
        int index = rand() % ELEMENTS_COUNT;
        struct element* current_element = &elements[index];

        char question[64];
        sprintf(question, "What is the symbol for element #%d? ", current_element->atomic_number);

        char answer[4];
        scanf("%s", answer);

        if (strcmp(answer, current_element->symbol) == 0) {
            score++;
            printf("\nCorrect! ");
        } else {
            printf("\nIncorrect. The correct answer is %s. ", current_element->symbol);
        }

        questions_left--;
    }

    if (score >= QUESTIONS_COUNT) {
        printf("\nCongratulations! You've passed the Cyberpunk Periodic Table Quiz with flying colors!");
    } else {
        printf("\nSorry, you didn't pass the quiz this time. Better luck next time!");
    }

    return 0;
}
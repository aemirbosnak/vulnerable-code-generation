//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ELEMENTS_COUNT 10

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

const Element elements[ELEMENTS_COUNT] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10},
};

void printElement(Element element) {
    printf("Element: %s, Symbol: %s, Atomic Number: %d\n", element.name, element.symbol, element.atomicNumber);
}

int getRandomElementIndex(int max) {
    return rand() % max;
}

void playQuiz() {
    int score = 0;
    int totalQuestions = 5;

    printf("\nWelcome to the Periodic Table Quiz!\n\n");
    printf("You will be asked %d questions.\n", totalQuestions);

    for (int i = 0; i < totalQuestions; i++) {
        int index = getRandomElementIndex(ELEMENTS_COUNT);
        Element questionElement = elements[index];

        char answer[3];
        printf("Question %d: What is the symbol for %s? ", i + 1, questionElement.name);
        scanf("%s", answer);

        if (strcmp(answer, questionElement.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", questionElement.symbol);
        }
    }

    printf("\nQuiz completed! Your score: %d out of %d\n", score, totalQuestions);
}

int main() {
    srand(time(NULL)); // Initialize random seed
    playQuiz();
    return 0;
}
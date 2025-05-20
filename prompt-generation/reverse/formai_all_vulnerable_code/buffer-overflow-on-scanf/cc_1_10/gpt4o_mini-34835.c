//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ELEMENTS 10

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

Element elements[NUM_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void shuffleElements() {
    srand(time(0));
    for(int i = NUM_ELEMENTS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

void printWelcome() {
    printf("🎉 Welcome to the Periodic Table Quiz! 🎉\n");
    printf("Let's see how much you know about the elements! 🌟\n");
    printf("You will be given the atomic number, and you have to guess the element name. Good luck! 🍀\n");
}

void playQuiz() {
    int score = 0;

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("\nGuess the element name for atomic number %d: ", elements[i].atomicNumber);
        char answer[20];
        scanf("%s", answer);

        if (strcasecmp(answer, elements[i].name) == 0) {
            printf("🎉 Correct! The element is %s! 🌈\n", elements[i].name);
            score++;
        } else {
            printf("😢 Oops! The correct answer is %s.\n", elements[i].name);
        }
    }

    printf("\nYour total score is: %d out of %d! 🎊\n", score, NUM_ELEMENTS);
    printf("Thank you for playing the Periodic Table Quiz! 🤗\n");
}

int main() {
    printWelcome();
    shuffleElements();
    playQuiz();

    return 0;
}
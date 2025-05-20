//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct {
    char element[20];
    char symbol[3];
    char category[20];
} Element;

Element elements[MAX_QUESTIONS] = {
    {"Hydrogen", "H", "Non-metal"},
    {"Oxygen", "O", "Non-metal"},
    {"Carbon", "C", "Non-metal"},
    {"Iron", "Fe", "Metal"},
    {"Gold", "Au", "Metal"}
};

void displayIntroduction() {
    printf("In fair Verona, where we lay our scene, \n");
    printf("A quiz of elements shall reign supreme. \n");
    printf("Know ye the symbols and their mighty might, \n");
    printf("Test thy knowledge, let’s take flight! \n\n");
}

void askQuestion(int index) {
    printf("What is the symbol of %s? \n", elements[index].element);
}

int checkAnswer(int index, char *answer) {
    return strcmp(elements[index].symbol, answer) == 0;
}

void displayResult(int score) {
    printf("\nIn this quiz of elements, you did %s!\n", (score == MAX_QUESTIONS) ? "triumph" : "fall short");
    if (score == MAX_QUESTIONS) {
        printf("Like Romeo and Juliet, your love for science is absolute!\n");
    } else {
        printf("But like the Montagues and Capulets, perhaps we must fight harder for the knowledge of elements.\n");
    }
}

int main() {
    displayIntroduction();
    int score = 0;
    char answer[3];

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        askQuestion(i);
        printf("Your answer: ");
        scanf("%s", answer);

        if (checkAnswer(i, answer)) {
            printf("O joy! Thou art correct!\n");
            score++;
        } else {
            printf("Alas! The answer was %s. \n", elements[i].symbol);
        }
        printf("\n");
    }

    displayResult(score);
    return 0;
}
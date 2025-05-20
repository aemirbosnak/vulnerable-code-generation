//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTS_COUNT 118
#define MAX_QUESTIONS 10

typedef struct {
    char symbol[3];
    char name;
} Element;

Element elements[ELEMENTS_COUNT] = {{"H", 'Hydrogen'}, {"He", 'Helium'}, {"Li", 'Lithium'}, {"Be", 'Beryllium'}, {"B", 'Boron'}, {"C", 'Carbon'}, {"N", 'Nitrogen'}, {"O", 'Oxygen'}, {"F", 'Fluorine'}, {"Ne", 'Neon'}};

int main() {
    srand(time(NULL));
    int score = 0;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int numQuestions = rand() % MAX_QUESTIONS + 1;
        int correctAnswers = 0;

        printf("Welcome to the Periodic Table Quiz!\n");
        printf("How many questions would you like to answer? (1-%d) ", MAX_QUESTIONS);
        scanf("%d", &numQuestions);

        for (int i = 0; i < numQuestions; i++) {
            int index = rand() % ELEMENTS_COUNT;
            Element element = elements[index];

            printf("\nQuestion %d:\n", i + 1);
            printf("What is the symbol for %s? ", element.name);

            char answer[4];
            scanf("%s", answer);

            if (strcmp(answer, element.symbol) == 0) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", element.symbol);
            }
        }

        printf("\nYou got %d out of %d questions correct.\n", correctAnswers, numQuestions);
        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    return 0;
}
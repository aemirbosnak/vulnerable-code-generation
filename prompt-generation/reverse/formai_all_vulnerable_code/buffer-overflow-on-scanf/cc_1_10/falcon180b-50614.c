//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 50
#define NUM_QUESTIONS 10

struct Element {
    char name[MAX_ANSWER_LENGTH];
    char symbol[MAX_ANSWER_LENGTH];
    int atomicNumber;
    char description[MAX_QUESTION_LENGTH];
};

struct Question {
    char question[MAX_QUESTION_LENGTH];
    int answerIndex;
};

int main() {
    srand(time(NULL));

    struct Element elements[NUM_ELEMENTS];
    struct Question questions[NUM_QUESTIONS];

    // Fill elements array with data
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        elements[i].atomicNumber = i + 1;
        sprintf(elements[i].name, "Element %d", i + 1);
        sprintf(elements[i].symbol, "E%d", i + 1);
        sprintf(elements[i].description, "This is element %d", i + 1);
    }

    // Fill questions array with data
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        questions[i].answerIndex = rand() % NUM_ELEMENTS;
        sprintf(questions[i].question, "What is the symbol for element %d?", questions[i].answerIndex + 1);
    }

    // Ask questions and keep track of score
    int numCorrect = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer == questions[i].answerIndex + 1) {
            numCorrect++;
        }
    }

    // Print final score
    printf("You got %d out of %d questions correct.\n", numCorrect, NUM_QUESTIONS);

    return 0;
}
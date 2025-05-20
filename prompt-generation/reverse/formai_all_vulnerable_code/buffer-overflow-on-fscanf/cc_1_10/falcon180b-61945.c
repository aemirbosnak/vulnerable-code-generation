//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 100
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 3
#define MAX_ATOMIC_WEIGHT_LENGTH 6
#define MAX_ELEMENT_CATEGORY_LENGTH 20
#define MAX_PERIOD_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
    char atomicWeight[MAX_ATOMIC_WEIGHT_LENGTH];
    char elementCategory[MAX_ELEMENT_CATEGORY_LENGTH];
    int period;
} Element;

Element elements[MAX_ELEMENTS];

void loadElements() {
    FILE *file = fopen("elements.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open elements.csv\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s,%s,%d,%s,%s,%d\n", elements[count].name, elements[count].symbol, &elements[count].atomicNumber, elements[count].atomicWeight, elements[count].elementCategory, &elements[count].period) == 6) {
        count++;
    }

    fclose(file);
}

void askQuestion() {
    int correctAnswers = 0;
    int incorrectAnswers = 0;

    for (int i = 0; i < 10; i++) {
        int index = rand() % MAX_ELEMENTS;
        Element *element = &elements[index];

        char answer[MAX_NAME_LENGTH];
        printf("Question %d: What is the name of the element with the symbol '%s'?\n", i + 1, element->symbol);
        scanf(" %s", answer);

        if (strcmp(answer, element->name) == 0) {
            printf("Correct answer!\n");
            correctAnswers++;
        } else {
            printf("Incorrect answer. The correct answer is '%s'.\n", element->name);
            incorrectAnswers++;
        }
    }

    printf("You got %d out of 10 questions correct.\n", correctAnswers);
}

int main() {
    srand(time(NULL));

    loadElements();

    askQuestion();

    return 0;
}
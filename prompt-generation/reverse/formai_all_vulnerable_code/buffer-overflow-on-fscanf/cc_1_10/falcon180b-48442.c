//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 50
#define MAX_ELEMENT_SYMBOL_LENGTH 3
#define MAX_ELEMENT_ATOMIC_NUMBER_LENGTH 3
#define MAX_ELEMENT_ATOMIC_WEIGHT_LENGTH 5

struct Element {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
    char atomicNumber[MAX_ELEMENT_ATOMIC_NUMBER_LENGTH];
    char atomicWeight[MAX_ELEMENT_ATOMIC_WEIGHT_LENGTH];
};

void loadElements(struct Element elements[]) {
    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error loading elements file.\n");
        exit(1);
    }

    int i = 0;

    while (fscanf(file, "%s %s %s %s", elements[i].name, elements[i].symbol, elements[i].atomicNumber, elements[i].atomicWeight)!= EOF) {
        i++;
    }

    fclose(file);
}

void shuffleArray(struct Element elements[]) {
    srand(time(NULL));

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;

        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    int score = 0;

    loadElements(elements);
    shuffleArray(elements);

    printf("Welcome to the Periodic Table Quiz!\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("Question %d: ", i + 1);

        if (elements[i].name[0]!= '\0') {
            printf("What is the name of the element with symbol '%s'?\n", elements[i].symbol);
        } else {
            printf("What is the symbol of the element with atomic number '%s'?\n", elements[i].atomicNumber);
        }

        char answer[MAX_ELEMENT_SYMBOL_LENGTH];
        fgets(answer, MAX_ELEMENT_SYMBOL_LENGTH, stdin);

        if (strcmp(answer, elements[i].symbol) == 0) {
            score++;
        }
    }

    printf("You got %d out of %d correct.\n", score, MAX_ELEMENTS);

    return 0;
}
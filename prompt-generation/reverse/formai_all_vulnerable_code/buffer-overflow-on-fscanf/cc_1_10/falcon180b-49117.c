//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 3

struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
    int atomicWeight;
};

void readElements(struct Element* elements) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d", elements[count].name, elements[count].symbol, &elements[count].atomicNumber, &elements[count].atomicWeight) == 4 && count < MAX_ELEMENTS) {
        count++;
    }

    fclose(file);
}

void printElements(struct Element* elements) {
    printf("Name\tSymbol\tAtomic Number\tAtomic Weight\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%s\t%s\t%d\t%d\n", elements[i].name, elements[i].symbol, elements[i].atomicNumber, elements[i].atomicWeight);
        }
    }
}

void quiz(struct Element* elements) {
    char input[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomicNumber;
    int correctAnswers = 0;

    printf("Enter the number of questions you want to answer: ");
    int numQuestions;
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n", i + 1);

        int randIndex = rand() % MAX_ELEMENTS;
        strcpy(input, elements[randIndex].name);
        strcpy(symbol, elements[randIndex].symbol);
        atomicNumber = elements[randIndex].atomicNumber;

        printf("Name: %s\n", input);
        printf("Symbol: ");
        scanf("%s", symbol);
        printf("Atomic Number: ");
        scanf("%d", &atomicNumber);

        if (tolower(symbol[0]) == tolower(elements[randIndex].symbol[0]) && atomicNumber == elements[randIndex].atomicNumber) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %s with atomic number %d.\n", elements[randIndex].name, elements[randIndex].atomicNumber);
        }
    }

    printf("You got %d out of %d questions correct.\n", correctAnswers, numQuestions);
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    readElements(elements);
    printElements(elements);
    quiz(elements);

    return 0;
}
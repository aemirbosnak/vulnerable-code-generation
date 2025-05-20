//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char symbol[3];
    int atomicNum;
    char name[20];
    char category[20];
};

typedef struct Element Element;

const int numOfElements = 118;
Element elementsArray[118];

void printWelcomeMessage() {
    printf("Welcome to the periodic table quiz!\n");
    printf("You will be presented with the symbol or name of an element and you must provide the corresponding name or symbol respectively.\n");
    printf("The quiz consists of 10 questions. Let's get started!\n\n");
}

void loadElements() {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: file could not be opened.\n");
        exit(1);
    }
    int i = 0;
    char buffer[100];
    while (fgets(buffer, 100, fp)) {
        sscanf(buffer, "%s %d %[^\n]s", elementsArray[i].symbol, &elementsArray[i].atomicNum, elementsArray[i].name);
        if (i >= 0 && i <= 1) {
            strcpy(elementsArray[i].category, "Hydrogen");
        } else if (i >= 2 && i <= 9) {
            strcpy(elementsArray[i].category, "Alkali Metal");
        } else if (i >= 10 && i <= 17) {
            strcpy(elementsArray[i].category, "Alkaline Earth Metal");
        } else if (i >= 18 && i <= 35) {
            strcpy(elementsArray[i].category, "Transition Metal");
        } else if (i >= 36 && i <= 53) {
            strcpy(elementsArray[i].category, "Post-transition Metal");
        } else if (i >= 54 && i <= 85) {
            strcpy(elementsArray[i].category, "Metalloid");
        } else if (i >= 86 && i <= 117) {
            strcpy(elementsArray[i].category, "Nonmetal");
        }
        i++;
    }
    fclose(fp);
}

int getRndNumInRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void quiz() {
    int score = 0;
    char input[20];
    char correctAnswer[20];
    int usedElements[numOfElements];
    for (int i = 0; i < 10; i++) {
        int index = getRndNumInRange(0, numOfElements - 1);
        while (usedElements[index] == 1) {
            index = getRndNumInRange(0, numOfElements - 1);
        }
        usedElements[index] = 1;
        Element currentElem = elementsArray[index];
        int isSymbolQuestion = rand() % 2;
        if (isSymbolQuestion) {
            printf("%d. %s\n", i + 1, currentElem.name);
            scanf("%s", input);
            strcpy(correctAnswer, currentElem.symbol);
        } else {
            printf("%d. %s\n", i + 1, currentElem.symbol);
            scanf("%s", input);
            strcpy(correctAnswer, currentElem.name);
        }
        if (strcmp(input, correctAnswer) == 0) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", correctAnswer);
        }
    }
    printf("Your score is %d out of 10.\n", score);
}

int main() {
    srand(time(NULL));
    loadElements();
    printWelcomeMessage();
    quiz();
    return 0;
}
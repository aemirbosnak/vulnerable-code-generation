//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTS 20
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 3

typedef struct Element {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int atomicNumber;
} Element;

void initializeElements(Element elements[]) {
    // Adding some elements to the post-apocalyptic world.
    strcpy(elements[0].name, "Hydrogen");
    strcpy(elements[0].symbol, "H");
    elements[0].atomicNumber = 1;

    strcpy(elements[1].name, "Helium");
    strcpy(elements[1].symbol, "He");
    elements[1].atomicNumber = 2;

    strcpy(elements[2].name, "Carbon");
    strcpy(elements[2].symbol, "C");
    elements[2].atomicNumber = 6;

    strcpy(elements[3].name, "Oxygen");
    strcpy(elements[3].symbol, "O");
    elements[3].atomicNumber = 8;

    strcpy(elements[4].name, "Iron");
    strcpy(elements[4].symbol, "Fe");
    elements[4].atomicNumber = 26;

    strcpy(elements[5].name, "Gold");
    strcpy(elements[5].symbol, "Au");
    elements[5].atomicNumber = 79;

    strcpy(elements[6].name, "Silver");
    strcpy(elements[6].symbol, "Ag");
    elements[6].atomicNumber = 47;

    strcpy(elements[7].name, "Uranium");
    strcpy(elements[7].symbol, "U");
    elements[7].atomicNumber = 92;
    
    // You can add more elements if needed, limited to MAX_ELEMENTS.
}

void quizUser(Element elements[], int numElements) {
    int score = 0;
    int totalQuestions = 5;
    int askedQuestions[totalQuestions];
    
    // Initializing the asked questions for the quiz
    for (int i = 0; i < totalQuestions; i++) {
        askedQuestions[i] = -1;
    }

    srand(time(NULL)); // Seed for randomness
    
    for (int i = 0; i < totalQuestions; i++) {
        int index;
        do {
            index = rand() % numElements;
        } while (askedQuestions[index] != -1);
        
        askedQuestions[i] = index;

        char answer[MAX_NAME_LEN];
        printf("Question %d: What is the symbol of %s? ", i + 1, elements[index].name);
        scanf("%s", answer);

        if (strcasecmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct symbol is %s.\n", elements[index].symbol);
        }
    }
    
    printf("You scored %d out of %d!\n", score, totalQuestions);
}

int main() {
    Element elements[MAX_ELEMENTS];
    initializeElements(elements);

    printf("Welcome to the Survival Element Quiz!\n");
    printf("In this post-apocalyptic world, knowing the elements can save your life.\n\n");

    quizUser(elements, 8); // Only 8 elements initialized
  
    printf("Thank you for participating! Remember, knowledge is power in this desolate world.\n");

    return 0;
}
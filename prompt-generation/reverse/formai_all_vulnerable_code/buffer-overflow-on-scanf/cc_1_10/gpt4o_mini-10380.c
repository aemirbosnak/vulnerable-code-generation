//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

typedef struct Element {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

void displayGreeting() {
    printf("Welcome, dear friend, to this noble quiz,\n");
    printf("On the elements that dwell 'neath the stars.\n");
    printf("Pray, art thou ready to test thy wisdom?\n");
    printf("For in this game, thine knowledge we shall spar.\n");
}

void presentQuestion(Element el, int questionNumber) {
    printf("\nQuestion %d:\nWhat is the symbol for %s?\n", questionNumber, el.name);
}

int checkAnswer(char *input, Element el) {
    return strcmp(input, el.symbol) == 0;
}

void offerReward() {
    printf("Thou hast proven thy worthiness in this quest!\n");
    printf("The elements shall bow to thy noble intellect!\n");
}

void displayFarewell() {
    printf("Alas! The curtain falls on this fair quiz,\n");
    printf("May knowledge reign in thine heart ever more.\n");
    printf("Farewell, dear scholar, till we meet again!\n");
}

int main() {
    Element elements[] = {
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

    int numQuestions = sizeof(elements) / sizeof(elements[0]);
    char answer[3];
    
    displayGreeting();
    
    for (int i = 0; i < numQuestions; i++) {
        presentQuestion(elements[i], i + 1);
        printf("Enter thy answer: ");
        scanf("%s", answer);
        
        if (checkAnswer(answer, elements[i])) {
            printf("Aye, thou art correct!\n");
        } else {
            printf("Alas, that is not the right symbol, dear friend!\n");
        }
    }
    
    offerReward();
    displayFarewell();

    return 0;
}
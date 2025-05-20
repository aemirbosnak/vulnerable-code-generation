//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

void initializePeriodicTable(Element table[]) {
    strcpy(table[0].name, "Hydrogen");
    strcpy(table[0].symbol, "H");
    table[0].atomicNumber = 1;

    strcpy(table[1].name, "Helium");
    strcpy(table[1].symbol, "He");
    table[1].atomicNumber = 2;

    strcpy(table[2].name, "Lithium");
    strcpy(table[2].symbol, "Li");
    table[2].atomicNumber = 3;

    strncpy(table[3].name, "Beryllium", 20);
    strncpy(table[3].symbol, "Be", 3);
    table[3].atomicNumber = 4;

    strcpy(table[4].name, "Boron");
    strcpy(table[4].symbol, "B");
    table[4].atomicNumber = 5;

    strcpy(table[5].name, "Carbon");
    strcpy(table[5].symbol, "C");
    table[5].atomicNumber = 6;

    strcpy(table[6].name, "Nitrogen");
    strcpy(table[6].symbol, "N");
    table[6].atomicNumber = 7;

    strcpy(table[7].name, "Oxygen");
    strcpy(table[7].symbol, "O");
    table[7].atomicNumber = 8;

    strcpy(table[8].name, "Fluorine");
    strcpy(table[8].symbol, "F");
    table[8].atomicNumber = 9;

    strcpy(table[9].name, "Neon");
    strcpy(table[9].symbol, "Ne");
    table[9].atomicNumber = 10;

    // Add more elements as needed
    for (int i = 10; i < 20; i++) {
        sprintf(table[i].name, "Element%d", i + 1);
        snprintf(table[i].symbol, sizeof(table[i].symbol), "E%d", i + 1);
        table[i].atomicNumber = i + 1;
    }
}

void displayQuiz(const Element table[], int size) {
    printf("Periodic Table Quiz\n");
    printf("====================\n");
    printf("Guess the symbol for the following elements:\n");
    
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", table[i].atomicNumber, table[i].name);
    }
}

void playQuiz(const Element table[], int size) {
    char answer[3];
    int score = 0;

    for (int i = 0; i < size; i++) {
        printf("What is the symbol for element %s (Atomic Number %d)? ", table[i].name, table[i].atomicNumber);
        scanf("%s", answer);

        if (strcasecmp(answer, table[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct symbol is %s.\n", table[i].symbol);
        }
    }

    printf("Your total score: %d/%d\n", score, size);
}

int main() {
    Element periodicTable[20];
    initializePeriodicTable(periodicTable);
    
    displayQuiz(periodicTable, 10);
    playQuiz(periodicTable, 10);

    return 0;
}
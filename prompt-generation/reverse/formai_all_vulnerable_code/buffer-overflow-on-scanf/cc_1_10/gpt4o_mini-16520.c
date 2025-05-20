//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[30];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
    char category[15];
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008, "Nonmetal"},
    {"Helium", "He", 2, 4.0026, "Noble Gas"},
    {"Lithium", "Li", 3, 6.94, "Alkali Metal"},
    {"Beryllium", "Be", 4, 9.0122, "Alkaline Earth Metal"},
    // ... filling this array is necessary for the quiz to function properly
    {"Oganesson", "Og", 118, 294, "Noble Gas"}
};

void initializePeriodicTable() {
    strcpy(periodicTable[0].name, "Hydrogen");
    strcpy(periodicTable[0].symbol, "H");
    periodicTable[0].atomicNumber = 1;
    periodicTable[0].atomicWeight = 1.008;
    strcpy(periodicTable[0].category, "Nonmetal");

    strcpy(periodicTable[1].name, "Helium");
    strcpy(periodicTable[1].symbol, "He");
    periodicTable[1].atomicNumber = 2;
    periodicTable[1].atomicWeight = 4.0026;
    strcpy(periodicTable[1].category, "Noble Gas");

    // Repeat for other elements
    // ...
}

void displayElement(int index) {
    printf("Element %d\n", index + 1);
    printf("Name: %s\n", periodicTable[index].name);
    printf("Symbol: %s\n", periodicTable[index].symbol);
    printf("Atomic Number: %d\n", periodicTable[index].atomicNumber);
    printf("Atomic Weight: %.2f\n", periodicTable[index].atomicWeight);
    printf("Category: %s\n", periodicTable[index].category);
}

void quizUser() {
    char answer[3];
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked a series of questions about chemical elements.\n");

    // Quiz questions based on some elements
    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d: What is the symbol for %s? ", i + 1, periodicTable[i].name);
        scanf("%s", answer);
        
        if (strcmp(answer, periodicTable[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", periodicTable[i].symbol);
        }
    }

    printf("\nYour total score is: %d out of 5\n", score);
    printf("Thank you for playing!\n");
}

int main() {
    initializePeriodicTable();
    quizUser();
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
    char category[MAX_NAME_LENGTH];
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.008, "Nonmetal"},
    {"Helium", "He", 2, 4.0026, "Noble gas"},
    {"Lithium", "Li", 3, 6.94, "Alkali metal"},
    {"Beryllium", "Be", 4, 9.0122, "Alkaline earth metal"},
    {"Boron", "B", 5, 10.81, "Metalloid"},
    {"Carbon", "C", 6, 12.011, "Nonmetal"},
    {"Nitrogen", "N", 7, 14.007, "Nonmetal"},
    {"Oxygen", "O", 8, 15.999, "Nonmetal"},
    {"Fluorine", "F", 9, 18.998, "Nonmetal"},
    {"Neon", "Ne", 10, 20.180, "Noble gas"},
    // ... Add more elements as needed ...
    {"Oganesson", "Og", 118, 294, "Noble gas"}
};

void displayElement(Element e) {
    printf("Element: %s\n", e.name);
    printf("Symbol: %s\n", e.symbol);
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Atomic Weight: %.3f\n", e.atomicWeight);
    printf("Category: %s\n\n", e.category);
}

void quizUser() {
    int score = 0;
    int totalQuestions = 5;
    char answer[3];
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions. Try to answer them correctly.\n\n", totalQuestions);

    for (int i = 0; i < totalQuestions; i++) {
        int index = rand() % MAX_ELEMENTS; // Random element
        Element e = periodicTable[index];

        printf("Question %d: What is the symbol for %s?\n", i + 1, e.name);
        printf("Your answer: ");
        scanf("%s", answer);
        if (strcmp(answer, e.symbol) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is: %s\n\n", e.symbol);
        }
    }

    printf("Quiz finished! You scored %d out of %d.\n", score, totalQuestions);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    
    // Peaceful introduction
    printf("🌍 Welcome to the Peaceful Periodic Table Quiz! 🌍\n");
    printf("Take a moment to breathe deeply and relax before we begin.\n\n");

    quizUser();

    printf("Thank you for participating! 🌈\n");
    printf("Remember, knowledge brings peace. Until next time! ☮️\n");
    
    return 0;
}
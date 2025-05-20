//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118
#define BUFFER_SIZE 256

typedef struct {
    char name[20];
    char symbol[3];
    int atomicNumber;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1}, {"Helium", "He", 2}, {"Lithium", "Li", 3},
    // ... fill in the rest of the elements
    {"Oganesson", "Og", 118}
};

void loadPeriodicTable() {
    // In a real program, you could load this data from a file.
}

int getAnswer(char *prompt) {
    int answer;
    printf("%s", prompt);
    
    // This paranoid checking tries to ensure user input is valid.
    while (1) {
        if (scanf("%d", &answer) != 1 || answer < 1 || answer > MAX_ELEMENTS) {
            printf("Invalid input! You can't trick me, please enter a number between 1 and %d: ", MAX_ELEMENTS);
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break; // Valid input
        }
    }
    
    while (getchar() != '\n'); // Clear the input buffer
    return answer;
}

void askQuestion() {
    int index = rand() % MAX_ELEMENTS; // Pick a random element
    Element e = periodicTable[index];
    
    // Paranoid logic: Repeating the question to catch any inconsistencies
    printf("What is the atomic number of %s (symbol: %s)? ", e.name, e.symbol);
    
    int answer = getAnswer("Your answer: ");
    if (answer == e.atomicNumber) {
        printf("Correct! You seem trustworthy. But were you just lucky?\n");
    } else {
        printf("Incorrect! Are you trying to deceive me? The correct answer is %d.\n", e.atomicNumber);
    }
}

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");
    
    loadPeriodicTable();
    
    while (1) {
        askQuestion();
        
        printf("Do you want to play again? (Yes=1/No=0): ");
        int playAgain = getAnswer("Your choice: ");
        if (playAgain == 0) {
            printf("I knew it! You might have been trying to distract me. Goodbye...\n");
            break;
        }
        
        printf("Just checking - you're not planning something, are you?\n");
    }

    return 0;
}
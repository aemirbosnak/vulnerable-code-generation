//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_QUESTIONS 5

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

Element periodicTable[] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10}
};

void shuffleQuestions(int *indices, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
}

void askQuestion(int index) {
    printf("Question: What is the name of the element with the symbol '%s'?\n", periodicTable[index].symbol);
}

int main() {
    srand(time(0)); // Seed the random number generator

    int indices[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        indices[i] = i; // Fill indices array with question indices
    }
    
    shuffleQuestions(indices, MAX_QUESTIONS); // Shuffle the questions

    int score = 0;
    char answer[20];
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        askQuestion(indices[i]);
        printf("Your answer: ");
        scanf("%s", answer);
        
        // Check the answer
        if (strcasecmp(answer, periodicTable[indices[i]].name) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is '%s'.\n\n", periodicTable[indices[i]].name);
        }
    }

    printf("Your final score: %d out of %d\n", score, MAX_QUESTIONS);
    
    if (score == MAX_QUESTIONS) {
        printf("Excellent! You're a chemistry master!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! Keep studying the periodic table!\n");
    } else {
        printf("Don't be discouraged! Keep learning the elements!\n");
    }

    return 0;
}
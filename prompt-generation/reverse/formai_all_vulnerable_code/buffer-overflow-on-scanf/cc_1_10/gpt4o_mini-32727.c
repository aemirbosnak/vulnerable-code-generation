//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ELEMENTS 10

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

Element elements[MAX_ELEMENTS] = {
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

void printWelcomeMessage() {
    printf("====================================\n");
    printf("    Welcome to the Periodic Table   \n");
    printf("           Quiz Challenge!          \n");
    printf("====================================\n\n");
    printf("You will be asked %d questions about\n", MAX_QUESTIONS);
    printf("the elements of the periodic table.\n");
    printf("Let's see how many you can get right!\n\n");
}

void askQuestion(int questionNumber) {
    int idx = rand() % MAX_ELEMENTS;
    printf("Question %d: What is the symbol for %s? ", questionNumber + 1, elements[idx].name);
}

int getUserAnswer() {
    char answer[3];
    scanf("%s", answer);
    return answer[0];
}

void evaluateAnswer(char correctAnswer, char userAnswer, int* score) {
    if (toupper(userAnswer) == toupper(correctAnswer)) {
        printf("Correct! 🎉\n\n");
        (*score)++;
    } else {
        printf("Wrong! The correct answer is: %c\n\n", correctAnswer);
    }
}

void printFinalScore(int score) {
    printf("====================================\n");
    printf("         Quiz Finished!            \n");
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);
    printf("Thanks for playing! 🥳\n");
    printf("====================================\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    
    printWelcomeMessage();
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        askQuestion(i);
        char userAnswer = getUserAnswer();
        evaluateAnswer(elements[i].symbol[0], userAnswer, &score);
    }

    printFinalScore(score);
    return 0;
}
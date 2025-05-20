//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 50
#define MAX_ATTEMPTS 5

int generateRandomNumber(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

void printInstructions() {
    printf("*** Typing Speed Test ***\n");
    printf("Type the word that appears on the screen as fast as possible.\n");
    printf("You have 5 attempts to score the highest.\n");
    printf("----------------------------------------\n");
}

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"future", "proof", "programming", "language", "algorithm", "data", "structure", "function", "variable", "memory", "pointer", "array", "iteration", "recursion", "code", "compile", "debug", "execute", "input", "output", "integer", "double", "float", "char", "string", "boolean", "operator", "conditional", "loop", "module", "header", "source", "library", "compiler", "interpreter", "linker", "main", "static", "dynamic", "global", "local", "parameter", "argument", "return", "void", "include", "define", "ifdef", "endif", "endif"};
    
    int score = 0, attempts = 0;
    char input[MAX_WORD_LENGTH];
    
    printInstructions();
    
    while (attempts < MAX_ATTEMPTS) {
        int randomIndex = generateRandomNumber(0, MAX_WORDS - 1);
        printf("Type the word: %s\n", words[randomIndex]);
        time_t startTime = time(NULL);
        scanf("%s", input);
        time_t endTime = time(NULL);
        
        double timeTaken = difftime(endTime, startTime);
        if (strcmp(input, words[randomIndex]) == 0) {
            printf("Correct! You took %.2lf seconds.\n", timeTaken);
            score++;
        } else {
            printf("Incorrect!\n");
        }
        
        attempts++;
    }
    
    printf("Your score is %d out of %d.\n", score, MAX_ATTEMPTS);
    
    if (score == MAX_ATTEMPTS) {
        printf("Amazing! You scored 100%%.\n");
    } else if (score >= (MAX_ATTEMPTS * 0.8)) {
        printf("Great job! You scored %d%%.\n", (int)(score * 100 / MAX_ATTEMPTS));
    } else if (score >= (MAX_ATTEMPTS * 0.6)) {
        printf("Good effort! You scored %d%%.\n", (int)(score * 100 / MAX_ATTEMPTS));
    } else {
        printf("Keep practicing! You scored %d%%.\n", (int)(score * 100 / MAX_ATTEMPTS));
    }
    
    return 0;
}
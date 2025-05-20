//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3

// Function to check if a given character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a given word is a valid English word
bool isValidWord(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isLetter(word[i])) {
            return false;
        }
    }
    return true;
}

// Function to generate a random word
char* generateRandomWord() {
    char* word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
    int i;
    for (i = 0; i < rand() % MAX_WORD_LENGTH + MIN_WORD_LENGTH; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[i] = '\0';
    return word;
}

// Function to print a random word and wait for the user to type it
void printRandomWord(char* word) {
    printf("Type the following word: %s\n", word);
    fflush(stdout);
    char input[MAX_WORD_LENGTH];
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(word, input)!= 0) {
        printf("Incorrect!\n");
    }
}

// Function to calculate the user's typing speed
void calculateTypingSpeed() {
    int correctWords = 0;
    int totalWords = 0;
    int startTime = time(NULL);
    while (totalWords < 10) {
        char* word = generateRandomWord();
        printRandomWord(word);
        if (strcmp(word, fgets(word, MAX_WORD_LENGTH, stdin)) == 0) {
            correctWords++;
        }
        totalWords++;
    }
    int endTime = time(NULL);
    int elapsedTime = endTime - startTime;
    float wordsPerMinute = (float) correctWords / (elapsedTime / 60.0);
    printf("Your typing speed is: %.2f words per minute\n", wordsPerMinute);
}

int main() {
    srand(time(NULL));
    calculateTypingSpeed();
    return 0;
}
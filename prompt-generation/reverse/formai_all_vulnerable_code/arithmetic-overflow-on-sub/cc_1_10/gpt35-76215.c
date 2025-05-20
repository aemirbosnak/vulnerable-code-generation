//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_WORDS 10
#define MAX_WORD_LEN 12
#define MAX_TIME 60
#define MIN_TIME 10

// Define function prototypes
void printIntro();
void printResults(float, int);
char randomChar();
char* generateWord();
int calculateWPM(int, int);

int main() {
    srand(time(NULL));
    printIntro();
    char inputChar, targetChar;
    int correctCount = 0, errorCount = 0, wordCount = 0;
    int timeLimit = rand() % MAX_TIME + MIN_TIME;
    time_t startTime = time(NULL);
    while (time(NULL) - startTime < timeLimit) {
        char *word = generateWord();
        printf("%s ", word);
        while (inputChar = getchar()) {
            targetChar = word[strlen(word) - 1];
            if (inputChar != targetChar) {
                errorCount++;
            } else {
                correctCount++;
            }
            if (inputChar == ' ') {
                wordCount++;
                break;
            }
        }
    }
    int totalTime = time(NULL) - startTime;
    int totalChars = correctCount + errorCount;
    int wpm = calculateWPM(totalChars, totalTime);
    float accuracy = ((float)correctCount / totalChars) * 100;
    printResults(accuracy, wpm);
    return 0;
}

// Prints introduction instructions
void printIntro() {
    printf("Welcome to the typing speed test!\n\n"
           "Type the random words that appear. Press spacebar to finish a word.\n"
           "You have between %d and %d seconds to type as many words as you can.\n\n",
           MIN_TIME, MAX_TIME);
}

// Prints test results
void printResults(float accuracy, int wpm) {
    printf("\n\nTest completed!\n\n"
           "Accuracy: %.2f%%\n"
           "Words per minute: %d\n\n", accuracy, wpm);
}

// Generates a random alphabet character
char randomChar() {
    const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    return alphabet[rand() % 26];
}

// Generates a random word
char* generateWord() {
    char* word = (char*) malloc(MAX_WORD_LEN + 1);
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        word[i] = randomChar();
    }
    word[MAX_WORD_LEN] = '\0';
    return word;
}

// Calculates words per minute
int calculateWPM(int totalChars, int totalTime) {
    float minutes = (float)totalTime / 60;
    float wpm = (float)totalChars / 5 / minutes;
    return (int)wpm;
}
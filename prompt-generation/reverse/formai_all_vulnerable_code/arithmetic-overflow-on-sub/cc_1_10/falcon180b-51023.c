//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function prototypes
void init(char *word);
int check(char c);
int main();

int main() {
    char word[100];
    int length, correct = 0, incorrect = 0;

    printf("Welcome to the Shape Shifting Typing Speed Test!\n");
    printf("Press Enter to begin...\n");
    getchar();

    // Get the length of the word
    length = rand() % 10 + 1;

    // Populate the word with random characters
    for (int i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }

    printf("The word is: %s\n", word);
    printf("Press Enter when ready to start...\n");
    getchar();

    // Start the timer
    clock_t start = clock();

    // Loop through the word and check each character
    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);
        if (isalpha(c)) {
            if (c == getchar()) {
                correct++;
            } else {
                incorrect++;
            }
        }
    }

    // Stop the timer
    clock_t end = clock();
    double elapsed_secs = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("You typed %d correct characters and %d incorrect characters.\n", correct, incorrect);
    printf("Your typing speed was %d characters per second.\n", (int)(length / elapsed_secs));

    return 0;
}

// Initializes the word with random characters
void init(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = rand() % 26 + 'a';
    }
}

// Checks if the character is a letter
int check(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}
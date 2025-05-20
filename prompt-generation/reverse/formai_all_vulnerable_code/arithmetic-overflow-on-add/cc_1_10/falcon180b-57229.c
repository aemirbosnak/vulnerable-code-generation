//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

// Function to get a random word
char* getRandomWord(char* words[], int numWords) {
    return words[rand() % numWords];
}

// Function to display a word and measure typing speed
void displayWord(char* word) {
    printf("Type the following word: %s\n", word);
    fflush(stdout);

    // Get the current time
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    // Wait for user input
    char input[MAX_WORD_LENGTH];
    scanf("%s", input);

    // Get the current time again
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate the time taken to type the word
    long int timeTaken = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);

    // Calculate the typing speed in words per minute
    float wpm = (float)timeTaken / (60.0 * strlen(word));

    // Display the typing speed
    printf("You typed %d characters in %d milliseconds, which is %f words per minute.\n", strlen(word), timeTaken, wpm);
}

int main() {
    // List of words to choose from
    char* words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

    // Get the number of words from the user
    int numWords;
    printf("How many words do you want to type? ");
    scanf("%d", &numWords);

    // Make sure the number of words is valid
    if (numWords < 1 || numWords > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    // Loop through the specified number of words
    for (int i = 0; i < numWords; i++) {
        // Display a random word and measure typing speed
        char* word = getRandomWord(words, numWords);
        displayWord(word);
    }

    return 0;
}
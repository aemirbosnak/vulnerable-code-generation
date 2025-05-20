//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to generate random words
void generateWord(char *word, int length) {
    int i;

    for (i = 0; i < length; i++) {
        int randomChar = 'a' + rand() % ('z' - 'a' + 1);
        word[i] = (char) randomChar;
    }
    word[length] = '\0';
}

int main() {
    // Initialization
    int totalWords = 10;
    int wordLength = 5;
    char word[wordLength + 1];
    int correctWords = 0;
    int incorrectWords = 0;
    int totalTime = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given 10 words to type. Each word is %d letters long.\n", wordLength);
    printf("Please type the words exactly as displayed and press enter after each word.\n");
    printf("Your time will be recorded and your accuracy will be calculated.\n");
    printf("Press enter to start the test.");
    getchar();

    // Generate the words and get user input
    for (int i = 0; i < totalWords; i++) {
        generateWord(word, wordLength);

        printf("%s\n", word);
        time_t start = time(NULL);
        char input[wordLength + 1];
        fgets(input, wordLength + 1, stdin);
        time_t end = time(NULL);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Calculate time and accuracy
        int timeTaken = (int) difftime(end, start);
        totalTime += timeTaken;

        if (strcmp(word, input) == 0) {
            printf("You typed the word correctly!\n");
            correctWords++;
        } else {
            printf("Sorry, that was incorrect\n");
            incorrectWords++;
        }
    }

    printf("\nTyping test results:\n");
    printf("Total time taken: %d seconds\n", totalTime);
    printf("Correct words: %d\n", correctWords);
    printf("Incorrect words: %d\n", incorrectWords);
    printf("Accuracy: %.2f%%\n", (float) correctWords / totalWords * 100);

    return 0;
}
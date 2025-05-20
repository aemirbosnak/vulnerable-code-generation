//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Introduction
    printf("Welcome to the C Typing Speed Test!\n");
    printf("Instructions:\n");
    printf("1. You will be given a random passage of text.\n");
    printf("2. Type the passage as accurately and quickly as possible.\n");
    printf("3. The test will end when you type \"stop\".\n");

    // Get the user's input
    char input[1000];
    printf("Enter your name: ");
    scanf("%s", input);
    printf("Enter your email address: ");
    scanf("%s", input);

    // Generate a random passage of text
    srand(time(NULL));
    int num_words = rand() % 100 + 100;
    char passage[num_words * 10];
    for (int i = 0; i < num_words; i++) {
        int num_letters = rand() % 10 + 5;
        for (int j = 0; j < num_letters; j++) {
            passage[i * 10 + j] = 'a' + rand() % 26;
        }
        passage[i * 10 + num_letters] = ' ';
    }

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    printf("Type the following passage as accurately and quickly as possible:\n");
    printf("%s", passage);
    scanf("%[^\n]%*c", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the user's typing speed
    int num_characters = strlen(input);
    double time_seconds = (double)(end - start) / CLOCKS_PER_SEC;
    double typing_speed = num_characters / time_seconds;

    // Display the results
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}
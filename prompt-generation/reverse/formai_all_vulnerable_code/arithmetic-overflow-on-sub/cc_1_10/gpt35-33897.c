//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 15
#define NUM_WORDS 10

int main()
{
    // Define variables
    char word_list[NUM_WORDS][MAX_WORD_LENGTH] = {"hello", "world", "programming", "challenge", "typing", "speed", "test", "code", "snippet", "example"};
    char input_word[MAX_WORD_LENGTH];
    int time_taken = 0;
    int correct_words = 0;
    clock_t start_time, end_time;

    // Display instruction
    printf("\nWelcome to the Typing Speed Test Program!\n\n");
    printf("You need to type as many words as you can in 30 seconds.\n");
    printf("Type the words exactly as they appear on the screen.\n");
    printf("Press enter after typing each word.\n\n");

    // Wait for user to start the test
    printf("Press enter to start the test...");
    getchar();

    // Start the timer
    start_time = clock();

    // Generate words and take input for 30 seconds
    for (int i = 0; i < NUM_WORDS && time_taken < 30; i++)
    {
        // Generate a random word
        srand(time(NULL));
        int random_index = rand() % NUM_WORDS;
        char current_word[MAX_WORD_LENGTH];
        strcpy(current_word, word_list[random_index]);

        // Display the word
        printf("%s ", current_word);

        // Take input from user
        fgets(input_word, MAX_WORD_LENGTH, stdin);

        // Calculate time_taken and correct_words
        if (strcasecmp(input_word, current_word) == 0)
        {
            correct_words++;
        }
        end_time = clock();
        time_taken = (int)(end_time - start_time) / CLOCKS_PER_SEC;
    }

    // End the test and display the results
    printf("\n\nTime Taken: %d seconds\n", time_taken);
    printf("Correct Words Typed: %d out of %d\n", correct_words, NUM_WORDS);
    printf("Typing Speed: %.2f words per minute\n", (float)(correct_words * 60) / time_taken);

    return 0;
}
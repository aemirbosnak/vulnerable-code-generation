//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
/* Typing Speed Test */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

int main()
{
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {  /* Word Bank */
        "quick", "brown", "fox", "jumps", "over",
        "the", "lazy", "dog", "in", "the",
    };
    char input[MAX_WORD_LENGTH];
    int errors = 0, count = 0, total_time_elapsed = 0;
    time_t start_time, end_time;

    srand((unsigned int)time(NULL));  /* Seed the random number generator */

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following words as fast as you can:\n\n");

    while (count < MAX_WORDS)
    {
        int word_index = rand() % MAX_WORDS;  /* Choose a random word from the word bank */
        printf("%s ", words[word_index]);  /* Display the word */
        time(&start_time);  /* Record the start time */

        fgets(input, MAX_WORD_LENGTH, stdin);  /* Get the user input */
        input[strcspn(input, "\n")] = '\0';  /* Remove the newline character */

        if (strcmp(input, words[word_index]) != 0)  /* If the input is incorrect */
        {
            printf("Incorrect! The proper word is %s.\n", words[word_index]);
            errors++;
        }

        time(&end_time);  /* Record the end time */
        total_time_elapsed += (int)difftime(end_time, start_time);  /* Calculate the time taken */
        count++;
    }

    printf("\nTyping Speed Test complete!\n");
    printf("You made %d error(s) and completed the test in %d second(s).\n", errors, total_time_elapsed);
    printf("Your typing speed is %.2f words per minute.\n", (float)MAX_WORDS / ((float)total_time_elapsed / 60.0));

    return 0;
}
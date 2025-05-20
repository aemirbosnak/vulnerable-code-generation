//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 50
#define TIME_LIMIT 60

int main()
{
    char typed_text[MAX_LENGTH];
    char random_text[MAX_LENGTH];
    time_t start_time, end_time;
    double elapsed_time, typing_speed;
    int correct_chars = 0, total_chars = 0;

    printf("Welcome to the Futuristic Typing Speed Test!\n\n");

    // Generate random text for typing test
    srand(time(NULL));
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        random_text[i] = (char)(rand() % 26 + 'a');
    }
    random_text[MAX_LENGTH - 1] = '\0';

    printf("Type the following text:\n%s\n\n", random_text);

    // Start timer
    start_time = time(NULL);

    // Get user input
    fgets(typed_text, MAX_LENGTH, stdin);

    // Remove newline character from typed text
    typed_text[strcspn(typed_text, "\n")] = 0;

    // End timer
    end_time = time(NULL);

    // Calculate elapsed time and typing speed
    elapsed_time = difftime(end_time, start_time);
    typing_speed = (double)(strlen(typed_text)) / elapsed_time * 60;

    // Calculate number of correct characters
    for (int i = 0; i < strlen(typed_text); i++)
    {
        if (typed_text[i] == random_text[i])
        {
            correct_chars++;
        }
    }

    total_chars = strlen(random_text);

    printf("\nYou typed:\n%s\n\n", typed_text);

    if (strcmp(typed_text, random_text) == 0)
    {
        printf("Congratulations! You typed the text correctly.\n");
    }
    else
    {
        printf("Sorry, the typed text does not match the random text.\n");
    }

    printf("Your typing speed is %.1f characters per minute.\n", typing_speed);
    printf("You typed %d out of %d characters correctly.\n", correct_chars, total_chars);

    if (elapsed_time > TIME_LIMIT)
    {
        printf("\nTime limit exceeded. You took %.0f seconds to type the text.\n", elapsed_time);
    }

    return 0;
}
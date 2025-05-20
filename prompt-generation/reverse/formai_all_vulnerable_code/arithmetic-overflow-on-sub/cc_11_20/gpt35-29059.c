//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TIMEOUT 60 // Timeout in seconds

int main ()
{
    char sentence[1000] = "The quick brown fox jumps over the lazy dog."; // Default sentence
    char typed[1000];
    int i, j, correct, total, speed;
    time_t start, end;

    printf("Welcome to the Typing Speed Test!\n\n");

    // Ask user for sentence or use default sentence
    printf("Enter a sentence to type (or leave blank for default sentence):\n");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = 0; // Remove newline character if present

    printf("\nType the following sentence:\n\n%s\n\n", sentence);

    printf("Press enter when you are ready to start.");
    getchar();

    printf("\nTimer starts now!\n");

    // Start timer
    start = time(NULL);

    // Loop for typing
    i = 0;
    j = 0;
    correct = 0;
    total = 0;
    while (1)
    {
        // Check if timeout
        end = time(NULL);
        if ((end - start) > TIMEOUT) break;

        // Get user input
        char c = getchar();

        // Check if end of sentence
        if (c == '.' || c == '?' || c == '!')
        {
            if (sentence[i] == c) correct++;
            total++;
            break;
        }

        // Check if backspace
        if (c == 127)
        {
            if (j > 0)
            {
                j--;
                total++;
            }
            continue;
        }

        // Check if newline
        if (c == '\n') continue;

        // Check if correct character typed
        if (sentence[i] == c) correct++;

        // Increment counters
        i++;
        j++;
        total++;
    }

    // Calculate and print results
    speed = (correct * 60) / (total * (TIMEOUT / 60));
    printf("\nTime taken: %ld seconds\n", (end - start));
    printf("Total characters typed: %d\n", total);
    printf("Correct characters typed: %d\n", correct);
    printf("Typing speed: %d characters per minute\n", speed);

    return 0;
}
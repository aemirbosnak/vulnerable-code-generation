//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SENTENCE "The quick brown fox jumps over the lazy dog"

int main()
{
    srand(time(NULL)); // seed the random number generator
    char c, input[100];
    int i = 0, errors = 0, correct = 0, seconds = 0;
    clock_t start, end;
    double time_taken;

    printf("\nWelcome to the Mind-Bending Typing Speed Test!\n");
    printf("----------------------------------------\n\n");

    printf("Your task is to re-type the following sentence:\n\n\t\t%s\n\n", SENTENCE);
    printf("Press ENTER to start the timer and begin typing...\n\n");
    getchar(); // wait for ENTER key

    start = clock(); // start the timer

    while (1)
    {
        c = rand() % 128; // generate a random character
        if (!isspace(c))
            putchar(c); // display the character if it is not a whitespace
        if (i >= sizeof(input) - 1)
            break; // stop the loop if end of input array is reached
        input[i] = getchar(); // get input from user
        if (input[i] == '\n')
            break; // stop the loop if ENTER key is pressed
        if (input[i] == SENTENCE[i])
            correct++; // count the number of correct characters typed
        else
            errors++; // count the number of errors made
        i++;
    }

    end = clock(); // end the timer
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken: %0.2f seconds\n", time_taken);
    printf("Errors: %d\n", errors);
    printf("Accuracy: %0.2f%%\n", ((double)correct / (double)i) * 100.0);
    printf("Typing speed: %0.2f characters per minute\n", ((double)i / time_taken) * 60.0);

    return 0;
}
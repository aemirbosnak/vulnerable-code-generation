//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 
In a post-apocalyptic world, communication is still important. Test your typing speed 
with this program and ensure the safe transmission of information. */

int main()
{
    char string[] = "The quick brown fox jumps over the lazy dog"; // sentence to type
    int len = strlen(string); // get length of sentence
    char typed[len]; // array to store user input
    int i, errors = 0, seconds = 0; // error count and timer variables

    printf("In this post-apocalyptic world, typing speed is crucial for communication. \n");
    printf("Type the following sentence as quickly and accurately as possible:\n\n%s\n", string);
    printf("Press enter to start the timer and begin typing.\n\n");

    getchar(); // wait for user to press enter

    time_t start = time(NULL); // start timer

    for (i = 0; i < len; i++)
    {
        printf("%c", string[i]); // print current character

        typed[i] = getchar(); // get user input

        // handle backspace input
        if (typed[i] == 8 && i > 0)
        {
            printf("\b \b"); // erase last character
            typed[--i] = 0; // clear last character in typed array
            continue; // skip error check
        }

        // check for incorrect input
        if (typed[i] != string[i])
        {
            printf("\nIncorrect! Try again.\n");
            i--; // repeat current character
            errors++; // keep track of errors
        }
    }

    time_t end = time(NULL); // end timer
    seconds = (int) difftime(end, start); // calculate elapsed time

    // print results
    printf("\n\nCongratulations, you finished typing the sentence!\n");
    printf("Errors: %d\n", errors);
    printf("Time elapsed: %d seconds\n", seconds);
    printf("Typing speed: %d characters per minute\n", (int)(len / (seconds / 60.0)));

    return 0;
}
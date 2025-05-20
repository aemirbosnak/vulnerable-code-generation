//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    char input[100];
    int i, j, len, errors = 0;
    clock_t start_t, end_t, total_t;
    double time_taken;

    len = strlen(sentence);

    printf("Type the following sentence:\n%s\n", sentence);
    printf("Press enter to start timer.\n");
    getchar();

    start_t = clock();

    fgets(input, sizeof(input), stdin);
    // Remove newline character from input
    input[strcspn(input, "\r\n")] = 0;

    end_t = clock();

    // Calculate time taken and WPM
    total_t = end_t - start_t;
    time_taken = ((double)total_t) / CLOCKS_PER_SEC;
    double wpm = ((double)len / 5) / (time_taken / 60);

    // Check for errors in input
    for(i = 0, j = 0; i < len && j < strlen(input); i++, j++)
    {
        if(sentence[i] != input[j])
        {
            errors++;
        }
    }

    printf("\nYou typed:\n%s\n", input);

    if(errors > 0)
    {
        printf("You made %d errors.\n", errors);
    }

    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your typing speed is: %.2f WPM\n", wpm);

    return 0;
}
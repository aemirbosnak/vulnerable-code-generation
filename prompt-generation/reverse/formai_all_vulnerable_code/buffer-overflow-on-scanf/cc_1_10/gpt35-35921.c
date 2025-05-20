//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int main()
{
    int count = 0, score = 0;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following text as quickly and accurately as possible:\n\n");
    printf("The quick brown fox jumps over the lazy dog.\n\n");

    delay(2000);

    printf("Begin typing now...\n\n");
    clock_t start_time = clock();

    char input[100];
    scanf("%[^\n]*c", input);

    clock_t end_time = clock();

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            count++;
        }
    }

    if (count != 8)
    {
        printf("\nYou did not enter the correct number of words.\n");
        printf("Expected: 8\n");
        printf("Actual  : %d\n", count + 1);
    }
    else
    {
        float elapsed_time = (float)(end_time - start_time) /CLOCKS_PER_SEC;
        float speeds_wpm = ((float)count + 1) / elapsed_time * 60;
        printf("\nElapsed Time: %.2f seconds\n", elapsed_time);
        printf("Speed: %.2f words per minute\n", speeds_wpm);
        score = (int)speeds_wpm;
    }

    printf("Your score is: %d\n", score);

    return 0;
}
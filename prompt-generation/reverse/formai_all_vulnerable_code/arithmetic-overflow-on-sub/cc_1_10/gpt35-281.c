//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Initializing variables
    int i, count_correct=0, count_wrong=0;
    char c[100], ch;

    // Generating a random string of characters for the typing test
    srand(time(NULL));
    for(i=0; i<100; i++)
    {
        c[i] = (char)(rand()%26+'a');
    }

    // Printing the generated string for the user
    printf("Type the following characters: \n%s\n", c);

    // Starting timer
    clock_t start_time = clock();

    // Reading user input
    for(i=0; i<100; i++)
    {
        ch = getchar();
        if(ch == c[i])
        {
            count_correct++;
        }
        else
        {
            count_wrong++;
        }
    }

    // Stopping timer
    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Displaying results
    printf("\nCorrect Characters Typed: %d\n", count_correct);
    printf("Wrong Characters Typed: %d\n", count_wrong);
    printf("Total Time Taken: %.2f seconds\n", total_time);
    double typing_speed = (count_correct/total_time)*60;
    printf("Your Typing Speed: %.2f words per minute\n", typing_speed/5);

    return 0;
}
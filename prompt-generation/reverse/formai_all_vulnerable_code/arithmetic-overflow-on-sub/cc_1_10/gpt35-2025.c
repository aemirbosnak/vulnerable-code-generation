//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 10
#define TEST_TIME 60

int main()
{
    int speed[NUM_TESTS];
    int correct_chars;
    char user_input;
    time_t start, end;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be given a random set of characters to type.\n");
    printf("Each test will last %d seconds.\n\n", TEST_TIME);

    srand(time(NULL));

    for (int i = 0; i < NUM_TESTS; i++)
    {
        char test_string[11];
        for (int j = 0; j < 10; j++)
        {
            test_string[j] = 'a' + rand() % 26;
        }
        test_string[10] = '\0';

        printf("Test %d:\n", i + 1);
        printf("%s\n", test_string);

        time(&start);
        correct_chars = 0;

        while (difftime(end, start) < TEST_TIME)
        {
            user_input = getchar();
            if (user_input == '\n') break;
            if (user_input == test_string[correct_chars])
            {
                correct_chars++;
            }
            fflush(stdin);
        }

        time(&end);

        speed[i] = correct_chars / TEST_TIME;

        printf("Time taken: %ld seconds.\n", end - start);
        printf("Your typing speed: %d characters per second.\n\n", speed[i]);
    }

    int total_speed = 0;
    for (int i = 0; i < NUM_TESTS; i++)
    {
        total_speed += speed[i];
    }

    int avg_speed = total_speed / NUM_TESTS;

    printf("Your average typing speed: %d characters per second.\n", avg_speed);

    return 0;
}
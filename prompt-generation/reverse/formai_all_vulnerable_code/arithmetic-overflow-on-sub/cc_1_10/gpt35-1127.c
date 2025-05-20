//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    // Declaration of variables
    char input[50];
    char random_chars[50];
    int length;
    int i, j;
    int correct_count = 0, incorrect_count = 0;
    double total_time;
    clock_t start_time, end_time;
    bool is_correct = true;
    float typing_speed;

    // Seed random number generator
    srand(time(0));

    // Input prompt
    printf("Welcome to the Typing Speed Test. You will be presented with a random set of letters and your task is to type them as fast as possible and with as few errors as possible.\n");
    printf("Enter the length of the set of letters to type (maximum 50 characters): ");
    scanf("%d", &length);
    if (length > 50)
    {
        printf("Invalid length. Please enter a length between 1 and 50.\n");
        return 0;
    }

    // Generate random characters
    printf("Type the following set of letters as fast as possible and with as few errors as possible:\n");
    for (i = 0; i < length; i++)
    {
        random_chars[i] = 'a' + (rand() % 26);
        printf("%c ", random_chars[i]);
    }
    printf("\n");

    // Start timer
    start_time = clock();

    // Get user input
    scanf("%s", input);
    if (strlen(input) != length)
    {
        printf("Error: Incorrect length of input.\n");
        return 0;
    }

    // Check if typed correctly
    for (i = 0; i < length; i++)
    {
        if (tolower(input[i]) != random_chars[i])
        {
            is_correct = false;
            incorrect_count++;
        }
        else
        {
            correct_count++;
        }
    }

    // End timer
    end_time = clock();

    // Calculate typing speed
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    typing_speed = (float)correct_count / total_time * 60;

    // Display results
    printf("Results:\n");
    printf("Correctly typed: %d\n", correct_count);
    printf("Incorrectly typed: %d\n", incorrect_count);
    printf("Typing speed: %.2f characters per minute\n", typing_speed);

    return 0;
}
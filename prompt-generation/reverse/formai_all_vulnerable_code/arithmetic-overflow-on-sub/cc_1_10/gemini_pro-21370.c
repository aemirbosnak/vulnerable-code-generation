//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_random_string(int n)
{
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++)
    {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to get the accuracy of the user's input
float get_accuracy(char *original, char *input)
{
    int correct_chars = 0;
    for (int i = 0; i < strlen(original); i++)
    {
        if (original[i] == input[i])
        {
            correct_chars++;
        }
    }
    return (float)correct_chars / strlen(original) * 100;
}

// Function to get the speed of the user's input
float get_speed(int n, float time)
{
    return (float)n / time * 60;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the string to be typed
    int n;
    printf("Enter the length of the string to be typed: ");
    scanf("%d", &n);

    // Generate a random string
    char *original = generate_random_string(n);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char *input = malloc(n + 1);
    printf("Type the following string: %s\n", original);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the accuracy and speed of the user's input
    float accuracy = get_accuracy(original, input);
    float speed = get_speed(n, (float)(end - start) / CLOCKS_PER_SEC);

    // Print the results
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f words per minute\n", speed);

    // Free the allocated memory
    free(original);
    free(input);

    return 0;
}
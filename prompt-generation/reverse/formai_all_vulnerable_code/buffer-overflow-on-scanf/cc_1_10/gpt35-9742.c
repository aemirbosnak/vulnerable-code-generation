//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of attempts
#define MAX_ATTEMPTS 3

// Define the prototype of the function that handles errors
void handle_error(const char *message, int *attempts_left);

int main(void)
{
    // Initialize the attempts counter
    int attempts_left = MAX_ATTEMPTS;

    // Prompt the user to enter a number
    printf("Please enter an integer: ");

    // Read the number from the input
    int num;
    if (scanf("%d", &num) != 1)
    {
        handle_error("Failed to read the number from the input", &attempts_left);
    }

    // Check if the number is positive
    if (num < 0)
    {
        handle_error("The number must be positive", &attempts_left);
    }

    // Print the number
    printf("You entered: %d\n", num);

    // Exit with success
    return EXIT_SUCCESS;
}

void handle_error(const char *message, int *attempts_left)
{
    // Decrement the attempts counter
    (*attempts_left)--;

    // Check if there are more attempts left
    if (*attempts_left > 0)
    {
        printf("%s. You have %d attempts left.\n", message, *attempts_left);
    }
    else
    {
        printf("You have no more attempts left. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }
}
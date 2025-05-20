//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000000

int main()
{
    char input_string[MAX_SIZE];
    char *output_string;
    int length;
    int i, j;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);

    // Remove the newline character from the input string
    length = strlen(input_string);
    if (input_string[length - 1] == '\n')
    {
        input_string[length - 1] = '\0';
    }

    // Reverse the input string
    for (i = 0, j = strlen(input_string) - 1; i < j; i++, j--)
    {
        char temp = input_string[i];
        input_string[i] = input_string[j];
        input_string[j] = temp;
    }

    // Allocate memory for the output string
    output_string = malloc(strlen(input_string) + 1);
    if (output_string == NULL)
    {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }

    // Copy the input string to the output string
    strcpy(output_string, input_string);

    // Remove all non-alphanumeric characters from the output string
    char *p = output_string;
    while (*p!= '\0')
    {
        if (!isalnum(*p))
        {
            *p = '\0';
        }
        p++;
    }

    // Reverse the output string
    for (i = 0, j = strlen(output_string) - 1; i < j; i++, j--)
    {
        char temp = output_string[i];
        output_string[i] = output_string[j];
        output_string[j] = temp;
    }

    // Display the output string
    printf("Output string: %s\n", output_string);

    // Free the memory allocated for the output string
    free(output_string);

    return 0;
}
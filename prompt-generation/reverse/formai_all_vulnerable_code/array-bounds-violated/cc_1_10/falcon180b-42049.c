//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main()
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char temp[MAX_LENGTH];
    int i, j, k;
    int length;

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing whitespace
    i = 0;
    j = strlen(input) - 1;
    while (isspace(input[i])) i++;
    while (isspace(input[j])) j--;
    length = j - i + 1;
    strncpy(temp, &input[i], length);
    temp[length] = '\0';

    // Reverse the string
    for (i = 0, j = strlen(temp) - 1; i < j; i++, j--)
    {
        char c = temp[i];
        temp[i] = temp[j];
        temp[j] = c;
    }

    // Convert to uppercase
    for (i = 0; i < strlen(temp); i++)
    {
        if (isalpha(temp[i]))
        {
            temp[i] = toupper(temp[i]);
        }
    }

    // Remove vowels
    for (i = 0; i < strlen(temp); i++)
    {
        if (!isalpha(temp[i]))
        {
            strncat(output, &temp[i], 1);
        }
    }

    // Output the result
    printf("Reversed string without vowels and in uppercase: %s\n", output);

    return 0;
}
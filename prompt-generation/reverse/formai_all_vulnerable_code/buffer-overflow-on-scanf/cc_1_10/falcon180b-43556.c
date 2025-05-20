//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

int main()
{
    char input_string[MAX_STRING_LENGTH];
    char output_string[MAX_STRING_LENGTH];
    char delimiter_char;
    int string_length;
    int i, j;

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Remove newline character from input string
    input_string[strcspn(input_string, "\n")] = '\0';

    // Prompt user for delimiter character
    printf("Enter a delimiter character: ");
    scanf("%c", &delimiter_char);

    // Initialize string length
    string_length = strlen(input_string);

    // Initialize output string with first character of input string
    output_string[0] = input_string[0];

    // Loop through input string and append to output string if not delimiter character
    for (i = 1; i < string_length; i++)
    {
        if (input_string[i]!= delimiter_char)
        {
            output_string[j] = input_string[i];
            j++;
        }
    }

    // Append delimiter character to output string if it exists in input string
    if (delimiter_char!= '\n')
    {
        output_string[j] = delimiter_char;
        j++;
    }

    // Append null terminator to output string
    output_string[j] = '\0';

    // Print output string
    printf("Output string: %s\n", output_string);

    return 0;
}
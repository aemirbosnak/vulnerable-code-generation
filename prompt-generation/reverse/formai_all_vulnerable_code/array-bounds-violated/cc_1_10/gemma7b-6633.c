//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    int line_number = 1;
    int character_position = 0;
    char current_character = '\0';

    // Read the source code from the user
    printf("Enter the source code: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Format the source code
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        // Handle line numbers
        if (buffer[i] == '\n')
        {
            line_number++;
            character_position = 0;
        }

        // Handle character indentation
        if (buffer[i] == '{' || buffer[i] == '}' || buffer[i] == '}')
        {
            int indent_level = count_indentations(buffer, i);
            character_position = indent_level * 2;
        }

        // Insert whitespace
        if (character_position > 0)
        {
            for (int j = character_position; j > 0; j--)
            {
                buffer[i - j] = ' ';
            }
        }

        // Store the character
        buffer[i] = current_character;
        current_character = buffer[i];
    }

    // Print the formatted source code
    printf("Formatted source code:\n\n");
    printf("%s", buffer);

    return 0;
}

int count_indentations(char *buffer, int index)
{
    int indentations = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '{' && buffer[i] == buffer[index])
        {
            indentations++;
        }
    }
    return indentations;
}
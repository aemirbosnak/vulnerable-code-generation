#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int line_number = 1;
    char buffer[1024];

    // Loop until the user enters an empty line
    while (1)
    {
        printf("Enter text (line %d): ", line_number);
        fgets(buffer, 1024, stdin);

        // Check if the user entered an empty line
        if (buffer[0] == '\0')
        {
            break;
        }

        // Increment the line number
        line_number++;
    }

    // Print the contents of the buffer
    printf("Lines: \n");
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        printf("%c", buffer[i]);
    }

    return 0;
}

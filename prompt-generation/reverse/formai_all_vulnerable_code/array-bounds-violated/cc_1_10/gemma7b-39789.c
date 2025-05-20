//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;

    // Listen for user input
    printf("Enter a message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Analyze the input for suspicious patterns
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check for repeated characters
        if (buffer[i] == buffer[i-1] && buffer[i] == buffer[i-2])
        {
            printf("WARNING: Suspicious character repetition detected.\n");
            break;
        }

        // Check for unusual character combinations
        switch (buffer[i])
        {
            case 'a':
                if (buffer[i-1] == 'b' && buffer[i+1] == 'c')
                {
                    printf("WARNING: Suspicious character combination detected.\n");
                    break;
                }
                break;

            case 'e':
                if (buffer[i-1] == 'f' && buffer[i+1] == 'g')
                {
                    printf("WARNING: Suspicious character combination detected.\n");
                    break;
                }
                break;

            default:
                break;
        }
    }

    // Print the remaining message
    printf("Your message: %s\n", buffer);

    return 0;
}
//FormAI DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <ctype.h>

// Declare variables and arrays
int i, j, len, errCount = 0;
char input[100];
char dict[10][10] = {"Hello", "world", "you", "are", "awesome",
                     "sometimes", "things", "just", "don't", "work"};

int main()
{
    printf("Enter your sentence: ");
    fgets(input, 100, stdin);

    len = strlen(input);

    // Remove new line character from input
    if (input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Convert input to lowercase
    for (i = 0; input[i]; i++)
        input[i] = tolower(input[i]);

    // Check for errors
    for (i = 0; input[i]; i++)
    {
        if (input[i] == ' ' || input[i] == '.' || input[i] == ',')
            continue;

        for (j = 0; j < 10; j++)
        {
            if (strncmp(&input[i], dict[j], strlen(dict[j])) == 0)
            {
                i += strlen(dict[j]) - 1;
                break;
            }
        }
        
        if (input[i] != dict[j][0])
        {
            printf("Error at position %d: %c should be %c\n", i+1, input[i], dict[j][0]);
            errCount++;
        }
    }

    // Print number of errors
    if (errCount == 0)
        printf("No errors found!\n");
    else if (errCount == 1)
        printf("1 error found.\n");
    else
        printf("%d errors found.\n", errCount);

    return 0;
}
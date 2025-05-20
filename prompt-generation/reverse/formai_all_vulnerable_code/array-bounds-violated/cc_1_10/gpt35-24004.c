//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main()
{
    char string[MAX_LEN];
    int i, j, len;
    char temp;

    printf("Enter a string: ");
    fgets(string, MAX_LEN, stdin);

    // Check for buffer overflow
    len = strlen(string);
    if (len == MAX_LEN && (string[MAX_LEN-1] != '\0' || string[MAX_LEN-2] != '\n'))
    {
        printf("Error: Buffer overflow detected!\n");
        exit(1);
    }

    // Check for null termination
    if (string[len-1] != '\n')
    {
        printf("Error: String not properly terminated with a newline character!\n");
        exit(1);
    }

    // Remove newline character
    string[len-1] = '\0';

    // Check for possible injection attacks
    for (i = 0; i < len; i++)
    {
        if (string[i] == ';')
        {
            printf("Error: Detected possible injection attack. Exiting...\n");
            exit(1);
        }
        else if (string[i] == '\\')
        {
            printf("Error: Detected possible escape sequence. Exiting...\n");
            exit(1);
        }
    }

    // Reverse string
    for (i = 0, j = len-2; i < j; i++, j--)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }

    printf("Reversed string: %s\n", string);

    return 0;
}
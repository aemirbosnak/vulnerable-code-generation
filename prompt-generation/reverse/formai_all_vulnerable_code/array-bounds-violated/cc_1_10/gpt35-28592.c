//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // initialize variables
    char input[1000], output[1000];
    int i, j = 0, indent = 0;

    // get user input
    printf("Enter HTML code:\n");
    fgets(input, 1000, stdin);

    // loop through input and add indentation/line breaks
    for (i = 0; i < strlen(input); i++) 
    {
        // check for tags and add indentation
        if (input[i] == '<') 
        {
            if (input[i+1] == '/')
            {
                indent -= 4;
            }
            else if (input[i-1] == '/')
            {
                indent += 0;
            }
            else
            {
                indent += 4;
            }
            printf("\n%*s%c", indent, " ", input[i]);
            j++;
        }
        // check for end tags and decrease indentation
        else if (input[i] == '>') 
        {
            printf("%c", input[i]);
        }
        // add characters to output string
        else 
        {
            printf("%c", input[i]);
        }
    }

    // print output
    printf("\n\nFormatted code:\n%s\n", output);

    return 0;
}
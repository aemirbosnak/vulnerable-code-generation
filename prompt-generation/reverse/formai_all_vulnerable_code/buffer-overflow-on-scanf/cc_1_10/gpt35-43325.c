//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_string[100];
    char output_string[100];
    char reversed_string[100];
    char temp[100];

    printf("Enter a string: ");
    scanf("%s", input_string);

    // Convert all characters to uppercase
    int i;
    for(i=0; input_string[i]!='\0'; i++)
    {
        if(input_string[i]>='a' && input_string[i]<='z')
        {
            input_string[i] = input_string[i] - 32;
        }
    }

    // Copy the input string to output string
    strcpy(output_string, input_string);

    // Reverse the string
    int j = 0;
    for(i=strlen(input_string)-1; i>=0; i--)
    {
        reversed_string[j++] = input_string[i];
    }
    reversed_string[j] = '\0';

    // Concatenate the reversed string and output string
    strcat(output_string, reversed_string);

    // Sort the string in lexicographically ascending order
    int n = strlen(output_string);
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(output_string[i]>output_string[j])
            {
                strcpy(temp, &output_string[i]);
                output_string[i] = output_string[j];
                output_string[j] = temp[0];
                strcat(output_string, temp+1);
            }
        }
    }

    printf("The final string is: %s\n", output_string);

    return 0;
}
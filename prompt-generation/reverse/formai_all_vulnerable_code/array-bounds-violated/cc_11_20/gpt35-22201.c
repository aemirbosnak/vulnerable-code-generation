//FormAI DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <string.h>

int main()
{
    char input_str[100], output_str[100];
    int i, j, k;

    printf("Enter the input string: ");
    scanf("%s", input_str);

    for(i=0; input_str[i]!='\0'; i++)
    {
        if(input_str[i] != ' ')
        {
            output_str[j++] = input_str[i];
        }
        else
        {
            if(input_str[i+1] != ' ' && input_str[i+1] != '\0')
            {
                output_str[j++] = ' ';
            }
        }
    }
    output_str[j] = '\0';

    for(i=0; output_str[i]!='\0'; i++)
    {
        if(output_str[i] >= 'a' && output_str[i] <= 'z')
        {
            output_str[i] -= 32;
        }
        else if(output_str[i] >= 'A' && output_str[i] <= 'Z')
        {
            output_str[i] += 32;
        }
    }

    k = strlen(output_str) - 1;
    for(i=0; i<k; i++, k--)
    {
        output_str[i] ^= output_str[k];
        output_str[k] ^= output_str[i];
        output_str[i] ^= output_str[k];
    }

    printf("The output string is: %s", output_str);

    return 0;
}
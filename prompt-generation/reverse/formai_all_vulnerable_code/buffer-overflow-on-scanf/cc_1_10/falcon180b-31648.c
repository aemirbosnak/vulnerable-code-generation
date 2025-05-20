//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char string[1000];
    int length, i, j;

    // Get string input from user
    printf("Enter a string: ");
    scanf("%[^\n]", string);
    length = strlen(string);

    // Remove leading and trailing spaces
    for(i=0; i<length; i++)
    {
        if(isspace(string[i]))
        {
            for(j=i; j<length; j++)
            {
                string[j] = string[j+1];
            }
            length--;
        }
    }

    // Reverse string
    for(i=0; i<length/2; i++)
    {
        char temp = string[i];
        string[i] = string[length-i-1];
        string[length-i-1] = temp;
    }

    // Convert to uppercase
    for(i=0; i<length; i++)
    {
        string[i] = toupper(string[i]);
    }

    // Count number of words
    int count = 0;
    for(i=0; i<length; i++)
    {
        if(isspace(string[i]))
        {
            count++;
        }
    }

    // Output results
    printf("Reversed string: %s\n", string);
    printf("Number of words: %d\n", count);

    return 0;
}
//FormAI DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];

    printf("Please enter a sentence:\n");
    fgets(str, 100, stdin); // using fgets to avoid buffer overflow

    int len = strlen(str);

    printf("\n\nText processing results:\n");

    // Capitalize each word 
    printf("Capitalized Text: ");
    for(int i=0; i<len; i++)
    {
        if(str[i-1] == ' ' || i==0) // condition to check for first letter of each word
        {
            str[i] = toupper(str[i]);
            putchar(str[i]); 
        }
        else
        {
            putchar(str[i]);
        }
    }

    // Removing extra whitespaces
    printf("\nText with no extra spaces: ");
    for(int i=0; i<len; i++)
    {
        if((str[i-1] == ' ' && str[i] == ' ') || i==len-1) // condition to check two consecutive spaces
        {
            continue;
        }
        else
        {
            putchar(str[i]);
        }
    }

    // Reversing the sentence
    printf("\nReversed text: ");
    for(int i=len-1; i>=0; i--)
    {
        putchar(str[i]);
    }

    return 0;
}
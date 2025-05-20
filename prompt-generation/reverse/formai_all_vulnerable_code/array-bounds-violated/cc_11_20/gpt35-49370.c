//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int main()
{
    char input[MAX_INPUT_LENGTH];
    printf("Enter a sentence:");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strlen(input)-1] = '\0'; // Removing the newline character

    int wordCount = 1;
    int vowelCount = 0;
    int consonantCount = 0;
    int letterCount = 0;
    int digitCount = 0;
    int symbolCount = 0;

    for(int i=0; input[i]!='\0'; i++)
    {
        if(input[i] == ' ')
        {
            wordCount++;
        }
        else if(isalpha(input[i]))
        {
            letterCount++;
            if(input[i]=='A' || input[i]=='E' || input[i]=='I' || input[i]=='O' || input[i]=='U' || input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u')
            {
                vowelCount++;
            }
            else
            {
                consonantCount++;
            }
        }
        else if(isdigit(input[i]))
        {
            digitCount++;
        }
        else if(ispunct(input[i]))
        {
            symbolCount++;
        }
    }

    printf("The input sentence has %d words\n", wordCount);
    printf("The input sentence has %d letters\n", letterCount);
    printf("The input sentence has %d vowels\n", vowelCount);
    printf("The input sentence has %d consonants\n", consonantCount);
    printf("The input sentence has %d digits\n", digitCount);
    printf("The input sentence has %d symbols\n", symbolCount);

    return 0;
}
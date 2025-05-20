//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include<stdio.h>
#include<string.h>
 
int main()
{
    char alienWord[100];
    int i, j, len, vowelCount = 0, consonantCount = 0;
    
    printf("Enter the alien word to translate: ");
    scanf("%s", alienWord);
    len = strlen(alienWord);
    
    // check if the word contains only A, U, E, O, P
    for(i=0; i<len; i++)
    {
        if(alienWord[i] != 'A' && alienWord[i] != 'U' && alienWord[i] != 'E' && alienWord[i] != 'O' && alienWord[i] != 'P')
        {
            printf("ERROR! The word contains invalid characters!");
            return 0;
        }
    }
    
    // check if the word contains at least 1 vowel
    for(i=0; i<len; i++)
    {
        if(alienWord[i] == 'A' || alienWord[i] == 'U' || alienWord[i] == 'E' || alienWord[i] == 'O')
        {
            vowelCount++;
            break;
        }
    }
    
    if(vowelCount == 0)
    {
        printf("ERROR! The word should contain at least 1 vowel!");
        return 0;
    }
    
    // count the number of consonants in the word
    consonantCount = len - vowelCount;
    
    // translate the word
    printf("\nThe translated word is: ");
    for(i=0; i<len; i++)
    {
        switch(alienWord[i])
        {
            case 'A':
                printf("y");
                break;
            case 'U':
                printf("z");
                break;
            case 'E':
                printf("x");
                break;
            case 'O':
                printf("w");
                break;
            case 'P':
                printf("%d", consonantCount);
                break;
        }
    }
    
    return 0;
}

/*
Example:
Input:
Enter the alien word to translate: POP

Output:
The translated word is: 1
*/
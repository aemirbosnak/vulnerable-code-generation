//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_LENGTH 1000
#define MAX_VOWELS 5

int main()
{
    char input[MAX_LENGTH];
    int length, i, j, k, max_length = 0, max_index = 0;
    bool is_vowel[MAX_VOWELS] = {false, false, false, false, false};
    char vowels[MAX_VOWELS] = {'a', 'e', 'i', 'o', 'u'};
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    length = strlen(input);
    
    for(i=0; i<length; i++)
    {
        if(isalpha(input[i]))
        {
            for(j=0; j<MAX_VOWELS; j++)
            {
                if(input[i] == vowels[j])
                {
                    is_vowel[j] = true;
                    break;
                }
            }
        }
    }
    
    for(i=0; i<MAX_VOWELS; i++)
    {
        if(is_vowel[i])
        {
            max_length = 0;
            for(j=0; j<length; j++)
            {
                if(input[j] == vowels[i])
                {
                    for(k=j+1; k<length; k++)
                    {
                        if(isalpha(input[k]) && input[k] == vowels[i])
                        {
                            max_length++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            if(max_length > max_index)
            {
                max_index = i;
            }
        }
    }
    
    printf("The longest vowel sequence is: ");
    for(i=0; i<max_index; i++)
    {
        printf("%c", vowels[i]);
    }
    printf("\n");
    
    return 0;
}
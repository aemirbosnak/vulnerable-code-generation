//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[100];
    int length, i, j, flag;

    printf("Enter a word: ");
    scanf("%s", word);

    length = strlen(word);

    // Removing non-alphabetic characters and converting to lowercase
    for (i = 0; i < length; i++)
    {
        if (!isalpha(word[i]))
        {
            for (j = i; j < length; j++)
            {
                word[j] = word[j+1];
            }
            length--;
            i--;
        }
        else
        {
            word[i] = tolower(word[i]);
        }
    }

    // Checking if word is a palindrome
    flag = 1;
    for (i = 0; i < length/2; i++)
    {
        if (word[i] != word[length-i-1])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        printf("%s is a palindrome!\n", word);
    }
    else
    {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int main()
{
    char string1[100], string2[100];
    int len1, len2;

    printf("Enter the first string:\n");
    scanf("%s", string1);

    printf("Enter the second string:\n");
    scanf("%s", string2);

    len1 = strlen(string1);
    len2 = strlen(string2);

    printf("Length of the first string is: %d\n", len1);
    printf("Length of the second string is: %d\n", len2);

    //Concatenation of two strings
    strcat(string1, string2);
    printf("String after concatenation: %s\n", string1);

    //Comparing two strings
    if(strcmp(string1, string2) == 0)
    {
        printf("Entered strings are equal.\n");
    }
    else
    {
        printf("Entered strings are not equal.\n");
    }

    //Reversing a string
    printf("The first string in reverse order: ");
    for(int i=len1-1; i>=0; i--)
    {
        printf("%c", string1[i]);
    }
    printf("\n");

    //Pallindrome checking
    int flag = 1;
    for(int i=0; i<len1; i++)
    {
        if(string1[i] != string1[len1-i-1])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Entered string is a pallindrome.\n");
    }
    else
    {
        printf("Entered string is not a pallindrome.\n");
    }

    //Frequency of each character
    int freq[26] = {0};
    for(int i=0; i<len1; i++)
    {
        freq[string1[i] - 'a']++;
    }
    printf("Frequency of each character in the first string:\n");
    for(int i=0; i<26; i++)
    {
        if(freq[i] != 0)
        {
            printf("%c: %d\n", i+'a', freq[i]);
        }
    }

    return 0;
}
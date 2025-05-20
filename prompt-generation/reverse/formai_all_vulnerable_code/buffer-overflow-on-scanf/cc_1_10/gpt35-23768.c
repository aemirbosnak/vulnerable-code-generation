//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include<stdio.h>
#include<string.h>

int main()
{
    char string1[20], string2[20];
    int i,j,k,len1,len2;

    printf("Enter string 1: ");
    scanf("%s",string1);
    printf("Enter string 2: ");
    scanf("%s",string2);

    len1 = strlen(string1);
    len2 = strlen(string2);

    // Concatenate two strings
    for(i=0; i<len2; i++)
    {
        string1[len1+i] = string2[i];
    }
    string1[len1+i] = '\0';

    printf("\nConcatenated string is: %s\n",string1);

    // Reverse the string
    for(i=0,j=len1-1; i<j; i++,j--)
    {
        k = string1[i];
        string1[i] = string1[j];
        string1[j] = k;
    }

    printf("\nReversed string is: %s\n",string1);

    // Check if strings are palindrome or not
    for(i=0,j=len1-1; i<j; i++,j--)
    {
        if(string1[i]!=string1[j])
        {
            printf("\n%d is not a palindrome\n",string1);
            break;
        }
    }
    if(i>=j)
    {
        printf("\n%d is a palindrome\n",string1);
    }

    // Convert lowercase to uppercase
    for(i=0; string1[i]!='\0'; i++)
    {
        if(string1[i]>='a' && string1[i]<='z')
        {
            string1[i] = string1[i]-32;
        }
    }

    printf("\nUppercase string is: %s\n",string1);

    return 0;
}
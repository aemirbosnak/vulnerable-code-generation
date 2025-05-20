//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int checkPalindrome(char str[], int len);

int main()
{
    char str[SIZE];
    int len;

    printf("Enter a string to check if it's a palindrome: ");
    fgets(str, SIZE, stdin);

    len = strlen(str);
    len -= (str[len-1] == '\n') ? 2 : 1;

    if(checkPalindrome(str, len))
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);

    return 0;
}

int checkPalindrome(char str[], int len)
{
    int i, j;
    char temp;

    for(i=0, j=len-1; i<j; i++, j--)
    {
        while(!((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]=='\0'))
            i++;
        while(!((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z') || str[j]=='\0'))
            j--;

        if((str[i]>='A' && str[i]<='Z'))
            str[i] = str[i] + 32;
        if((str[j]>='A' && str[j]<='Z'))
            str[j] = str[j] + 32;

        if(str[i] != str[j])
            return 0;
    }

    return 1;
}
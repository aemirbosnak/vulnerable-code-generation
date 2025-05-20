//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

// Recursive function to translate the given string to C Alien language
void alienTranslate(char str[], int len)
{
    if(len <= 0) // Base case: if length is 0 or negative, stop recursion
    {
        return;
    }
    else if(str[len-1] == 'A' || str[len-1] == 'a') // if the last character is A or a, translate to @ symbol
    {
        str[len-1] = '@';
        alienTranslate(str, len-1); // make recursive call for the remaining characters
    }
    else if(str[len-1] == 'B' || str[len-1] == 'b') // if the last character is B or b, translate to 8 symbol
    {
        str[len-1] = '8';
        alienTranslate(str, len-1); // make recursive call for the remaining characters
    }
    else if(str[len-1] == 'C' || str[len-1] == 'c') // if the last character is C or c, translate to ( symbol
    {
        str[len-1] = '(';
        alienTranslate(str, len-1); // make recursive call for the remaining characters
    }
    else if(str[len-1] == 'D' || str[len-1] == 'd') // if the last character is D or d, translate to |) symbol
    {
        str[len-1] = '|';
        int i;
        for(i=len-1; i>0; i--)
        {
            str[i] = str[i-1]; // shift all characters to the right by one position
        }
        str[0] = '|';
        str[len+1] = ')';
        alienTranslate(str, len+2); // make recursive call for the remaining characters
    }
    else // for any other character, make recursive call for the remaining characters
    {
        alienTranslate(str, len-1);
    }
}

int main()
{
    char str[100];
    printf("Enter a string in C Alien language: ");
    scanf("%s", str);
    int len = strlen(str);
    alienTranslate(str, len);
    printf("The translated string is: %s\n", str);
    return 0;
}
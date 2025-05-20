//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str, int len);

int main()
{
    char input[100];
    int length;
    
    printf("Enter a word or phrase to check if it's a palindrome:\n");
    fgets(input, 100, stdin);
    
    // remove newline character from input
    length = strlen(input);
    if (input[length-1] == '\n')
    {
        input[length-1] = '\0';
        length--;
    }
    
    // check if input is a palindrome
    if (is_palindrome(input, length))
    {
        printf("Yes, '%s' is a palindrome.\n", input);
    }
    else
    {
        printf("No, '%s' is not a palindrome.\n", input);
    }
    
    return 0;
}

int is_palindrome(char *str, int len)
{
    int i, j;
    char c1, c2;
    
    // convert all characters to lowercase
    for (i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
    
    // check if string is a palindrome
    for (i = 0, j = len-1; i < j; i++, j--)
    {
        // ignore non-alphanumeric characters
        while (!isalnum(str[i]) && i < j) i++;
        while (!isalnum(str[j]) && i < j) j--;
        
        // compare characters (ignoring case)
        c1 = tolower(str[i]);
        c2 = tolower(str[j]);
        if (c1 != c2)
        {
            return 0;
        }
    }
    
    return 1;
}
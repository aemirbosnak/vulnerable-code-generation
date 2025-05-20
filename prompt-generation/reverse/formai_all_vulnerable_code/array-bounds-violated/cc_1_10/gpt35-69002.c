//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void palindrome(char *str);

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove new line character if present
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    // Check if string is a palindrome
    palindrome(str);

    return 0;
}

// Function to check if string is a palindrome
void palindrome(char *str)
{
    char str_lower[strlen(str)+1];
    int i, j;

    // Convert string to lowercase
    for(i=0,j=0; str[i]!='\0'; i++)
    {
        if(isalpha(str[i])){
            str_lower[j++] = tolower(str[i]);
        }
    }
    str_lower[j] = '\0';

    // Check if string is a palindrome
    int len = strlen(str_lower);
    for(i=0; i<len/2; i++)
    {
        if(str_lower[i] != str_lower[len-i-1]){
            printf("%s is not a palindrome", str);
            return;
        }
    }
    printf("%s is a palindrome", str);
}
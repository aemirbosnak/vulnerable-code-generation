//FormAI DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000//maximum string length to be handled

/**
 * This function takes two strings as an arguments and returns the first character of string1
 * that occurs in string2. If none of the characters are found, the function returns '\0'.
 **/
char get_first_common_char(const char *str1, const char *str2) 
{
    int len1 = strlen(str1), len2 = strlen(str2);
    int i, j;
    for (i = 0; i < len1; i++) 
    {
        for (j = 0; j < len2; j++) 
        {
            if (str1[i] == str2[j]) 
            {
                return str1[i];
            }
        }
    }
    return '\0';//returning null, if none of the character is found
}

/**
 * This function takes a string as an argument and returns true if the string
 * contains all unique characters, otherwise it returns false.
 **/
int is_unique(const char *str) 
{
    int len = strlen(str), i, j;
    for (i = 0; i < len; i++) 
    {
        for (j = i + 1; j < len; j++) 
        {
            if (str[i] == str[j]) 
            {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * The main function
 **/
int main() 
{
    char string1[MAX_STRING_LENGTH], string2[MAX_STRING_LENGTH];
    printf("Enter first string: ");
    fgets(string1, MAX_STRING_LENGTH, stdin);//reading the first string
    printf("Enter second string: ");
    fgets(string2, MAX_STRING_LENGTH, stdin);//reading the second string

    //removing the newline character from string1, if any.
    if (string1[strlen(string1) - 1] == '\n') 
    {
        string1[strlen(string1) - 1] = '\0';
    }

    //removing the newline character from string2, if any.
    if (string2[strlen(string2) - 1] == '\n') 
    {
        string2[strlen(string2) - 1] = '\0';
    }

    printf("First common character of string1 and string2 is: %c\n", 
        get_first_common_char(string1, string2));

    if (is_unique(string1)) 
    {
        printf("string1 contains all unique characters\n");
    } 
    else 
    {
        printf("string1 does not contain all unique characters\n");
    }

    if (is_unique(string2)) 
    {
        printf("string2 contains all unique characters\n");
    } 
    else 
    {
        printf("string2 does not contain all unique characters\n");
    }

    return 0;
}
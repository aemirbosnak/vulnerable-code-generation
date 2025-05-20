//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Defining Macros
#define MAX_STRING_SIZE 100

/*Function to check whether a given string is a palindrome*/
int is_Palindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-i-1])
            return 0;
    }
    return 1;
}

/*Function to reverse a given string*/
char* reverse(char* str)
{
    int len = strlen(str);
    char* rev_str = (char*)malloc((len+1)*sizeof(char));
    for (int i = 0; i < len; i++)
    {
        rev_str[i] = str[len-i-1];
    }
    rev_str[len] = '\0';
    return rev_str;
}

/*Function to compute the sum of ASCII values of all characters
in a given string*/
int sum_ASCII(char* str)
{
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        sum += (int)str[i];
    }
    return sum;
}

/*Function to concatenate two given strings*/
char* concatenate(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* conc_str = (char*)malloc((len1+len2+1)*sizeof(char));
    int i,j;
    for (i = 0; i < len1; i++)
    {
        conc_str[i] = str1[i];
    }
    for (j = 0; j < len2; j++)
    {
        conc_str[i+j] = str2[j];
    }
    conc_str[i+j] = '\0';
    return conc_str;
}

/*Function to replace a character at a given position
in a given string*/
char* replace(char* str, char c, int pos)
{
    str[pos-1] = c;
    return str;
}

int main()
{
    char str1[MAX_STRING_SIZE];
    char str2[MAX_STRING_SIZE];
    char* conc_str;
    char* rev_str;
    int pal, sum;

    //Read two strings from user
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    //Check if string 1 is a palindrome
    pal = is_Palindrome(str1);
    if (pal == 1)
        printf("String 1 is a palindrome\n");
    else
        printf("String 1 is not a palindrome\n");

    //Compute the sum of ASCII values of all characters in string 2
    sum = sum_ASCII(str2);
    printf("Sum of ASCII values of characters in string 2: %d\n", sum);

    //Reverse string 1 and print it
    rev_str = reverse(str1);
    printf("Reverse of String 1: %s\n", rev_str);

    //Concatenate string 1 and string 2 and print the resulting string
    conc_str = concatenate(str1, str2);
    printf("Concatenation of string 1 and string 2: %s\n", conc_str);

    //Replace the 3rd character in string 2 with 'A' and print the resulting string
    char* replace_str = replace(str2, 'A', 3);
    printf("Replacing the 3rd character in String 2 with A: %s\n", replace_str);

    //Free memory
    free(rev_str);
    free(conc_str);
    free(replace_str);

    return 0;
}
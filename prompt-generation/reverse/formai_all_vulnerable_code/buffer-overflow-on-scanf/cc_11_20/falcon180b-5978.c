//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];
    int len, i, j, k;

    // Taking input from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Checking if the input string contains only alphabets
    for(i=0; str[i]!='\0'; i++)
    {
        if(!isalpha(str[i]))
        {
            printf("Error! Input string should contain only alphabets.\n");
            return 0;
        }
    }

    // Calculating length of the string
    len = strlen(str);

    // Reversing the string
    for(i=0, j=len-1; i<j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Displaying the reversed string
    printf("Reversed string: %s\n", str);

    // Converting the string to uppercase
    for(i=0; str[i]!='\0'; i++)
    {
        str[i] = toupper(str[i]);
    }

    // Displaying the uppercase string
    printf("Uppercase string: %s\n", str);

    // Converting the string to lowercase
    for(i=0; str[i]!='\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    // Displaying the lowercase string
    printf("Lowercase string: %s\n", str);

    // Counting number of vowels and consonants in the string
    int vow = 0, cons = 0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(isalpha(str[i]))
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            {
                vow++;
            }
            else
            {
                cons++;
            }
        }
    }

    // Displaying the number of vowels and consonants
    printf("Number of vowels: %d\n", vow);
    printf("Number of consonants: %d\n", cons);

    // Concatenating two strings
    char str1[50] = "Hello";
    char str2[50] = "World";
    strcat(str1, str2);

    // Displaying the concatenated string
    printf("Concatenated string: %s\n", str1);

    // Copying one string to another
    char dest[100] = " ";
    strcpy(dest, str);

    // Displaying the copied string
    printf("Copied string: %s\n", dest);

    // Comparing two strings
    char str3[50] = "apple";
    char str4[50] = "APPLE";
    int result = strcmp(str3, str4);

    // Displaying the result of comparison
    if(result==0)
    {
        printf("Strings are equal.\n");
    }
    else if(result<0)
    {
        printf("String 1 is less than String 2.\n");
    }
    else
    {
        printf("String 1 is greater than String 2.\n");
    }

    // Finding the index of a character in a string
    char ch = 'a';
    int index = strchr(str, ch) - str;

    // Displaying the index of the character
    printf("Index of %c in the string: %d\n", ch, index);

    return 0;
}
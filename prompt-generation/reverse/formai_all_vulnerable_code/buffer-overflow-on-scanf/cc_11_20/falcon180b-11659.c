//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];
    char result[200];
    int len, i, j;

    printf("Enter a string: ");
    scanf("%[^\n]", str);
    len = strlen(str);

    // Printing the original string
    printf("Original string: %s\n", str);

    // Reversing the string
    for(i=len-1, j=0; i>=0; i--, j++)
    {
        result[j] = str[i];
    }
    result[j] = '\0';
    printf("Reversed string: %s\n", result);

    // Converting the string to uppercase
    for(i=0; str[i]!='\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase string: %s\n", str);

    // Converting the string to lowercase
    for(i=0; str[i]!='\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase string: %s\n", str);

    // Counting the number of vowels in the string
    int count=0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(isalpha(str[i]))
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            {
                count++;
            }
        }
    }
    printf("Number of vowels: %d\n", count);

    // Replacing a substring with another substring
    char str1[100] = "Hello, World!";
    char str2[100] = "Hi, Universe!";
    char str3[200];

    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);

    printf("Original string: %s\n", str1);
    printf("Replaced string: %s\n", str3);

    return 0;
}
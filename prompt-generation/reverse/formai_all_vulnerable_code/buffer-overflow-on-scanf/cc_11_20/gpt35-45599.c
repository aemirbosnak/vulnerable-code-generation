//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int i, j;

    printf("Welcome to the String Manipulator!\n");
    printf("Enter your first string: ");
    scanf("%s", str1);

    printf("Enter your second string: ");
    scanf("%s", str2);

    printf("\nYour first string is: %s\n", str1);
    printf("Your second string is: %s\n", str2);

    // Concatenation
    strcat(str1, str2);
    printf("\nString concatenation: %s\n", str1);

    // Reversing
    char str3[100];
    strcpy(str3, str1);
    int len = strlen(str3);
    for(i = 0, j = len - 1; i < len/2; i++, j--)
    {
        char temp = str3[i];
        str3[i] = str3[j];
        str3[j] = temp;
    }
    printf("\nString reversal: %s\n", str3);

    // Substring finding
    char substr[100];
    printf("\nEnter substring to search: ");
    scanf("%s", substr);
    if(strstr(str1, substr) != NULL)
    {
        printf("\nFound substring at position %d\n", (int)(strstr(str1, substr) - str1));
    }
    else
    {
        printf("\nSubstring not found.\n");
    }
    
    // Uppercase
    char str4[100];
    strcpy(str4, str1);
    len = strlen(str4);
    for(i = 0; i < len; i++)
    {
        if(str4[i] >= 'a' && str4[i] <= 'z')
            str4[i] = str4[i] - 32;
    }
    printf("\nUppercase string: %s\n", str4);

    // Lowercase
    char str5[100];
    strcpy(str5, str1);
    len = strlen(str5);
    for(i = 0; i < len; i++)
    {
        if(str5[i] >= 'A' && str5[i] <= 'Z')
            str5[i] = str5[i] + 32;
    }
    printf("\nLowercase string: %s\n", str5);

    // Palindrome checking
    char str6[100];
    strcpy(str6, str1);
    len = strlen(str6);
    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        if(str6[i] != str6[j])
        {
            printf("\nNot a palindrome.\n");
            return 0;
        }
    }
    printf("\nYes! It is a palindrome.\n");
    
    printf("\nThank you for using our program!\n");
    return 0;
}
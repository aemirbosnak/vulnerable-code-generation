//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50];
    
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);
    
    printf("Length of string 1: %d\n", strlen(str1));
    printf("Length of string 2: %d\n", strlen(str2));
    
    if(strcmp(str1, str2) == 0)
    {
        printf("String 1 and 2 are equal\n");
    }
    else
    {
        printf("String 1 and 2 are not equal\n");
        strcat(str1, str2);
        printf("Concatenated string: %s\n", str1);
    }
    
    printf("Uppercase string 1: ");
    for(int i=0; i<strlen(str1); i++)
    {
        printf("%c", toupper(str1[i]));
    }
    printf("\n");
    
    printf("Lowercase string 2: ");
    for(int i=0; i<strlen(str2); i++)
    {
        printf("%c", tolower(str2[i]));
    }
    printf("\n");
    
    printf("Reverse string 1: ");
    for(int i=strlen(str1)-1; i>=0; i--)
    {
        printf("%c", str1[i]);
    }
    printf("\n");
    
    int vowels = 0, consonants = 0;
    for(int i=0; i<strlen(str2); i++)
    {
        if(str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u' ||
        str2[i] == 'A' || str2[i] == 'E' || str2[i] == 'I' || str2[i] == 'O' || str2[i] == 'U')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }
    printf("Vowels in string 2: %d\n", vowels);
    printf("Consonants in string 2: %d\n", consonants);
    
    return 0;
}
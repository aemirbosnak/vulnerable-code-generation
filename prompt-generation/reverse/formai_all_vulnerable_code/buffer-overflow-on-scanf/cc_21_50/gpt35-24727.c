//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100], temp;
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    printf("Original string: %s\n", str);

    // Reversing the string
    for(i=0, j=len-1; i<len/2; i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);

    // Converting the string to uppercase
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("Uppercase string: %s\n", str);

    // Finding the length of the string
    len = strlen(str);
    printf("Length of the string: %d\n", len);

    // Counting the vowels in the string
    int vowels = 0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            vowels++;
        }
    }

    printf("Number of vowels in the string: %d\n", vowels);

    // Counting the consonants in the string
    int consonants = 0;
    for(i=0; str[i]!='\0'; i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            {
                continue;
            }
            else
            {
                consonants++;
            }
        }
    }

    printf("Number of consonants in the string: %d\n", consonants);

    // Removing the whitespace from the string
    char no_whitespace[100];
    int k = 0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]!=' ')
        {
            no_whitespace[k] = str[i];
            k++;
        }
    }
    no_whitespace[k] = '\0';

    printf("String with no whitespace: %s\n", no_whitespace);

    // Replacing a character in the string with another character
    char replace_char;
    printf("Enter the character to replace: ");
    scanf(" %c", &temp);
    printf("Enter the character to replace with: ");
    scanf(" %c", &replace_char);

    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]==temp)
        {
            str[i] = replace_char;
        }
    }

    printf("String with replaced character: %s\n", str);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: careful
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100];
    int len, i, j;
    char temp;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    //Reversing a string
    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Reversed string: %s\n", str);

    //Removing spaces from a string
    for(i = 0; str[i]; i++)
    {
        if(isspace(str[i]))
        {
            str[i] = '\0';
        }
    }
    printf("String without spaces: %s\n", str);

    //Converting a string to uppercase
    for(i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
    printf("String in uppercase: %s\n", str);

    //Converting a string to lowercase
    for(i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    printf("String in lowercase: %s\n", str);

    //Counting the number of vowels in a string
    int count = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: creative
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 100

void reverse_string(char *str)
{
    int i, j;
    char temp;
    for(i=0, j=strlen(str)-1; i<j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void capitalize_string(char *str)
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
}

void count_vowels(char *str)
{
    int i, count=0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            count++;
        }
    }
    printf("Number of vowels in the string: %d\n", count);
}

void remove_spaces(char *str)
{
    int i, j;
    for(i=0, j=0; str[i]!='\0'; i++)
    {
        if(str[i]!=' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main()
{
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    capitalize_string(str);
    printf("Capitalized string: %s\n", str);

    count_vowels(str);

    remove_spaces(str);
    printf("String without spaces: %s\n", str);

    return 0;
}
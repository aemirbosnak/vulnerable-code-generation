//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//function to reverse the string
void reverse(char *str)
{
    int len = strlen(str);
    char temp;
    for(int i=0;i<len/2;i++)
    {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

//function to convert the string to uppercase
void toUpperCase(char *str)
{
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        str[i] = toupper(str[i]);
    }
}

//function to translate the string to alien language
void translate(char *str)
{
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = str[i] + 7;
        }
    }
}

int main()
{
    char str[100];
    printf("Enter the string to be translated: ");
    scanf("%s",str);

    //reversing the string
    reverse(str);

    //converting the string to uppercase
    toUpperCase(str);

    //translating the string to alien language
    translate(str);

    printf("The translated string is: %s",str);

    return 0;
}
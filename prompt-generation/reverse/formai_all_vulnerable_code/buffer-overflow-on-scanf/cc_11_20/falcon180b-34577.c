//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: calm
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[100], ch;
    int i=0, j=0, k, len=0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    len = strlen(str);

    printf("\nThe entered string is: %s\n", str);
    printf("The length of the entered string is: %d\n\n", len);

    printf("The string in reverse order is: ");
    for(k=len-1; k>=0; k--)
        printf("%c", str[k]);
    printf("\n\n");

    printf("The string in uppercase is: ");
    for(k=0; k<len; k++)
    {
        if(isalpha(str[k]))
        {
            ch = toupper(str[k]);
            printf("%c", ch);
        }
        else
            printf("%c", str[k]);
    }
    printf("\n\n");

    printf("The string in lowercase is: ");
    for(k=0; k<len; k++)
    {
        if(isalpha(str[k]))
        {
            ch = tolower(str[k]);
            printf("%c", ch);
        }
        else
            printf("%c", str[k]);
    }
    printf("\n\n");

    printf("The string without spaces is: ");
    for(k=0; k<len; k++)
    {
        if(str[k]!=' ')
            printf("%c", str[k]);
    }
    printf("\n\n");

    printf("The string with spaces is: ");
    for(k=0; k<len; k++)
    {
        if(str[k]==' ')
            printf(" ");
        else
            printf("%c", str[k]);
    }
    printf("\n\n");

    printf("The string with every second character reversed is: ");
    for(k=0; k<len; k=k+2)
    {
        ch = str[k];
        str[k] = str[k+1];
        str[k+1] = ch;
    }
    printf("%s\n\n", str);

    printf("The string with every third character reversed is: ");
    for(k=0; k<len; k=k+3)
    {
        ch = str[k];
        str[k] = str[k+2];
        str[k+2] = ch;
    }
    printf("%s\n\n", str);

    return 0;
}
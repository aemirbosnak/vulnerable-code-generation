//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 100

int main()
{
    char str[MAX_LENGTH];
    int i, j, n, count;
    char *token;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    printf("The original string is: %s\n", str);
    printf("The length of the string is: %d\n", n);

    printf("\n");

    printf("The string in uppercase is: ");
    for(i=0; i<n; i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    printf("%s\n", str);

    printf("\n");

    printf("The string in lowercase is: ");
    for(i=0; i<n; i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    printf("%s\n", str);

    printf("\n");

    printf("The reverse of the string is: ");
    for(i=n-1, j=0; i>=0; i--, j++)
    {
        str[j] = str[i];
    }
    str[n] = '\0';
    printf("%s\n", str);

    printf("\n");

    count = 0;
    token = strtok(str, " ");
    while(token!= NULL)
    {
        printf("%s ", token);
        count++;
        if(count == 5)
        {
            break;
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    printf("The number of words in the string is: %d\n", count);

    printf("\n");

    return 0;
}
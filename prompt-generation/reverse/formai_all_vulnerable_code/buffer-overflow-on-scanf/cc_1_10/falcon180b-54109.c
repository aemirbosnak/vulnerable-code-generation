//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_STRING_LENGTH 100

int main()
{
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    char result[MAX_STRING_LENGTH];
    int len1, len2, i, j;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if(len1 > len2)
    {
        for(i=0, j=0; i<len1; i++)
        {
            if(isalpha(str1[i]))
            {
                result[j++] = tolower(str1[i]);
            }
        }
        result[j] = '\0';
    }
    else
    {
        for(i=0, j=0; i<len2; i++)
        {
            if(isalpha(str2[i]))
            {
                result[j++] = tolower(str2[i]);
            }
        }
        result[j] = '\0';
    }

    printf("The common lowercase letters are: %s\n", result);

    return 0;
}
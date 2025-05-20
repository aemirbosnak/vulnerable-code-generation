//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 1024

typedef char* strPtr;

void reverseStr(strPtr str)
{
    char *start, *end;
    start = str;
    end = str + strlen(str) - 1;
    while (start < end)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

char* removeDupChar(strPtr str)
{
    int i, j, k;
    char *newStr = malloc(strlen(str) + 1);
    j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (k = 0; k < j; k++)
        {
            if (newStr[k] == str[i])
            {
                break;
            }
        }
        if (k == j)
        {
            newStr[j] = str[i];
            j++;
        }
    }
    newStr[j] = '\0';
    return newStr;
}

int main()
{
    char str[STR_LEN];
    char *newStr, *reversedStr, *dupRemovedStr;
    printf("Enter a string: ");
    gets(str);
    newStr = removeDupChar(str);
    printf("String without duplicate characters: %s\n", newStr);
    reversedStr = malloc(strlen(str) + 1);
    strcpy(reversedStr, str);
    reverseStr(reversedStr);
    printf("Reversed string: %s\n", reversedStr);
    dupRemovedStr = removeDupChar(reversedStr);
    printf("String without duplicate characters in reversed order: %s\n", dupRemovedStr);
    free(newStr);
    free(reversedStr);
    free(dupRemovedStr);
    return 0;
}
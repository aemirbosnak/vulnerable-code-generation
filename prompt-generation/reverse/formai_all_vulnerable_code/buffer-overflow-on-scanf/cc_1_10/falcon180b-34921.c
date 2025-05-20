//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<limits.h>

#define TRUE   1
#define FALSE  0
#define MAX    100

int main()
{
    int i,j,n,result=0;
    char input[MAX],pattern[MAX];

    printf("Enter the string to search: ");
    scanf("%[^\n]",input);

    printf("Enter the pattern to search for: ");
    scanf("%[^\n]",pattern);

    for(i=0;i<strlen(input);i++)
    {
        input[i]=tolower(input[i]);
        pattern[i]=tolower(pattern[i]);
    }

    for(i=0;i<=strlen(input)-strlen(pattern);i++)
    {
        for(j=0;j<strlen(pattern);j++)
        {
            if(input[i+j]!=pattern[j])
            {
                break;
            }
        }
        if(j==strlen(pattern))
        {
            result=i+1;
            break;
        }
    }

    if(result==0)
    {
        printf("Pattern not found in string.\n");
    }
    else
    {
        printf("Pattern found at position %d.\n",result);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define SIZE 100

int main()
{
    int i,j,k,l;
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%[^\n]",str);

    for(i=0;i<strlen(str);i++)
    {
        if(isalpha(str[i]))
        {
            printf("The character %c is an alphabet\n",str[i]);
        }
        else if(isdigit(str[i]))
        {
            printf("The character %c is a digit\n",str[i]);
        }
        else
        {
            printf("The character %c is a special character\n",str[i]);
        }
    }

    return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define SIZE 100

int main()
{
    int i,j,k,l;
    char str[SIZE];
    printf("Enter a string: ");
    scanf("%[^\n]",str);

    for(i=0;i<strlen(str);i++)
    {
        if(isalpha(str[i]))
        {
            printf("The character %c is an alphabet\n",str[i]);
        }
        else if(isdigit(str[i]))
        {
            printf("The character %c is a digit\n",str[i]);
        }
        else
        {
            printf("The character %c is a special character\n",str[i]);
        }
    }

    return 0;
}
*/
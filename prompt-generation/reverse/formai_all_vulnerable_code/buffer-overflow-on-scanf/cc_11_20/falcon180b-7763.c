//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: accurate
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void main()
{
    int i,j,n,spaces,ch;
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);
    n=strlen(str);
    spaces=n/2;
    printf("\n");
    for(i=0;i<spaces;i++)
    {
        printf(" ");
    }
    for(i=0;i<n;i++)
    {
        ch=tolower(str[i]);
        if(ch>=65 && ch<=90)
        {
            printf("%c",ch);
        }
        else if(ch>=97 && ch<=122)
        {
            printf("%c",ch);
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
    for(i=0;i<spaces;i++)
    {
        printf(" ");
    }
    for(i=n-1;i>=0;i--)
    {
        ch=tolower(str[i]);
        if(ch>=65 && ch<=90)
        {
            printf("%c",ch);
        }
        else if(ch>=97 && ch<=122)
        {
            printf("%c",ch);
        }
        else
        {
            printf(" ");
        }
    }
}
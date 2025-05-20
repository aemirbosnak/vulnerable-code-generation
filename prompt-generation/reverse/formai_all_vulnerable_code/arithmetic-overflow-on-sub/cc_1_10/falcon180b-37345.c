//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    fgets(str,MAX,stdin);
    int len = strlen(str);
    int i,j;
    int count = 0;
    char *p;
    printf("\n");
    for(i=0;i<len;i++)
    {
        if(isalpha(str[i]))
        {
            count++;
        }
    }
    printf("Number of words in the string: %d\n",count+1);
    printf("String in upper case: ");
    for(i=0;i<len;i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    printf("%s\n",str);
    printf("String in lower case: ");
    for(i=0;i<len;i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    printf("%s\n",str);
    printf("String reversed: ");
    for(i=len-1,j=0;i>=0;i--,j++)
    {
        str[j] = str[i];
    }
    str[len] = '\0';
    printf("%s\n",str);
    printf("Substring of the string: ");
    scanf("%s",str);
    printf("Enter the starting position: ");
    scanf("%d",&i);
    printf("Enter the length of the substring: ");
    scanf("%d",&j);
    p = str + i - 1;
    printf("Substring: ");
    while(j--)
    {
        printf("%c",*(p++));
    }
    printf("\n");
    return 0;
}
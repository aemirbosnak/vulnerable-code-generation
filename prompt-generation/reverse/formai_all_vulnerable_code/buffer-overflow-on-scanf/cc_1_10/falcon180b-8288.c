//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int count=0;
char word[MAX];

void translate(char str[50])
{
    int i,j;
    for(i=0;str[i]!='\0';i++)
    {
        if(isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    for(i=0,j=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            word[j]='\0';
            j=0;
        }
        else if(isalpha(str[i]))
        {
            word[j++] = str[i];
        }
    }
    if(j>0)
    {
        word[j]='\0';
        printf("%s : %s\n",str,word);
    }
    else
    {
        printf("Error: Invalid input\n");
    }
}

int main()
{
    char str[50];
    printf("Enter a sentence: ");
    scanf("%s",str);
    translate(str);
    return 0;
}
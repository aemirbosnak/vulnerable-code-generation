//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 1000

void reverse(char str[MAX])
{
    int i,j;
    char temp;

    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

void capitalize(char str[MAX])
{
    int i=0;

    while(str[i]!='\0')
    {
        if(isalpha(str[i]))
        {
            str[i]=toupper(str[i]);
        }
        i++;
    }
}

void shift(char str[MAX],int n)
{
    char temp[MAX];
    int i=0;

    strcpy(temp,str);

    for(i=0;temp[i]!='\0';i++)
    {
        if(isalpha(temp[i]))
        {
            if(isupper(temp[i]))
            {
                temp[i]=tolower(temp[i]);
            }
            else
            {
                temp[i]=toupper(temp[i]);
            }
        }
        else
        {
            temp[i]=temp[i];
        }
    }

    strcpy(str,temp);
}

int main()
{
    char str[MAX];
    int i,n;

    printf("Enter a string: ");
    scanf("%s",str);

    printf("Enter the number of characters to shift: ");
    scanf("%d",&n);

    shift(str,n);

    printf("Shifted string: %s",str);

    return 0;
}
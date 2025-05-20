//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LEN 1000

char str[LEN];

int main()
{
    char ch;
    int i,j;
    int count=0;
    int flag=0;
    char temp[LEN];
    char revStr[LEN];
    char *p;
    char *q;
    char *r;

    printf("Enter a String: ");
    scanf("%[^\n]",str);

    //Removing White Spaces
    p=strtok(str," ");
    while(p!=NULL)
    {
        strcat(temp,p);
        p=strtok(NULL," ");
    }
    strcpy(str,temp);

    //Counting Vowels
    for(i=0;str[i]!='\0';i++)
    {
        ch=tolower(str[i]);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            count++;
        }
    }

    //Reversing the String
    for(i=strlen(str)-1,j=0;i>=0;i--,j++)
    {
        revStr[j]=str[i];
    }
    revStr[j]='\0';

    //Checking Palindrome
    p=str;
    q=revStr;
    while(p!=q)
    {
        if(*p!=*q)
        {
            flag=1;
            break;
        }
        p++;
        q--;
    }

    //Converting to Uppercase
    for(i=0;str[i]!='\0';i++)
    {
        str[i]=toupper(str[i]);
    }

    //Converting to Lowercase
    for(i=0;str[i]!='\0';i++)
    {
        str[i]=tolower(str[i]);
    }

    if(count>0)
    {
        printf("The String contains %d Vowels.\n",count);
    }

    if(flag==0)
    {
        printf("The String is a Palindrome.\n");
    }

    printf("The String in Uppercase is: %s\n",str);

    return 0;
}
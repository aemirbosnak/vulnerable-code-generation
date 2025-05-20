//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: active
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100

int main()
{
    char str[MAX];
    char new_str[MAX];
    int i,j,k;
    char ch;
    int len;

    printf("Enter a string: ");
    scanf("%[^\n]",str);
    len=strlen(str);
    printf("\n%s\n",str);

    //reverse string
    for(i=len-1,j=0;i>=j;i--,j++)
    {
        ch=str[i];
        str[i]=str[j];
        str[j]=ch;
    }
    printf("\nReversed string: %s\n",str);

    //count number of vowels
    int count=0;
    for(i=0;i<len;i++)
    {
        ch=tolower(str[i]);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            count++;
        }
    }
    printf("\nNumber of vowels: %d\n",count);

    //remove spaces and convert to uppercase
    j=0;
    for(i=0;i<len;i++)
    {
        ch=str[i];
        if(ch!=' ')
        {
            new_str[j]=toupper(ch);
            j++;
        }
    }
    new_str[j]='\0';
    printf("\nNew string: %s\n",new_str);

    //check if string is palindrome
    for(i=0,k=len-1;i<k;i++,k--)
    {
        if(str[i]!=str[k])
        {
            printf("\nNot a palindrome\n");
            exit(0);
        }
    }
    printf("\nPalindrome\n");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Recursive ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define max 1000

char stack[max];
int top=-1;

void push(char x)
{
    if(top==max-1)
        printf("\nStack Overflow");
    else
    {
        top++;
        stack[top]=x;
    }
}

char pop()
{
    char x;
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        x=stack[top];
        top--;
    }
    return x;
}

void reverse(char str[])
{
    int i,j;
    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}

void isPalindrome(char str[])
{
    int i,j;
    for(i=0,j=strlen(str)-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            printf("\nNot a Palindrome");
            exit(0);
        }
    }
    printf("\nPalindrome");
}

void main()
{
    char str[max];
    printf("\nEnter a string:");
    scanf("%s",str);
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(!isalpha(str[i]))
        {
            printf("\nNot a Palindrome");
            exit(0);
        }
    }
    reverse(str);
    isPalindrome(str);
}
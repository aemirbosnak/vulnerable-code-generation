//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[100000];
int top=-1;

void push(char c)
{
    stack[++top]=c;
}

void pop()
{
    top--;
}

void print_spaces(int x)
{
    for(int i=1; i<=x; i++)
        printf(" ");
}

int main()
{
    char html[100000];
    printf("Enter the HTML code to be beautified:\n");
    fgets(html, 100000, stdin);
    int len=strlen(html);
    html[len-1]='\0';
    printf("\n");
    int current_indent=0, i=0, flag=0;
    while(html[i] != '\0')
    {
        if(html[i] == '<' && html[i+1] != '/')
        {
            if(flag != 0)
            {
                printf("\n");
                print_spaces(current_indent);
            }
            push(html[i]);
            if(html[i+1] != ' ')
            {
                printf("%c\n", html[i]);
                print_spaces(++current_indent);
            }
            else
            {
                printf("%c", html[i]);
                while(html[i+1] == ' ')
                    i++;
            }
            flag=1;
        }
        else if(html[i] == '<' && html[i+1] == '/')
        {
            pop();
            current_indent-=2;
            printf("\n");
            print_spaces(current_indent);
            printf("%c%c", html[i], html[i+1]);
            while(html[i] != '>')
                printf("%c", html[++i]);
            flag=1;
        }
        else if(html[i] == '>')
        {
            printf("%c\n", html[i]);
            flag=0;
        }
        else
            printf("%c", html[i]);
        i++;
    }
    return 0;
}
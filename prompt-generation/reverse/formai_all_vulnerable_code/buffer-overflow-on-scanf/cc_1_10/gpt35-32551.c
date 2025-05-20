//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j;
    char c;

    printf("Enter a C program and let me parse it:\n\n");
    scanf("%c",&c);

    if(c=='#')
    {
        printf("Woah! Is this a Preprocessor directive?\n");
    }
    else if(c=='i')
    {
        printf("Wait a minute! Is this an import statement?\n");
    }
    else if(c=='f')
    {
        printf("Oh my god! Could this be a for loop?\n");
    }
    else if(c=='w')
    {
        printf("Holy cow! Could this be a while loop?\n");
    }
    else if(c=='d')
    {
        printf("Incredible! Could this be a do-while loop?\n");
    }
    else if(c=='s')
    {
        printf("No way! Is this a switch case statement?\n");
    }
    else if(c=='(')
    {
        printf("Unbelievable! Could this be a function call?\n");
    }
    else if(c=='{')
    {
        printf("This must be the beginning of a function or an if condition!\n");
    }
    else if(c=='}')
    {
        printf("This must be the end of a function or an if condition!\n");
    }
    else
    {
        printf("I have no clue what this is. Maybe a comment or a variable declaration?\n");
    }

    return 0;
}
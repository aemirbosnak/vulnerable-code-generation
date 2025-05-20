//FormAI DATASET v1.0 Category: Syntax parsing ; Style: ephemeral
#include<stdio.h>

int main(){

    char code[1000];
    int i, j, found;

    printf("Enter your C Syntax code here: \n");
    gets(code);

    printf("\nParsing C Syntax Code...\n\n");

    for(i=0;i<strlen(code);i++)
    {
        found=0;
        if(code[i]=='i' && code[i+1]=='n' && code[i+2]=='t')
        {
            printf("Datatype found: int\n");
            found=1;
            i=i+2;
        }
        else if(code[i]=='f' && code[i+1]=='l' && code[i+2]=='o' && code[i+3]=='a' && code[i+4]=='t')
        {
            printf("Datatype found: float\n");
            found=1;
            i=i+4;
        }
        else if(code[i]=='c' && code[i+1]=='h' && code[i+2]=='a' && code[i+3]=='r')
        {
            printf("Datatype found: char\n");
            found=1;
            i=i+3;
        }
        else if(code[i]=='f' && code[i+1]=='o' && code[i+2]=='r' && code[i+3]=='(')
        {
            printf("For loop found\n");
            found=1;
            i=i+3;
        }
        else if(code[i]=='w' && code[i+1]=='h' && code[i+2]=='i' && code[i+3]=='l' && code[i+4]=='e' && code[i+5]=='(')
        {
            printf("While loop found\n");
            found=1;
            i=i+5;
        }
        else if(code[i]=='s' && code[i+1]=='w' && code[i+2]=='i' && code[i+3]=='t' && code[i+4]=='c' && code[i+5]=='h')
        {
            if(code[i+6]=='(')
                printf("Switch case found\n");
            found=1;
            i=i+5;
        }

        if(found==0)
            printf("%c", code[i]);
    }

    return 0;
}
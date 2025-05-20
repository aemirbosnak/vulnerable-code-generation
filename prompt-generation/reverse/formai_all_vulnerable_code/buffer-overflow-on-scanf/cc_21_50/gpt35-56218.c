//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[1000];
    printf("Enter the sentence in Alien Language: ");
    scanf("%[^\n]", input);

    int length = strlen(input);

    for(int i=0; i<length; i++)
    {
        if(isalpha(input[i]))
        {
            if(input[i] == 'a') 
                printf("1");
            else if(input[i] == 'b')
                printf("23");
            else if(input[i] == 'c')
                printf("456");
            else if(input[i] == 'd')
                printf("7890");
            else if(input[i] == 'e')
                printf("qw");
            else if(input[i] == 'f')
                printf("er");
            else if(input[i] == 'g')
                printf("ty");
            else if(input[i] == 'h')
                printf("ui");
            else if(input[i] == 'i')
                printf("op");
            else if(input[i] == 'j')
                printf("a");
            else if(input[i] == 'k')
                printf("b");
            else if(input[i] == 'l')
                printf("c");
            else if(input[i] == 'm')
                printf("d");
            else if(input[i] == 'n')
                printf("e");
            else if(input[i] == 'o')
                printf("f");
            else if(input[i] == 'p')
                printf("g");
            else if(input[i] == 'q')
                printf("h");
            else if(input[i] == 'r')
                printf("i");
            else if(input[i] == 's')
                printf("jkl");
            else if(input[i] == 't')
                printf("mno");
            else if(input[i] == 'u')
                printf("pqrs");
            else if(input[i] == 'v')
                printf("tuv");
            else if(input[i] == 'w')
                printf("wxyz");
            else if(input[i] == 'x')
                printf(".");
            else if(input[i] == 'y')
                printf(",");
            else if(input[i] == 'z')
                printf("?");
        }
        else
            printf("%c", input[i]);
    }

    return 0;
}
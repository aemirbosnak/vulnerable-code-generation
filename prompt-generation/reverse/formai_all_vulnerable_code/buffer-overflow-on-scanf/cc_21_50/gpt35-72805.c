//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

void translate(char message[])
{
    int i=0,j=0;
    char word[100];
    while(message[i]!='\0')
    {
        if(message[i]!=' ')
        {
            word[j]=message[i];
            j++;
        }
        else
        {
            word[j]='\0';
            j=0;
            if(strcmp(word,"zix")==0)
            {
                printf("a");
            }
            else if(strcmp(word,"piu")==0)
            {
                printf("b");
            }
            else if(strcmp(word,"mux")==0)
            {
                printf("c");
            }
            else if(strcmp(word,"dox")==0)
            {
                printf("d");
            }
            else if(strcmp(word,"rax")==0)
            {
                printf("e");
            }
            else if(strcmp(word,"tux")==0)
            {
                printf("f");
            }
            else if(strcmp(word,"dax")==0)
            {
                printf("g");
            }
            else if(strcmp(word,"vix")==0)
            {
                printf("h");
            }
            else if(strcmp(word,"bin")==0)
            {
                printf("i");
            }
            else if(strcmp(word,"sux")==0)
            {
                printf("j");
            }
            else if(strcmp(word,"lix")==0)
            {
                printf("k");
            }
            else if(strcmp(word,"nax")==0)
            {
                printf("l");
            }
            else if(strcmp(word,"wux")==0)
            {
                printf("m");
            }
            else if(strcmp(word,"ryx")==0)
            {
                printf("n");
            }
            else if(strcmp(word,"pix")==0)
            {
                printf("o");
            }
            else if(strcmp(word,"mix")==0)
            {
                printf("p");
            }
            else if(strcmp(word,"hix")==0)
            {
                printf("q");
            }
            else if(strcmp(word,"six")==0)
            {
                printf("r");
            }
            else if(strcmp(word,"tix")==0)
            {
                printf("s");
            }
            else if(strcmp(word,"lix")==0)
            {
                printf("t");
            }
            else if(strcmp(word,"cix")==0)
            {
                printf("u");
            }
            else if(strcmp(word,"mox")==0)
            {
                printf("v");
            }
            else if(strcmp(word,"kix")==0)
            {
                printf("w");
            }
            else if(strcmp(word,"pax")==0)
            {
                printf("x");
            }
            else if(strcmp(word,"rix")==0)
            {
                printf("y");
            }
            else if(strcmp(word,"sim")==0)
            {
                printf("z");
            }
        }
        i++;
    }
    word[j]='\0';
    j=0;
    if(strcmp(word,"zix")==0)
    {
        printf("a");
    }
    else if(strcmp(word,"piu")==0)
    {
        printf("b");
    }
    else if(strcmp(word,"mux")==0)
    {
        printf("c");
    }
    else if(strcmp(word,"dox")==0)
    {
        printf("d");
    }
    else if(strcmp(word,"rax")==0)
    {
        printf("e");
    }
    else if(strcmp(word,"tux")==0)
    {
        printf("f");
    }
    else if(strcmp(word,"dax")==0)
    {
        printf("g");
    }
    else if(strcmp(word,"vix")==0)
    {
        printf("h");
    }
    else if(strcmp(word,"bin")==0)
    {
        printf("i");
    }
    else if(strcmp(word,"sux")==0)
    {
        printf("j");
    }
    else if(strcmp(word,"lix")==0)
    {
        printf("k");
    }
    else if(strcmp(word,"nax")==0)
    {
        printf("l");
    }
    else if(strcmp(word,"wux")==0)
    {
        printf("m");
    }
    else if(strcmp(word,"ryx")==0)
    {
        printf("n");
    }
    else if(strcmp(word,"pix")==0)
    {
        printf("o");
    }
    else if(strcmp(word,"mix")==0)
    {
        printf("p");
    }
    else if(strcmp(word,"hix")==0)
    {
        printf("q");
    }
    else if(strcmp(word,"six")==0)
    {
        printf("r");
    }
    else if(strcmp(word,"tix")==0)
    {
        printf("s");
    }
    else if(strcmp(word,"lix")==0)
    {
        printf("t");
    }
    else if(strcmp(word,"cix")==0)
    {
        printf("u");
    }
    else if(strcmp(word,"mox")==0)
    {
        printf("v");
    }
    else if(strcmp(word,"kix")==0)
    {
        printf("w");
    }
    else if(strcmp(word,"pax")==0)
    {
        printf("x");
    }
    else if(strcmp(word,"rix")==0)
    {
        printf("y");
    }
    else if(strcmp(word,"sim")==0)
    {
        printf("z");
    }
}

int main()
{
    char message[100];
    printf("Enter the message in C Alien Language (words separated by spaces): ");
    scanf("%[^\n]s", message);
    printf("\nThe translated message is: ");
    translate(message);
    printf("\n");
    return 0;
}
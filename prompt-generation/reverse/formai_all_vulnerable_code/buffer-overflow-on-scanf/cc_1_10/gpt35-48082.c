//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char c_cat_language[50], human_language[50], expression[50][50] = {"meow", "purr", "hiss", "scratch"};
    
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please input the sentence in C Cat language: ");
    scanf("%[^\n]", c_cat_language);

    // Removing the newline character from input
    char c = getchar();
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }

    printf("Translating...\n");

    // Breaking the input into words
    char *words = strtok(c_cat_language, " ");

    printf("In English, this means: ");

    // Translating each word
    while(words != NULL)
    {
        if(strcmp(words, "meow") == 0)
        {
            strcat(human_language, expression[0]);
        }
        else if(strcmp(words, "purr") == 0)
        {
            strcat(human_language, expression[1]);
        }
        else if(strcmp(words, "hiss") == 0)
        {
            strcat(human_language, expression[2]);
        }
        else if(strcmp(words, "scratch") == 0)
        {
            strcat(human_language, expression[3]);
        }
        else
        {
            strcat(human_language, "???");
        }
        
        strcat(human_language, " ");

        words = strtok(NULL, " ");
    }

    printf("%s\n", human_language);

    printf("Thank you for using the C Cat Language Translator!\n");

    return 0;
}
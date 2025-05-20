//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include<stdio.h>
#include<string.h>

// This program acts as a C-Cat Language translator

int main()
{
    char ccatString[1000];
    char transString[1000];

    // Taking input from user in C-Cat Language
    printf("Enter a sentence in C-Cat Language: ");
    fgets(ccatString, 1000, stdin);

    // Initializing the variables for translation
    char *token;
    char *rest = ccatString;
    int index = 0;

    // Translating one word at a time
    while ((token = strtok_r(rest, " ", &rest)))
    {
        if (token[0] == 'M' && token[1] == 'i' && token[2] == 'a' && token[3] == 'u')
        {
            transString[index++] = 'C';
            transString[index++] = 'a';
            transString[index++] = 't';
            transString[index++] = ' ';
        }
        else if (token[0] == 'P' && token[1] == 'u' && token[2] == 'r' && token[3] == 'r')
        {
            transString[index++] = 'K';
            transString[index++] = 'i';
            transString[index++] = 't';
            transString[index++] = 't';
            transString[index++] = 'y';
            transString[index++] = ' ';
        }
        else if (token[0] == 'M' && token[1] == 'e' && token[2] == 'o' && token[3] == 'w')
        {
            transString[index++] = 'H';
            transString[index++] = 'e';
            transString[index++] = 'l';
            transString[index++] = 'l';
            transString[index++] = 'o';
            transString[index++] = ' ';
        }
        else
        {
            strcat(transString, token);
            strcat(transString, " ");
            index += (strlen(token) + 1);
        }
    }

    // Printing the translated string
    printf("The translated sentence is: %s", transString);

    return 0;
}
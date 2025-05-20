//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to translate C cat language to English
char* cCatTranslator(char *cCatCode){

    int length = strlen(cCatCode);
    char *englishCode = malloc(length);

    for(int i=0; i < length; i++)
    {
        if(cCatCode[i] == ':')
            strcat(englishCode,"for ");
        else if(cCatCode[i] == ';')
            strcat(englishCode,";");
        else if(cCatCode[i] == '!')
            strcat(englishCode,"not ");
        else if(cCatCode[i] == '~')
            strcat(englishCode,"-");
        else if(cCatCode[i] == '(')
            strcat(englishCode,"(");
        else if(cCatCode[i] == ')')
            strcat(englishCode,")");
        else if(cCatCode[i] == '/')
            strcat(englishCode,"/");
        else if(cCatCode[i] == '&')
            strcat(englishCode,"and ");
        else if(cCatCode[i] == '|')
            strcat(englishCode,"or ");
        else if(cCatCode[i] == '{')
            strcat(englishCode,"{");
        else if(cCatCode[i] == '}')
            strcat(englishCode,"}");
        else if(cCatCode[i] == '#')
            strcat(englishCode,"include ");
        else if(cCatCode[i] == '@')
            strcat(englishCode,"int ");
        else if(cCatCode[i] == '^')
            strcat(englishCode,"^");
        else if(cCatCode[i] == '<')
            strcat(englishCode,"less than ");
        else if(cCatCode[i] == '>')
            strcat(englishCode,"greater than ");
    }
    return englishCode;
}

int main()
{
    char cCatCode[1000];
    printf("Welcome to C Cat Language Translator \n\n");
    printf("Enter the C Cat code: ");
    scanf("%[^\n]s",cCatCode);

    char *englishCode = cCatTranslator(cCatCode);
    printf("\nTranslated C Cat code is: \n%s",englishCode);
    free(englishCode);

    return 0;
}
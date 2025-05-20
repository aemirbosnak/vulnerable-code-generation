//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100];
    int i, j, choice;
    
    printf("Welcome to the C Alien Language Translator!\n\n");
    printf("Please enter your message in the alien language:\n");
    scanf("%s", input);
    
    printf("Please enter your choice of translation:\n");
    printf("1. Translate to English\n");
    printf("2. Translate to C Alien Language\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: // Translate to English
            for(i=0, j=0; i<strlen(input); i++, j++)
            {
                if(input[i] == 'A')
                {
                    output[j] = 'Z';
                    continue;
                }
                if(input[i] == 'a')
                {
                    output[j] = 'z';
                    continue;
                }
                output[j] = input[i] - 1;
            }
            output[j] = '\0';
            printf("The translated message in English is:\n%s\n", output);
            break;
            
        case 2: // Translate to C Alien Language
            for(i=0, j=0; i<strlen(input); i++, j++)
            {
                if(input[i] == 'Z')
                {
                    output[j] = 'A';
                    continue;
                }
                if(input[i] == 'z')
                {
                    output[j] = 'a';
                    continue;
                }
                output[j] = input[i] + 1;
            }
            output[j] = '\0';
            printf("The translated message in C Alien Language is:\n%s\n", output);
            break;
            
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}
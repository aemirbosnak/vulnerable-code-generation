//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char phrase[1000];
    int j, len;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a phrase in the C Alien Language to be translated: ");
    scanf("%s", phrase);

    len = strlen(phrase);

    for(j=0; j<len; j++)
    {
        if(phrase[j] == '0')
        {
            printf("Beep Boop ");
        }
        else if(phrase[j] == '1')
        {
            printf("Boop Beep ");
        }
        else if(phrase[j] == '2')
        {
            printf("Bloop Beep ");
        }
        else if(phrase[j] == '3')
        {
            printf("Beep Bloop ");
        }
        else if(phrase[j] == '4')
        {
            printf("Bloop Bloop ");
        }
        else if(phrase[j] == '5')
        {
            printf("Beep Beep ");
        }
        else if(phrase[j] == '6')
        {
            printf("Boop Boop ");
        }
        else if(phrase[j] == '7')
        {
            printf("Blop Blop ");
        }
        else if(phrase[j] == '8')
        {
            printf("Beep Blop ");
        }
        else if(phrase[j] == '9')
        {
            printf("Boop Blop ");
        }
        else
        {
            printf("Unknown character");
        }
    }

    printf("\nThank you for using the Alien Language Translator! Hope to see you soon!");

    return 0;
}
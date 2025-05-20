//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char cCat[50];
    printf("Enter a sentence in C Cat Language: ");
    scanf("%[^\n]", cCat);

    int length = strlen(cCat);
    char translated[50];
    int i = 0, j = 0;
    while (i < length)
    {
        if (cCat[i] == 'm' && cCat[i+1] == 'e')
        {
            translated[j++] = 'I';
            i += 2;
        }
        else if (cCat[i] == 'm' && cCat[i+1] == 'y')
        {
            translated[j++] = 'you';
            i += 2;
        }
        else if (cCat[i] == 'y' && cCat[i+1] == 'o' && cCat[i+2] == 'u' && cCat[i+3] == 'r')
        {
            translated[j++] = 'I\'m';
            i += 4;
        }
        else if (cCat[i] == 'a' && cCat[i+1] == 'm')
        {
            translated[j++] = 'you are';
            i += 2;
        }
        else if (cCat[i] == 'm' && cCat[i+1] == 'y' && cCat[i+2] == 's' && cCat[i+3] == 'e' && cCat[i+4] == 'l' && cCat[i+5] == 'f')
        {
            translated[j++] = 'yourself';
            i += 6;
        }
        else if (cCat[i] == '?')
        {
            translated[j++] = '?';
            i++;
        }
        else if (cCat[i] == '!')
        {
            translated[j++] = '!';
            i++;
        }
        else
        {
            translated[j++] = cCat[i++];
        }
    }
    translated[j] = '\0';

    printf("Your sentence in English: %s\n", translated);

    return 0;
}
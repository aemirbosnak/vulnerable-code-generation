//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char cat[1000], translated[1000], word[100], symbol[10];
    printf("Enter a sentence in Cat Language: ");
    gets(cat);
    int index = 0, tIndex = 0, len = strlen(cat), wIndex = 0, sIndex = 0;
    while (index < len)
    {
        sIndex = 0;
        while (cat[index] != ' ' && index < len)
        {
            symbol[sIndex] = cat[index];
            sIndex++;
            index++;
        }
        symbol[sIndex] = '\0';
        if (strcmp(symbol, "meow") == 0)
        {
            translated[tIndex++] = 'h';
            translated[tIndex++] = 'e';
            translated[tIndex++] = 'l';
            translated[tIndex++] = 'l';
            translated[tIndex++] = 'o';
        }
        else if (strcmp(symbol, "purr") == 0)
        {
            translated[tIndex++] = 'g';
            translated[tIndex++] = 'o';
            translated[tIndex++] = 'o';
            translated[tIndex++] = 'd';
            translated[tIndex++] = 'b';
            translated[tIndex++] = 'y';
            translated[tIndex++] = 'e';
        }
        else
        {
            wIndex = 0;
            while (symbol[wIndex] != '\0')
            {
                translated[tIndex] = symbol[wIndex];
                tIndex++;
                wIndex++;
            }
        }
        translated[tIndex++] = ' ';
        index++;
    }
    translated[--tIndex] = '\0';
    printf("Translated sentence: %s", translated);
    return 0;
}
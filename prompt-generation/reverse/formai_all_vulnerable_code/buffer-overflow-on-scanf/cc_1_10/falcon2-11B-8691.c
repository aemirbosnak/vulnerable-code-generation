//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN 100
#define MAX_SENTENCE 100

char *cat_translation(char *input);

int main()
{
    char input[MAX_LEN];
    char output[MAX_SENTENCE];
    int i, j;

    printf("Enter a sentence to translate to Cat Language: ");
    scanf("%s", input);

    printf("Translation: %s\n", cat_translation(input));

    return 0;
}

char *cat_translation(char *input)
{
    char *translated = (char*)malloc(MAX_LEN * sizeof(char));
    int len = strlen(input);
    int i, j;

    translated[0] = '\0';
    for (i = 0; i < len; i++)
    {
        if (isalpha(input[i]))
        {
            char upper_case = toupper(input[i]);
            char lower_case = tolower(input[i]);
            char cat_sound ='m';

            if (islower(upper_case))
            {
                if (isupper(lower_case))
                {
                    cat_sound = 'r';
                }
            }

            translated[i] = cat_sound;
        }
        else
        {
            translated[i] = input[i];
        }
    }

    translated[len] = '\0';
    return translated;
}
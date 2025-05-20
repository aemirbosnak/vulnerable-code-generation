//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: invasive
#include <stdio.h>
#include <string.h>

int main()
{
    char alien_phrases[100][100];
    char human_phrases[100][100];
    int i, n;

    printf("---Alien Language Translator---\n\n");

    printf("Enter the number of phrases to translate: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("\nEnter a phrase in Alien language: ");
        scanf("%s", alien_phrases[i]);
    }

    for(i=0; i<n; i++)
    {
        if(strcmp(alien_phrases[i], "Kl'rvuton") == 0)
        {
            strcpy(human_phrases[i], "Hello");
        }
        else if(strcmp(alien_phrases[i], "N'resht") == 0)
        {
            strcpy(human_phrases[i], "Goodbye");
        }
        else if(strcmp(alien_phrases[i], "F'talnus") == 0)
        {
            strcpy(human_phrases[i], "Thank you");
        }
        else if(strcmp(alien_phrases[i], "G'naxlot") == 0)
        {
            strcpy(human_phrases[i], "Sorry");
        }
        else
        {
            strcpy(human_phrases[i], "Unknown phrase");
        }
    }

    printf("\n---Translation---");
    for(i=0; i<n; i++)
    {
        printf("\nAlien Language: %s", alien_phrases[i]);
        printf("\nHuman Language: %s\n", human_phrases[i]);
    }

    return 0;
}
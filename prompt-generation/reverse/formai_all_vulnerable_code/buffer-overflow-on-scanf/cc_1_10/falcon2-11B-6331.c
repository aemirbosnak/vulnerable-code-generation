//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include<stdio.h>
#include<string.h>

int main()
{
    char words[1000];
    int max_char = 0;
    int i, j;

    printf("Enter the words : ");
    scanf("%s", words);

    max_char = strlen(words);

    char *seen[max_char];
    for (i = 0; i < max_char; i++)
    {
        seen[i] = 0;
    }

    while (words[i]!= '\0')
    {
        i = 0;
        for (j = 0; j < max_char; j++)
        {
            if (words[i] == seen[j])
            {
                seen[j]++;
                break;
            }
            i++;
        }
    }

    while (words[i]!= '\0')
    {
        i = 0;
        for (j = 0; j < max_char; j++)
        {
            if (words[i] == seen[j])
            {
                seen[j]++;
                break;
            }
            i++;
        }
    }

    printf("Word\tFrequency\n");

    for (i = 0; i < max_char; i++)
    {
        printf("%s\t%d\n", seen[i], seen[i]);
    }

    return 0;
}
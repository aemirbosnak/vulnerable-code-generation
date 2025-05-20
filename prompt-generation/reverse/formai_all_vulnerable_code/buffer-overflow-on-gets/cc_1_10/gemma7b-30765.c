//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int i, j, k, speed, words = 0, characters = 0;
    char str[1000];

    start = time(NULL);

    printf("Type as quickly as you can a sentence of at least 20 words: ");

    gets(str);

    end = time(NULL);

    words = words_count(str);
    characters = characters_count(str);

    speed = (characters / (end - start)) * 60;

    printf("\nYour typing speed is: %d words per minute.\n", speed);

    printf("Number of characters typed: %d\n", characters);

    printf("Number of words typed: %d\n", words);

    return 0;
}

int words_count(char *str)
{
    int i = 0, words = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
        {
            words++;
        }
        i++;
    }

    return words;
}

int characters_count(char *str)
{
    int i = 0, characters = 0;

    while (str[i] != '\0')
    {
        characters++;
        i++;
    }

    return characters;
}
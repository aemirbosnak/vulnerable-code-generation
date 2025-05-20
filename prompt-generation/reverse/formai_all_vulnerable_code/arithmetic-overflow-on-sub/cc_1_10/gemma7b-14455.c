//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int timeTaken, wordsTyped, charactersTyped;
    char text[1000];

    start = clock();

    printf("Welcome to the Future Text Speed Test!\n");
    printf("Please type as quickly as you can:\n");
    fgets(text, 1000, stdin);

    end = clock();

    timeTaken = (int)(end - start) / CLOCKS_PER_SEC;
    wordsTyped = words_per_minute(text);
    charactersTyped = characters_per_minute(text);

    printf("Your typing speed is:\n");
    printf("  - Words per minute: %d\n", wordsTyped);
    printf("  - Characters per minute: %d\n", charactersTyped);
    printf("  - Time taken: %.2f seconds\n", (double)timeTaken);

    return 0;
}

int words_per_minute(char *text)
{
    int words = 0, characters = 0, i = 0;

    while (text[i] != '\0')
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            words++;
        }
        characters++;
        i++;
    }

    return words * 60 / characters;
}

int characters_per_minute(char *text)
{
    int characters = 0, i = 0;

    while (text[i] != '\0')
    {
        characters++;
        i++;
    }

    return characters * 60 / clock();
}
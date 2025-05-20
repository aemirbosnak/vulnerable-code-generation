//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int i, words, characters, speed;
    char text[1000];

    // Start the timer
    start = clock();

    // Get the text to be typed
    printf("Please type the following text as quickly as possible:\n\n");
    gets(text);

    // Stop the timer
    end = clock();

    // Calculate the number of words and characters
    words = words_count(text);
    characters = characters_count(text);

    // Calculate the typing speed
    speed = (characters * 60) / (end - start);

    // Print the results
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    printf("Typing speed: %d words per minute\n", speed);

    return 0;
}

int words_count(char *text)
{
    int words = 0;
    char *p = text;

    while (p)
    {
        if (*p == ' ' || *p == '\n' || *p == '\t')
        {
            words++;
        }
        p++;
    }

    return words;
}

int characters_count(char *text)
{
    int characters = 0;
    char *p = text;

    while (p)
    {
        if (*p)
        {
            characters++;
        }
        p++;
    }

    return characters;
}
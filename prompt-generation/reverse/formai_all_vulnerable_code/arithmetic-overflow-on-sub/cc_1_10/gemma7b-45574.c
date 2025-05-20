//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    double elapsed_time;

    // Declare variables for the typing speed test
    char text[] = "The quick brown fox jumps over the lazy dog.";
    int words_per_minute = 0;
    int characters_per_second = 0;

    // Start the timer
    start = clock();

    // User types the text
    printf("Type the following text as quickly as you can:\n\n");
    printf("%s", text);

    // End the timer
    end = clock();

    // Calculate the elapsed time
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the words per minute
    words_per_minute = (int)(words_per_minute_calc(text) / elapsed_time) * 60;

    // Calculate the characters per second
    characters_per_second = (int)(characters_per_second_calc(text) / elapsed_time) * 1000;

    // Print the results
    printf("\nYour typing speed is:\n");
    printf("  - Words per minute: %d\n", words_per_minute);
    printf("  - Characters per second: %d\n", characters_per_second);

    return 0;
}

int words_per_minute_calc(char *text)
{
    int words = 0;
    char *word_start = text;

    while (word_start = strstr(word_start, " "))
    {
        words++;
        word_start++;
    }

    return words;
}

int characters_per_second_calc(char *text)
{
    int characters = 0;
    char *character_start = text;

    while (character_start = strchr(character_start, " "))
    {
        characters++;
        character_start++;
    }

    return characters;
}
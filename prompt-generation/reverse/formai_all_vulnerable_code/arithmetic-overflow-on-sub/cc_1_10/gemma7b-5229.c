//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    double duration, words, characters;
    char text[1000];

    // Get the start time
    start = time(NULL);

    // Prompt the user to enter text
    printf("Enter text: ");
    fgets(text, 1000, stdin);

    // Get the end time
    end = time(NULL);

    // Calculate the duration
    duration = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the number of words and characters
    words = words_count(text);
    characters = characters_count(text);

    // Print the results
    printf("Time taken: %.2lf seconds\n", duration);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    return 0;
}

int words_count(char *text)
{
    int words = 0;
    char *word = NULL;

    word = strtok(text, " ");

    while (word)
    {
        words++;
        word = strtok(NULL, " ");
    }

    return words;
}

int characters_count(char *text)
{
    int characters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        characters++;
    }

    return characters;
}
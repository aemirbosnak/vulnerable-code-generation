//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int speed, words, characters;
    char text[1000];

    // Start the timer
    start = time(NULL);

    // Get the text from the user
    printf("Type a text below: ");
    gets(text);

    // End the timer
    end = time(NULL);

    // Calculate the time taken
    speed = (end - start) * 60 / words;

    // Calculate the number of words and characters
    words = words_count(text);
    characters = characters_count(text);

    // Print the results
    printf("Your typing speed is: %d words per minute.\n", speed);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    return 0;
}

int words_count(char *text)
{
    int words = 0;
    char *word = NULL;

    word = strtok(text, " \n\t");

    while (word)
    {
        words++;
        word = strtok(NULL, " \n\t");
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
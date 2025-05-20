//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    char text[1000] = "The post-apocalyptic world was a bleak one. The sun shone mercilessly, casting long shadows across the barren land. The wind howled, carrying with it the scent of smoke and decay. The remnants of once-great cities stood as silent testament to the past.";

    start = time(NULL);
    printf("Type the following text as quickly as possible:\n\n%s", text);
    fflush(stdout);

    // Replace this line with your own code to measure typing speed
    char input[1000];
    scanf("%s", input);

    end = time(NULL);

    printf("Your typing speed is: %d words per minute.\n", (words_per_minute(start, end, input, text)));
    return 0;
}

int words_per_minute(time_t start, time_t end, char *input, char *text)
{
    int words = count_words(text);
    int chars = count_chars(input);
    int time_taken = end - start;

    return (words * chars) / time_taken * 60;
}

int count_words(char *text)
{
    int words = 0;
    char *p = text;

    while (p)
    {
        p = strchr(p, ' ') ? strchr(p, ' ') : NULL;
        if (p)
        {
            words++;
            p++;
        }
    }

    return words;
}

int count_chars(char *text)
{
    int chars = 0;
    char *p = text;

    while (p)
    {
        p = strchr(p, ' ') ? strchr(p, ' ') : NULL;
        if (p)
        {
            chars++;
            p++;
        }
    }

    return chars;
}
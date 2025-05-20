//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char typed_string[100];
    char random_string[100];
    int num_chars = 0;
    int i = 0;
    int j = 0;
    int start_time, end_time, typing_time, typing_speed;

    // Generate random string for typing test
    srand(time(0));
    for (i = 0; i < 7; i++)
    {
        random_string[i] = 'a' + rand() % 26;   // Generate lowercase letters randomly
    }
    random_string[i] = '\0';

    printf("Type the following string as fast as you can:\n\n");
    printf("%s\n\n", random_string);

    // Measure time taken to complete the typing test
    start_time = time(0);
    fgets(typed_string, 100, stdin);   // Take input from user
    end_time = time(0);

    typing_time = end_time - start_time;   // Calculate typing time

    // Calculate typing speed in characters per minute
    num_chars = strlen(random_string);
    typing_speed = (num_chars * 60) / typing_time;

    // Count number of correct characters
    for (i = 0; i < num_chars; i++)
    {
        if (random_string[i] == typed_string[i])
        {
            j++;
        }
    }

    printf("\nTyping speed: %d characters per minute\n", typing_speed);
    printf("Number of correct characters: %d out of %d\n", j, num_chars);

    return 0;
}
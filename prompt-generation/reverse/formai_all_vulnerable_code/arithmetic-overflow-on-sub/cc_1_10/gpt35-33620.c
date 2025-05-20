//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char input[50];
    int i, words = 0, seconds, speed;
    clock_t start_time, end_time;

    printf("Welcome to the Typing Speed Test! \n");
    printf("Type the following romantic poem as fast as you can: \n\n");
    printf("My love for you is like a rose, \n");
    printf("Ever blooming, never grows old. \n");
    printf("With every beat of my heart, \n");
    printf("I vow to never let us grow apart. \n\n");

    start_time = clock(); // time starts

    scanf("%[^\n]", input); // accepting input from user

    end_time = clock(); // time ends

    // count number of words in the input
    for(i = 0; input[i] != '\0'; i++)
    {
        if(input[i] == ' ' && input[i-1] != ' ')
            words++;
    }
    words++; // last word

    seconds = (end_time - start_time) / CLOCKS_PER_SEC;

    speed = (words / seconds) * 60; // wpm calculation

    printf("\nYou typed at a speed of %d words per minute! \n", speed);

    // romantic message based on typing speed
    if(speed > 60)
    {
        printf("Your typing speed is as fast as my heart beats for you! \n");
    }
    else if(speed > 40)
    {
        printf("You are slow and steady like a turtle, but just as cute! \n");
    }
    else
    {
        printf("Your typing speed is slower than a snail, but you're still the love of my life! \n");
    }

    return 0;
}
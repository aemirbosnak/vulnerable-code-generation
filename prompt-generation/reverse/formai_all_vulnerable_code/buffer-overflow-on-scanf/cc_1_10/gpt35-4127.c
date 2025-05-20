//FormAI DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>

/* This program helps you determine if you're a hacker or not. */

int main()
{
    int skills = 0;  // initialize skills as 0
    int caffeine = 0;  // initialize caffeine as 0

    printf("Welcome to \"Are You a Hacker?\"\n");
    printf("Answer the following questions with 1 for yes or 0 for no.\n");

    printf("Do you wear a black hoodie while coding? ");
    int hoodie;
    scanf("%d", &hoodie);

    if (hoodie == 1) {
        skills += 10;
    }

    printf("Do you drink energy drinks like they're going out of style? ");
    int energy;
    scanf("%d", &energy);

    if (energy == 1) {
        caffeine += 10;
    }

    printf("Do you have a sticker that says \"I'm a hacker\" on your laptop? ");
    int sticker;
    scanf("%d", &sticker);

    if (sticker == 1) {
        skills += 20;
    }

    printf("Can you type more than 100 words per minute? ");
    int speed;
    scanf("%d", &speed);

    if (speed == 1) {
        skills += 15;
    }

    printf("Do you secretly dream of taking down the NSA with a single line of code? ");
    int dream;
    scanf("%d", &dream);

    if (dream == 1) {
        skills += 30;
    }

    printf("On a scale of 1-10, how much caffeine have you had today? ");
    scanf("%d", &caffeine);

    if (caffeine > 10) {
        printf("Woah there, slow down on the caffeine!\n");
    }

    printf("Your hacking skills: %d\n", skills);

    if (skills >= 50) {
        printf("Congratulations, you're officially a hacker!\n");
    } else {
        printf("Sorry, looks like you still have some work to do.\n");
    }

    return 0;
}
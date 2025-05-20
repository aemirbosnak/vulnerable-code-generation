//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    char name[20];
    int age;
    float balance;
    enum Mood { SAD, HAPPY, CHEERFUL };
    enum Mood mood;

    // Get user input
    printf("What is your name? ");
    scanf("%s", name);

    printf("How old are you? ");
    scanf("%d", &age);

    printf("What's your current balance? ");
    scanf("%f", &balance);

    // Determine mood
    if (age >= 18)
    {
        mood = HAPPY;
    }
    else
    {
        mood = SAD;
    }

    // Display information
    printf("Hello, %s! You are %d years old and have a balance of $%.2f.\n", name, age, balance);

    // Print mood
    switch (mood)
    {
        case HAPPY:
            printf("You're happy as a clam! :D\n");
            break;
        case SAD:
            printf("You're sad as a wet noodle. :(\n");
            break;
        case CHEERFUL:
            printf("You're cheerful as a bouncing ferret. :)\n");
            break;
    }

    return 0;
}
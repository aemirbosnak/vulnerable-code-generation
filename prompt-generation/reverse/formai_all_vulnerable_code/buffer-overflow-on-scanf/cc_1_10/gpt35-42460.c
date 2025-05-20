//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>

int main() {
    char name[100];
    printf("What's your name? ");
    scanf("%s", name);
    printf("Welcome, %s! Let's have some fun with C programming.\n\n", name);

    printf("What's your favorite number? ");
    int favorite;
    scanf("%d", &favorite);
    printf("Cool, %d is a good number!\n\n", favorite);

    printf("Want to play a game? I'm thinking of a number between 1 and 10...\n");
    int guess;
    int answer = 5;
    do {
        printf("What's your guess? ");
        scanf("%d", &guess);
        if (guess < answer) {
            printf("Nope, too low. Try again!\n");
        } else if (guess > answer) {
            printf("Nope, too high. Try again!\n");
        }
    } while (guess != answer);
    printf("Congratulations, you guessed it!\n\n");

    printf("Okay, now it's my turn to guess.\n");
    int number = 1;
    printf("Is your number %d? (y/n) ", number);
    char response;
    scanf(" %c", &response);
    while (response != 'y') {
        printf("No? Okay, how about %d? (y/n) ", ++number);
        scanf(" %c", &response);
    }
    printf("Told you I was good at this game!\n\n");

    printf("Now let's do some math. Give me two numbers.\n");
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x, y, x - y);
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d / %d = %d (with remainder %d)\n\n", x, y, x / y, x % y);

    printf("Okay, last thing. Let's see your initials in ASCII art!\n\n");
    printf("  ____  \n");
    printf(" / __ \\ \n");
    printf("/ /_/ / \\\n");
    printf("\\__,_/\\_\\\n\n");

    printf("Thanks for playing, %s! Goodbye.\n", name);
    return 0;
}
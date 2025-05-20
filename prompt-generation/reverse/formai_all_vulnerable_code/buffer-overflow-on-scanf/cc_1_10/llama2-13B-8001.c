//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PRINT_COLOR(color) \
    printf("%s", #color); \
    fflush(stdout); \
    system("color");

int main() {
    PRINT_COLOR(red);
    printf("WELCOME TO THE MOST EPIC C PROGRAM EVER! 🎉\n");

    PRINT_COLOR(green);
    printf("I'm feeling lucky today, so let's play a game! 🍀\n");

    PRINT_COLOR(blue);
    printf("Here's your first question: What is the capital of France? 🇫🇷\n");

    int answer = get_answer();

    PRINT_COLOR(yellow);
    if (answer == 1) {
        printf("Correct! The capital of France is Paris. 💡\n");
    } else {
        PRINT_COLOR(red);
        printf("Oops, that's incorrect. The correct answer is Paris. 😔\n");
    }

    PRINT_COLOR(purple);
    printf("Now, let's play a guessing game! 🎁\n");

    int guess = 0;
    int secret_number = 123;

    PRINT_COLOR(cyan);
    do {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);

        PRINT_COLOR(orange);
        if (guess > secret_number) {
            printf("Too high! Try again. 😅\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again. 😓\n");
        } else {
            PRINT_COLOR(pink);
            printf("You guessed it! The secret number was %d. 🎉\n", secret_number);
            break;
        }
    } while (1);

    PRINT_COLOR(brown);
    printf("That's all for now! Thanks for playing! 👋\n");

    return 0;
}

int get_answer() {
    PRINT_COLOR(gray);
    printf("What is your answer? (1/2/3/4/5): ");
    int answer;
    scanf("%d", &answer);

    PRINT_COLOR(gray);
    return answer;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <string.h>

//My curiosity is peaked! I wonder what arithmetic adventure awaits us?

int main() {
    //Let's greet the user and see if they have a favorite number
    int favorite_num;
    char name[15];
    printf("Hello there! What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! Do you have a favorite number?\n", name);
    scanf("%d", &favorite_num);
    printf("Ah, %d. An interesting choice! Let's use that number in some arithmetic operations.\n", favorite_num);

    //Let's create some variables and do some arithmetic!
    int a = 2, b = 3, c = 5;
    printf("First, we have a = %d, b = %d and c = %d\n", a, b, c);
    printf("Let's add a and b together and then multiply by c. What do you think the answer will be?\n");
    int d = (a + b) * c;
    printf("The answer is %d!\n", d);
    printf("Now let's subtract your favorite number from the answer we got before. What do you think the result will be?\n");
    int e = d - favorite_num;
    printf("The result is %d!\n", e);

    //I'm curious if the user wants to keep playing with numbers
    char play_again;
    printf("That was fun! Do you want to keep playing with arithmetic? (Y/N)\n");
    scanf(" %c", &play_again);
    if(play_again == 'Y' || play_again == 'y') {
        printf("Great! Let's continue.\n");

        //We'll play a little guessing game
        int secret_num = 7;
        int guess;
        printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
        do {
            scanf("%d", &guess);
            if(guess < secret_num) {
                printf("Nope, too low. Guess again.\n");
            } else if(guess > secret_num) {
                printf("Nope, too high. Guess again.\n");
            } else {
                printf("Yes! You guessed it. The secret number was %d.\n", secret_num);
                break;
            }
        } while(guess != secret_num);

        //Let's do some more arithmetic based on the guess
        int f = guess * 2;
        int g = guess / 3;
        printf("Now let's double your guess and divide it by 3. The answer is %d.\n", g);
    }

    //That was fun, let's say goodbye
    printf("Thanks for playing with arithmetic, %s! Goodbye!\n", name);

    return 0;
}
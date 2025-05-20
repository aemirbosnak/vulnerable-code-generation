//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    // Declare variables to store user input
    char name[MAX_NAME_LEN];
    int age;

    // Print a funny error message if user input is invalid
    printf("Welcome to the party, human! Please enter your name and age:\n");
    if (scanf("%19s%d", name, &age) != 2) {
        printf("Oh noes! It looks like you've been possessed by a demon! Your name is now %s, and your age is %d. Better luck next time! \n", name, age);
        return 1;
    }

    // Check if age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Uh-oh! It looks like you've been sipping on some magic potion again! Your age is now %d. Better lay off the fantasy novels for a while! \n", age);
        return 2;
    }

    // Print a success message
    printf("Welcome to the party, %s! You are now %d years young! Enjoy the cake and punch, but don't get too carried away or you might end up in a time loop! \n", name, age);

    // Generate a random number between 1 and 10
    int randomNumber = rand() % 10 + 1;

    // Print a funny message based on the random number
    switch (randomNumber) {
        case 1:
            printf("Oh look, a unicorn! \n");
            break;
        case 2:
            printf("A dragon just flew by! \n");
            break;
        case 3:
            printf("The cat just meowed at you. \n");
            break;
        case 4:
            printf("The potted plant just winked at you. \n");
            break;
        case 5:
            printf("You just won the lottery! (But don't tell anyone.) \n");
            break;
        default:
            printf("Something strange just happened. (But don't worry, it's not a bug.) \n");
            break;
    }

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print a happy message
void print_happy_message() {
    printf("HAPPINESS IS THE KEY TO LIFE! 😄👍\n");
}

// Function to print an unhappy message
void print_unhappy_message() {
    printf("Boo! 😢👎\n");
}

// Function to roll a dice
int roll_dice() {
    int dice_roll = rand() % 6 + 1;
    return dice_roll;
}

int main() {
    // Ask the user for their name
    printf("What's your name? 🤔\n");
    char name[50];
    fgets(name, 50, stdin);

    // Print a happy message if the user's name is "Alice" or "Bob"
    if (strcmp(name, "Alice") == 0 || strcmp(name, "Bob") == 0) {
        print_happy_message();
    } else {
        // Print an unhappy message if the user's name is not "Alice" or "Bob"
        print_unhappy_message();
    }

    // Roll a dice and print the result
    int dice_roll = roll_dice();
    printf("You rolled a %d! 🎲\n", dice_roll);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n) 🤔\n");
    char play_again;
    scanf(" %c", &play_again);

    if (play_again == 'y' || play_again == 'Y') {
        // Play again!
        main();
    } else {
        // Goodbye! 👋
        printf("Goodbye! 👋\n");
    }

    return 0;
}
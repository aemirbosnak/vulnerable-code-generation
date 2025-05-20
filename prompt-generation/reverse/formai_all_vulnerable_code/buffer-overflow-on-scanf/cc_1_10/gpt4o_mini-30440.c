//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void display_welcome_message();
int roll_dice(int sides);
void display_roll_result(int roll);
void play_again(int *continue_playing);
int get_number_of_sides();

int main() {
    int continue_playing = 1;
    int dice_sides, roll;

    // Seed for random number generation
    srand((unsigned int)time(0));

    // Display the welcome message
    display_welcome_message();

    while (continue_playing) {
        dice_sides = get_number_of_sides();
        roll = roll_dice(dice_sides);
        display_roll_result(roll);
        play_again(&continue_playing);
    }

    printf("Thank you for playing!\n");
    return 0;
}

// Function to display a welcome message
void display_welcome_message() {
    printf("================================\n");
    printf("       DICE ROLLER PROGRAM      \n");
    printf("================================\n");
    printf("Welcome to the Dice Roller!\n");
    printf("You can roll a die of any number of sides.\n");
    printf("Let's see what you roll!\n");
}

// Function to roll a dice given the number of sides
int roll_dice(int sides) {
    int roll = (rand() % sides) + 1; // Generates a random number between 1 and sides
    return roll;
}

// Function to display the result of the roll
void display_roll_result(int roll) {
    printf("You rolled a: %d\n", roll);
}

// Function to ask the user if they want to play again
void play_again(int *continue_playing) {
    char response;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        *continue_playing = 1; // Continue playing
    } else {
        *continue_playing = 0; // Stop playing
    }
}

// Function to get the number of sides for the dice
int get_number_of_sides() {
    int sides;
    
    do {
        printf("Enter the number of sides for the die (greater than 1): ");
        scanf("%d", &sides);
        
        if (sides <= 1) {
            printf("Please enter a valid number greater than 1.\n");
        }
    } while (sides <= 1);
    
    return sides;
}
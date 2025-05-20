//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 6
#define MIN_DICE 1
#define MAX_ROLLS 10
#define MAX_NAME_LENGTH 50

// Function to roll a single die
int roll_die() {
    return (rand() % MAX_DICE) + MIN_DICE;
}

// Function to roll multiple dice and store results
void roll_multiple_dice(int num_dice, int results[]) {
    for (int i = 0; i < num_dice; i++) {
        results[i] = roll_die();
    }
}

// Function to display the results of the rolls
void display_results(int results[], int num_dice, char *player_name) {
    printf("\n%s rolled %d dice:\n", player_name, num_dice);
    for (int i = 0; i < num_dice; i++) {
        printf("Die %d: %d\n", i + 1, results[i]);
    }
}

void print_welcome_message() {
    printf("*****************************************\n");
    printf("* Welcome to the C Dice Roller Game!    *\n");
    printf("*****************************************\n");
    printf("Roll up to %d dice to see what you get!\n", MAX_ROLLS);
    printf("Let's have some fun!\n\n");
}

void print_goodbye_message() {
    printf("\nThanks for playing! Goodbye!\n");
    printf("*****************************************\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed

    char player_name[MAX_NAME_LENGTH];
    int num_rolls = 0;
    int results[MAX_ROLLS];

    print_welcome_message();

    printf("Enter your name: ");
    fgets(player_name, sizeof(player_name), stdin);
    
    // Remove newline character from player's name
    player_name[strcspn(player_name, "\n")] = 0; 

    while (1) {
        printf("\nHow many dice would you like to roll (1 to %d, or 0 to exit)? ", MAX_ROLLS);
        scanf("%d", &num_rolls);

        if (num_rolls == 0) {
            print_goodbye_message();
            break;
        } else if (num_rolls < 1 || num_rolls > MAX_ROLLS) {
            printf("Invalid number of dice! Please try again.\n");
            continue;
        }

        roll_multiple_dice(num_rolls, results);
        display_results(results, num_rolls, player_name);

        char choice;
        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            print_goodbye_message();
            break;
        }
    }

    return 0;
}
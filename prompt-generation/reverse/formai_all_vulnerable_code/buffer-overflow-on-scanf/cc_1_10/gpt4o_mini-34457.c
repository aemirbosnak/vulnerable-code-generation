//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that simulates the rolling of a dice
int roll_dice() {
    return (rand() % 6) + 1; // Returns a number between 1 and 6
}

// Function to display an artful representation of the dice
void print_dice(int dice_value) {
    printf("\n");
    printf(" ------- \n");
    printf("|       |\n");
    
    // Representing the dice face according to its value
    switch(dice_value) {
        case 1:
            printf("|   *   |\n");
            break;
        case 2:
            printf("| *     |\n");
            printf("|     * |\n");
            break;
        case 3:
            printf("| *     |\n");
            printf("|   *   |\n");
            printf("|     * |\n");
            break;
        case 4:
            printf("| *   * |\n");
            printf("|       |\n");
            printf("| *   * |\n");
            break;
        case 5:
            printf("| *   * |\n");
            printf("|   *   |\n");
            printf("| *   * |\n");
            break;
        case 6:
            printf("| *   * |\n");
            printf("| *   * |\n");
            printf("| *   * |\n");
            break;
    }
    
    printf("|       |\n");
    printf(" ------- \n");
}

// Function to play the dice rolling game
void play_game() {
    char choice;
    int total_rolls = 0, current_roll;
    
    printf("Welcome to the Dice Roller Game!\n");
    printf("You can roll a dice as many times as you want!\n");
    
    do {
        current_roll = roll_dice();
        total_rolls++;
        printf("You rolled: %d", current_roll);
        print_dice(current_roll);
        
        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nTotal rolls made: %d\n", total_rolls);
    printf("Thank you for playing the Dice Roller Game!\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Start the game
    play_game();
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 5
#define MAX_SIDES 20

// Structure to represent a dice
typedef struct {
    int sides;
    int value;
} Dice;

// Function to roll a single die
int roll_die(Dice *die) {
    die->value = (rand() % die->sides) + 1;
    return die->value;
}

// Function to display the results of the dice rolls
void display_results(Dice dice[], int num_dice) {
    printf("\nYou've rolled the following dice:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d (d%d): %d\n", i + 1, dice[i].sides, dice[i].value);
    }
}

// Function to handle the rolling of multiple dice
void roll_multiple_dice(int num_dice) {
    Dice dice[MAX_DICE];
    for (int i = 0; i < num_dice; i++) {
        printf("Enter the number of sides for dice %d (up to %d sides): ", i + 1, MAX_SIDES);
        scanf("%d", &dice[i].sides);
        if (dice[i].sides < 1 || dice[i].sides > MAX_SIDES) {
            printf("Invalid number of sides! Setting to default (6).\n");
            dice[i].sides = 6;
        }
    }
    
    printf("\nRolling... brace yourself!\n");
    
    for (int i = 0; i < num_dice; i++) {
        roll_die(&dice[i]);
    }
    
    display_results(dice, num_dice);
}

// Function to simulate the desolate reality of the world
void apocalyptic_introduction() {
    printf("In a world ravaged by chaos and despair...\n");
    printf("Survivors gather in the ruins of civilization...\n");
    printf("Dice rolls are no longer just games; they are battles for survival...\n");
    printf("Each number holds the fate of brave souls.\n\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int num_dice;

    apocalyptic_introduction();

    while (1) {
        printf("How many dice do you want to roll? (1 to %d, 0 to exit): ", MAX_DICE);
        scanf("%d", &num_dice);
        
        if (num_dice < 0 || num_dice > MAX_DICE) {
            printf("Invalid number of dice. Try again or exit by entering 0.\n");
            continue;
        }
        
        if (num_dice == 0) {
            printf("You chose to leave the chaos behind. Until next time...\n");
            break;
        }

        roll_multiple_dice(num_dice);
    }

    return 0;
}
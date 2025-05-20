//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_SCORE 50

void clear_screen() {
    // Clear the console screen for a cleaner game display
    printf("\033[H\033[J");
}

void display_rules() {
    printf("Welcome to the Dice Rolling Game!\n");
    printf("Rules:\n");
    printf("1. Each player takes turns rolling two dice.\n");
    printf("2. The sum of the two dice is the score for that turn.\n");
    printf("3. First player to reach %d points wins!\n", MAX_SCORE);
    printf("4. If you roll a double, you get an extra turn!\n");
    printf("5. Type 'exit' to quit the game at any time.\n\n");
}

int roll_dice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1); // Sum of two dice
}

int main() {
    int scores[MAX_PLAYERS] = {0};
    char player_names[MAX_PLAYERS][20];
    int player_count, current_player = 0, game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of players
    printf("Enter number of players (2-4): ");
    scanf("%d", &player_count);
    
    // Validate player count
    while (player_count < 2 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players! Please enter a number between 2 and 4: ");
        scanf("%d", &player_count);
    }

    // Get player names
    for (int i = 0; i < player_count; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", player_names[i]);
    }

    clear_screen();
    display_rules();

    // Game loop
    while (!game_over) {
        int turn_score = 0;
        char input[10];

        printf("\n%s's turn!\n", player_names[current_player]);
        printf("Press enter to roll the dice (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin); // Capture input to wait for enter
        
        // Check for exit command
        if (strcmp(input, "exit\n") == 0) {
            printf("Thanks for playing!\n");
            return 0;
        }

        int roll = roll_dice();
        turn_score += roll;
        printf("You rolled a %d! (Total: %d)\n", roll, turn_score);

        // Check for double
        if (roll % 2 == 0) {
            printf("You rolled a double! You get an extra turn!\n");
            roll = roll_dice();
            turn_score += roll;
            printf("You rolled another %d! (Total: %d)\n", roll, turn_score);
        }

        // Update and display player's score
        scores[current_player] += turn_score;
        printf("%s's current score: %d\n", player_names[current_player], scores[current_player]);

        // Check for win condition
        if (scores[current_player] >= MAX_SCORE) {
            printf("%s wins the game with %d points!\n", player_names[current_player], scores[current_player]);
            game_over = 1; // End game
        }

        // Move to the next player
        current_player = (current_player + 1) % player_count;

        // Clear screen after each turn for better readability
        clear_screen();
    }

    return 0;
}
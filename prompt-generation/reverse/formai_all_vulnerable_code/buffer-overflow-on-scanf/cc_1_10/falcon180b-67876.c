//Falcon-180B DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a colorful message
void print_color(char *message, int color) {
    printf("\033[0;%dm%s\033[0m", color, message);
}

int main() {
    srand(time(NULL));

    // Define colors
    int RED = 31;
    int GREEN = 32;
    int YELLOW = 33;
    int BLUE = 34;
    int MAGENTA = 35;
    int CYAN = 36;

    // Define game variables
    char player_name[20];
    int player_score = 0;
    int enemy_score = 0;
    int game_over = 0;

    // Initialize game
    printf("Welcome to the game!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    print_color("Player: ", RED);
    print_color(player_name, GREEN);
    print_color("\n", 0);

    // Game loop
    while (!game_over) {
        int random_number = rand() % 6 + 1;
        if (random_number == 1) {
            enemy_score++;
            print_color("Enemy scores a point! ", YELLOW);
        } else if (random_number == 2) {
            player_score++;
            print_color("Player scores a point! ", GREEN);
        } else {
            print_color("Nothing happens. ", BLUE);
        }
        if (player_score == 10) {
            game_over = 1;
            print_color("Player wins! ", GREEN);
        } else if (enemy_score == 10) {
            game_over = 1;
            print_color("Enemy wins! ", RED);
        }
        print_color("\n", 0);
    }

    return 0;
}
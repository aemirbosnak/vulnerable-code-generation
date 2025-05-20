//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include <stdio.h>

int main() {
    int player_x = 0, player_y = 0;
    int alien_x = 997, alien_y = 642;
    int fuel_cells_remaining = 20;
    int distance_to_alien = abs(player_x - alien_x) + abs(player_y - alien_y);
    int random_event_chance = 5; // percent chance of random event occurring
    int player_health = 100;
    int player_shield = 50;

    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are on a mission to reach an alien planet and make contact with its inhabitants.\n");
    printf("You start at coordinates (%d, %d) and the alien planet is at coordinates (%d, %d).\n\n", player_x, player_y, alien_x, alien_y);

    // game loop
    while (fuel_cells_remaining > 0 && distance_to_alien > 0 && player_health > 0) {
        printf("\nCurrent stats:\n");
        printf("- Fuel cells remaining: %d\n", fuel_cells_remaining);
        printf("- Distance to alien planet: %d\n", distance_to_alien);
        printf("- Player health: %d\n", player_health);
        printf("- Player shield: %d\n", player_shield);

        // handle random event
        if ((rand() % 100) < random_event_chance) {
            int event_type = rand() % 3;
            int event_value = rand() % 10 + 1;

            switch (event_type) {
                case 0: // asteroid field
                    printf("\nOh no! You have entered an asteroid field!\n");
                    printf("Your shield has taken a hit.\n");
                    player_shield -= event_value;
                    break;
                case 1: // alien ambush
                    printf("\nAlien ships have appeared and are attacking!\n");
                    printf("Your health has been damaged.\n");
                    player_health -= event_value;
                    break;
                case 2: // fuel leak
                    printf("\nThere is a fuel leak on your ship!\n");
                    printf("You have lost some fuel.\n");
                    fuel_cells_remaining -= event_value;
                    break;
            }
        }

        printf("\nChoose your next move:\n");
        printf("1. Move up\n");
        printf("2. Move down\n");
        printf("3. Move left\n");
        printf("4. Move right\n");
        printf("5. Use fuel cell to move faster\n");
        printf("6. Quit game\n\n");

        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int move_distance = 1; // default distance for regular moves
        switch (choice) {
            case 1: // move up
                player_y += move_distance;
                break;
            case 2: // move down
                player_y -= move_distance;
                break;
            case 3: // move left
                player_x -= move_distance;
                break;
            case 4: // move right
                player_x += move_distance;
                break;
            case 5: // use fuel cell to move faster
                if (fuel_cells_remaining > 0) {
                    move_distance = 2;
                    player_x += move_distance;
                    fuel_cells_remaining--;
                } else {
                    printf("\nYou have no more fuel cells!\n");
                }
                break;
            case 6: // quit game
                printf("\nQuitting game...\n");
                return 0;
            default: // invalid choice
                printf("\nInvalid choice! Please choose a number between 1 and 6.\n");
                break;
        }

        // update distance to alien planet
        distance_to_alien = abs(player_x - alien_x) + abs(player_y - alien_y);
    }

    if (distance_to_alien <= 0) {
        printf("\nCongratulations! You have reached the alien planet and made contact with its inhabitants.\n");
    } else if (fuel_cells_remaining <= 0) {
        printf("\nUh oh, you have run out of fuel cells! You are stranded in space.\n");
    } else {
        printf("\nOh no, your health has reached zero! Better luck next time.\n");
    }

    return 0;
}
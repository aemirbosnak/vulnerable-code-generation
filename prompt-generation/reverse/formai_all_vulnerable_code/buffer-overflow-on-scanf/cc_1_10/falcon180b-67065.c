//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game Variables
int player_health = 100;
int player_hunger = 100;
int player_thirst = 100;
int player_location = 0;
int game_status = 0;

// Game Functions
void game_over() {
    printf("Game Over!\n");
    exit(0);
}

void game_start() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a mysterious forest.\n");
    printf("What would you like to do?\n");
}

void game_loop() {
    int choice;

    printf("Health: %d\n", player_health);
    printf("Hunger: %d\n", player_hunger);
    printf("Thirst: %d\n", player_thirst);

    printf("1. Move Forward\n");
    printf("2. Search for Food\n");
    printf("3. Search for Water\n");
    printf("4. Rest\n");
    printf("5. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(player_location < 10) {
                player_location++;
            } else {
                printf("You have reached the end of the forest.\n");
                game_over();
            }
            break;

        case 2:
            if(player_hunger > 0) {
                player_hunger--;
            } else {
                printf("You are too hungry to search for food.\n");
            }
            break;

        case 3:
            if(player_thirst > 0) {
                player_thirst--;
            } else {
                printf("You are too thirsty to search for water.\n");
            }
            break;

        case 4:
            if(player_health > 0) {
                player_health--;
            } else {
                printf("You are too weak to rest.\n");
            }
            break;

        case 5:
            game_over();
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}

int main() {
    srand(time(0));

    game_start();

    while(game_status == 0) {
        game_loop();
    }

    return 0;
}
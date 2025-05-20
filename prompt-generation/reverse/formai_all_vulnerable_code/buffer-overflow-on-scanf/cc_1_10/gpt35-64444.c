//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void explore(int planet);
void travel();
void battle();
int roll_die();

int main() {
    // seed random generator
    srand(time(NULL));
    
    // welcome message
    printf("Welcome to our procedural space adventure!\n\n");

    // player starts on planet 1
    int current_planet = 1;
    printf("You are currently on planet %d.\n\n", current_planet);

    // main game loop
    while (1) {
        printf("What would you like to do?\n");
        printf("1 - Explore this planet\n");
        printf("2 - Travel to another planet\n");
        printf("3 - Battle an alien on this planet\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                explore(current_planet);
                break;
            case 2:
                travel();
                break;
            case 3:
                battle();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // check if player has reached the final planet
        if (current_planet == 10) {
            printf("Congratulations! You have completed the game!\n");
            break;
        }
    }

    return 0;
}

void explore(int planet) {
    printf("Exploring planet %d...\n", planet);

    // random chance of finding an item
    int item_roll = roll_die();
    if (item_roll > 3) {
        printf("You found a rare item!\n");
    } else {
        printf("You didn't find anything.\n");
    }
}

void travel() {
    // random chance of encountering an obstacle
    int obstacle_roll = roll_die();
    if (obstacle_roll >= 4) {
        printf("You traveled safely to another planet.\n");
    } else {
        printf("You encountered a hostile alien on the way and had to battle it!\n");
        battle();
    }
}

void battle() {
    printf("Engaging in battle with an alien!\n");

    // simulate battle
    int player_health = 20;
    int alien_health = 20;
    while (player_health > 0 && alien_health > 0) {
        int player_roll = roll_die();
        int alien_roll = roll_die();

        if (player_roll >= alien_roll) {
            printf("You hit the alien and dealt 3 damage!\n");
            alien_health -= 3;
        } else {
            printf("The alien hit you and dealt 2 damage!\n");
            player_health -= 2;
        }
    }

    if (player_health > 0) {
        printf("You won the battle!\n");
    } else {
        printf("You lost the battle and returned to your previous planet with reduced health.\n");
    }
}

int roll_die() {
    return rand() % 6 + 1;
}
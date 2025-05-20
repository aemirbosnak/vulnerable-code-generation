//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random number */
int randomNumber(int min, int max) {
    return (rand() % (max + 1 - min)) + min;
}

/* Function to initialize game */
int initialize() {
    int player_health = 100, alien_health = 100, player_choice, alien_attack;
    printf("*** Welcome to Procedural Space Adventure ***\n");
    printf("Your spaceship has been attacked by aliens.\n");
    printf("You have to fight the alien to save your life.\n");
    printf("You have 100 health points. The alien also has 100 health points.\n");
    printf("Press 1 to attack the alien, press 2 to defend yourself.\n");
    printf("Enter your choice: ");
    scanf("%d", &player_choice);
    if (player_choice == 1) {
        alien_health -= randomNumber(10, 20);
        printf("You attacked the alien. The alien now has %d health points left.\n", alien_health);
    } else {
        printf("You are defending yourself. The alien attacks you.\n");
        player_health -= randomNumber(10, 20);
        printf("Your health points: %d\n", player_health);
    }
    return player_health > 0 && alien_health > 0 ? 1 : 0;
}

/* Function to play the game */
void play() {
    int player_health = 100, alien_health = 100, player_choice, alien_attack;
    while (player_health > 0 && alien_health > 0) {
        printf("Press 1 to attack the alien, press 2 to defend yourself.\n");
        printf("Enter your choice: ");
        scanf("%d", &player_choice);
        if (player_choice == 1) {
            alien_health -= randomNumber(10, 20);
            printf("You attacked the alien. The alien now has %d health points left.\n", alien_health);
            if (alien_health > 0) {
                alien_attack = randomNumber(1, 2);
                if (alien_attack == 1) {
                    player_health -= randomNumber(10, 20);
                    printf("The alien attacked you. Your health points: %d\n", player_health);
                } else {
                    printf("The alien is defending itself.\n");
                }
            }
        } else {
            printf("You are defending yourself. The alien attacks you.\n");
            player_health -= randomNumber(10, 20);
            printf("Your health points: %d\n", player_health);
            if (player_health > 0) {
                alien_attack = randomNumber(1, 2);
                if (alien_attack == 1) {
                    printf("The alien attacked you. Your health points: %d\n", player_health);
                } else {
                    printf("The alien is defending itself.\n");
                }
            }
        }
    }
    if (player_health > 0) {
        printf("*** Congratulations! You have defeated the alien! ***\n");
    } else {
        printf("*** Game over. The alien has defeated you. ***\n");
    }
}

/* Main Function */
int main() {
    int play_again;
    srand((unsigned int)time(NULL));
    do {
        if (initialize() == 1) {
            play();
        }
        printf("Do you want to play again? Press 1 for Yes, 2 for No.\n");
        printf("Enter your choice: ");
        scanf("%d", &play_again);
    } while (play_again == 1);
    printf("*** Thank you for playing Procedural Space Adventure! ***\n");
    return 0;
}
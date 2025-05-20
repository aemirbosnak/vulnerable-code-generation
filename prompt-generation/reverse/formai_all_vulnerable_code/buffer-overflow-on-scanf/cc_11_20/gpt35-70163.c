//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int ghost_health = 200;
    int drink_health = 50;
    int option;
    printf("Welcome to the Haunted House!\n");
    printf("You are trapped in a haunted house filled with ghosts and ghouls.\n");
    printf("Your goal is to escape the house while avoiding the spirits that haunt it.\n");
    printf("Your current health is %d.\n\n", player_health);
    while (player_health > 0 && ghost_health > 0) {
        printf("What do you want to do? (Enter the corresponding number.)\n");
        printf("1. Search for a way out.\n");
        printf("2. Fight the ghosts.\n");
        printf("3. Drink the potion.\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("You search the house for a way out, but all the doors are locked.\n");
                if (rand() % 2 == 0) {
                    printf("A ghost appears and attacks you!\n");
                    player_health -= 30;
                    printf("You lose 30 health.\n");
                }
                else {
                    printf("You find an old key hidden behind a painting.\n");
                }
                break;
            case 2:
                printf("You prepare to fight the ghosts.\n");
                if (rand() % 2 == 0) {
                    printf("A ghost appears and attacks you!\n");
                    player_health -= 30;
                    printf("You lose 30 health.\n");
                }
                else {
                    printf("You defeat the ghosts! But the battle has left you exhausted.\n");
                }
                break;
            case 3:
                printf("You drink the potion and regain some health.\n");
                player_health += drink_health;
                if (player_health > 100) {
                    player_health = 100;
                }
                printf("Your health is now %d.\n", player_health);
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
        if (rand() % 2 == 0) {
            printf("A ghost appears and attacks you!\n");
            player_health -= 10;
            printf("You lose 10 health.\n");
        }
        else {
            printf("You manage to avoid the ghosts for now.\n");
        }
        if (ghost_health > 0) {
            ghost_health -= 20;
            printf("The ghosts lose 20 health.\n");
        }
        if (player_health <= 0) {
            printf("Game over. You have died.\n");
        }
        else if (ghost_health <= 0) {
            printf("Congratulations! You have defeated all the ghosts and escaped the haunted house!\n");
            printf("You are the ultimate survivor.\n");
        }
    }
    return 0;
}
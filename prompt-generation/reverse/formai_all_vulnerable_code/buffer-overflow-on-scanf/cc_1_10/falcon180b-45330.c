//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void space_adventure() {
    int choice;
    char name[30];
    int health = 100;
    int score = 0;
    int planet = 1;
    int enemy_health = 0;
    int enemy_attack = 0;

    printf("Welcome to the Space Adventure!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    srand(time(NULL));

    while(health > 0 && planet <= 5) {
        printf("\nPlanet %d\n", planet);
        printf("You have %d health points left.\n", health);
        printf("Score: %d\n", score);

        int event = rand() % 6;

        switch(event) {
            case 0:
                printf("You find a healing potion. Health increased by 20.\n");
                health += 20;
                break;
            case 1:
                printf("You find a weapon. Attack increased by 10.\n");
                break;
            case 2:
                printf("You find a shield. Defense increased by 10.\n");
                break;
            case 3:
                printf("An enemy appears! It has %d health points and %d attack points.\n", enemy_health, enemy_attack);
                printf("What do you want to do?\n");
                printf("1. Attack\n");
                printf("2. Defend\n");
                scanf("%d", &choice);

                if(choice == 1) {
                    if(health - enemy_attack <= 0) {
                        printf("You lose the battle. Game over.\n");
                        exit(0);
                    } else {
                        printf("You win the battle.\n");
                        enemy_health = 0;
                    }
                } else if(choice == 2) {
                    if(enemy_health - health <= 0) {
                        printf("You win the battle.\n");
                        enemy_health = 0;
                    } else {
                        printf("You lose the battle. Game over.\n");
                        exit(0);
                    }
                } else {
                    printf("Invalid choice. You lose the battle. Game over.\n");
                    exit(0);
                }
                break;
            case 4:
                printf("You find a treasure. Score increased by 10.\n");
                score += 10;
                break;
            case 5:
                printf("Nothing happens.\n");
                break;
        }

        planet++;
    }

    printf("\nCongratulations! You completed the Space Adventure with a score of %d!\n", score);
}

int main() {
    space_adventure();
    return 0;
}
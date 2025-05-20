//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int player_attack = rand() % 10 + 1;
    int enemy_attack = rand() % 10 + 1;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark, eerie forest.\n");
    printf("There is a path leading north and one leading east.\n");
    printf("Which way do you want to go? ");

    char choice;
    scanf("%c", &choice);

    switch (choice) {
        case 'n':
            printf("You walk along the path to the north.\n");
            printf("Suddenly, an evil goblin jumps out from behind a tree!\n");
            printf("The goblin has %d health points.\n", enemy_health);

            while (player_health > 0 && enemy_health > 0) {
                printf("What do you want to do? ");
                printf("a) Attack\nb) Defend\n");
                char action;
                scanf("%c", &action);

                if (action == 'a') {
                    printf("You attack the goblin with all your might!\n");
                    enemy_health -= player_attack;
                } else if (action == 'b') {
                    printf("You defend yourself against the goblin's attack.\n");
                    player_health -= enemy_attack;
                } else {
                    printf("Invalid action.\n");
                }
            }

            if (player_health <= 0) {
                printf("You have been defeated by the goblin.\n");
                return 0;
            } else {
                printf("You have vanquished the evil goblin!\n");
            }
            break;

        case 'e':
            printf("You follow the path to the east.\n");
            printf("As you walk, you come across a sparkling river.\n");
            printf("Do you want to cross the river? ");

            char river_choice;
            scanf("%c", &river_choice);

            if (river_choice == 'y') {
                printf("You carefully make your way across the river.\n");
            } else {
                printf("You decide to turn back and explore another path.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}
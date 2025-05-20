//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_health = 100;
    int enemy_health = 50;
    int choice;
    int random_number;

    srand(time(0));

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave warrior on a quest to defeat the evil sorcerer.\n");
    printf("Guide me through this adventure.\n");

    while(player_health > 0 && enemy_health > 0) {
        printf("You see the sorcerer in the distance. What do you do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run away\n");
        scanf("%d", &choice);

        random_number = rand() % 3;

        if(choice == 1 && random_number == 0) {
            printf("You successfully attack the sorcerer and deal 10 damage!\n");
            enemy_health -= 10;
        } else if(choice == 1 && random_number!= 0) {
            printf("You miss your attack.\n");
        } else if(choice == 2 && random_number == 0) {
            printf("You successfully defend against the sorcerer's attack!\n");
        } else if(choice == 2 && random_number!= 0) {
            printf("You fail to defend and take 10 damage!\n");
            player_health -= 10;
        } else if(choice == 3) {
            printf("You successfully run away from the sorcerer.\n");
        } else {
            printf("Invalid choice.\n");
        }

        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
    }

    if(player_health <= 0) {
        printf("You have been defeated by the sorcerer.\n");
    } else {
        printf("You have defeated the sorcerer and saved the kingdom!\n");
    }

    return 0;
}
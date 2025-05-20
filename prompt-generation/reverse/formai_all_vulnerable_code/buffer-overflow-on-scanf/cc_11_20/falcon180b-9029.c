//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
//Ada Lovelace Space Adventure

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int score = 0;
    int lives = 3;
    char name[20];
    printf("Welcome to the Ada Lovelace Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Greetings, %s! You are now in space.\n", name);
    printf("You have %d lives.\n", lives);
    srand(time(NULL));
    while(lives > 0) {
        int enemy_type = rand() % 3;
        int damage = rand() % 10 + 1;
        int enemy_health = rand() % 20 + 1;
        if(enemy_type == 0) {
            printf("You encounter a rogue asteroid!\n");
        }
        else if(enemy_type == 1) {
            printf("You are attacked by space pirates!\n");
        }
        else {
            printf("You face an alien invasion!\n");
        }
        printf("The enemy has %d health.\n", enemy_health);
        printf("What will you do?\n1. Attack\n2. Defend\n3. Run Away\n");
        scanf("%d", &choice);
        if(choice == 1) {
            if(score >= damage) {
                printf("You attack the enemy and deal %d damage!\n", damage);
                enemy_health -= damage;
                if(enemy_health <= 0) {
                    printf("You have defeated the enemy!\n");
                    score += enemy_health;
                }
                else {
                    printf("The enemy has %d health left.\n", enemy_health);
                }
            }
            else {
                printf("You don't have enough energy to attack.\n");
            }
        }
        else if(choice == 2) {
            if(score >= damage) {
                printf("You defend yourself and take %d damage.\n", damage);
                score -= damage;
                if(score <= 0) {
                    printf("You have been defeated!\n");
                    lives--;
                    score = 0;
                }
            }
            else {
                printf("You don't have enough energy to defend.\n");
            }
        }
        else if(choice == 3) {
            printf("You run away from the enemy.\n");
        }
        else {
            printf("Invalid choice.\n");
        }
    }
    printf("Thanks for playing, %s! Your final score is %d.\n", name, score);
    return 0;
}
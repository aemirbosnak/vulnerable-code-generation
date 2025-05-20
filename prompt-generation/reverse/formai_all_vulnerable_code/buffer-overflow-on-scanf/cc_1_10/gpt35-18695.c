//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {

    char player_name[20];
    int playing_time = 0;
    int planets_visited = 0;
    int alien_encounters = 0;

    printf("Welcome to the Space Adventure! What is your name, adventurer?\n");
    scanf("%s", player_name);

    printf("Good luck, %s! You are about to embark on a journey through the galaxies! Press Enter to start\n", player_name);
    getchar();

    // travelling to the first planet
    printf("As you take off, you notice that your spaceship is malfunctioning!\n");
    printf("You try to warn the crew but it's too late! You're being sucked into a wormhole!\n");

    printf("You enter a new universe... An alien approaches!\n");

    char alien_name[20];
    int alien_age;
    printf("Alien: Welcome to the world of Zorg, adventurer! What is your name?\n");
    scanf("%s", alien_name);

    printf("Alien: Welcome, %s! I am %s and I am %d years old. You are our first visitor from Earth!\n", player_name, alien_name, alien_age);
    printf("Alien: I will show you around our planet. By the way, how long have you been travelling?\n");

    scanf("%d", &playing_time);
    printf("Alien: %d years! You must be terribly hungry. We have a feast prepared for you at our palace!\n", playing_time);

    printf("As you indulge in the feast, you realize that this alien race is friendly and you start to enjoy your journey.\n");

    // travelling to the second planet
    printf("After spending some time on Zorg, you continue on your adventure.\n");
    printf("As you approach the next planet, you notice a fleet of enemy spaceships!\n");
    printf("You try to outrun them, but they've got you cornered!\n");
    printf("You must battle to survive! Let's do this!\n");

    int enemy_spaceships = 3;
    int player_spaceships = 1;
    while (enemy_spaceships > 0) {
        printf("Enemy spaceship %d approaching!\n", enemy_spaceships);
        printf("You fire your laser cannon!\n");
        enemy_spaceships--;
        printf("Enemy spaceship %d destroyed! You successfully defended yourself!\n", enemy_spaceships + 1);
        printf("You have %d spaceships remaining.\n", player_spaceships);
        if (player_spaceships == 0) {
            printf("Your spaceship has been destroyed! Game over, adventurer.\n");
            return 0;
        }
    }

    printf("Congratulations! You have successfully defended yourself and defeated all the enemy spaceships!\n");
    alien_encounters++;

    // travelling to the third planet
    printf("As you arrive on the third planet, you notice something strange. The stars are disappearing!\n");
    printf("The galaxy is being destroyed and you must act fast!\n");

    int time_left = 30;
    while (time_left > 0) {
        printf("You have %d minutes left to save the galaxy! What is your next move?\n", time_left);
        printf("1. Fire your laser. \n");
        printf("2. Dive into the black hole.\n");
        printf("3. Call for help.\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You fire your laser but it does nothing. You lose 5 minutes!\n");
                time_left -= 5;
                break;

            case 2:
                printf("You dive into the black hole and discover a new galaxy! You gain 10 minutes!\n");
                time_left += 10;
                break;

            case 3:
                printf("You call for help and are rescued by a passing starship! You gain 3 minutes!\n");
                time_left += 3;
                break;

            default:
                printf("Invalid choice! You lose 1 minute!\n");
                time_left -= 1;
                break;
        }

        if (time_left <= 0) {
            printf("You've run out of time! The galaxy is doomed... GAME OVER.\n");
            return 0;
        }
        else if (time_left >= 60) {
            printf("You're running out of time! Hurry!!\n");
        }
    }

    printf("Congratulations! You've saved the galaxy!\n");
    planets_visited++;

    // final score
    printf("That was quite an adventure, %s! You have travelled to %d planets and encountered %d friendly aliens.\n", player_name, planets_visited, alien_encounters);
    printf("Well done! You completed your mission and survived the dangers of space.\n");

    return 0;
}
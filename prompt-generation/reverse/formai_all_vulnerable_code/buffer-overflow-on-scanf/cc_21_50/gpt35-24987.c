//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char player_name[100];
    int player_health = 100;
    int player_points = 0;
    int aliens_killed = 0;
    int distance_to_planet = 1000000;
    int fuel = 100;
    int luck_factor;

    printf("Welcome to Procedural Space Adventure! What's your name, adventurer?\n");
    scanf("%s", player_name);
    printf("Welcome, %s! You have been tasked with traveling across the galaxy to planet X and taking out any aliens that stand in your way.\n", player_name);

    while (distance_to_planet > 0 && player_health > 0) {
        printf("You are currently %d miles from planet X. What would you like to do?\n", distance_to_planet);
        printf("1. Move closer to planet X.\n2. Take a rest and regain health.\n3. Search for fuel.\n4. Attack incoming aliens.\n5. Quit game.\n");
        int choice = getchar();
        getchar(); // consume newline character

        switch (choice) {
            case '1':
                printf("You move closer to planet X...\n");
                luck_factor = rand() % 10;
                if (luck_factor < 3) {
                    printf("You encountered an asteroid field and lost 10 fuel.\n");
                    fuel -= 10;
                } else if (luck_factor < 6) {
                    printf("You found some extra fuel floating in space and gained 10 fuel.\n");
                    fuel += 10;
                }
                distance_to_planet -= 50000;
                break;

            case '2':
                printf("You take a break and regain 10 health.\n");
                player_health += 10;
                if (player_health > 100) {
                    player_health = 100;
                }
                break;

            case '3':
                printf("You search for fuel...\n");
                luck_factor = rand() % 10;
                if (luck_factor < 3) {
                    printf("You couldn't find any fuel.\n");
                } else if (luck_factor < 6) {
                    printf("You found some fuel and gained 10 fuel.\n");
                    fuel += 10;
                } else {
                    printf("You found a fuel refinery and gained 20 fuel.\n");
                    fuel += 20;
                }
                break;

            case '4':
                printf("You attack incoming aliens...\n");
                int alien_health = 50;
                while (alien_health > 0 && player_health > 0) {
                    printf("Alien health: %d\n", alien_health);
                    printf("Your health: %d\n", player_health);
                    printf("1. Attack\n2. Flee\n");
                    int attack_choice = getchar();
                    getchar(); // consume newline character
                    if (attack_choice == '1') {
                        luck_factor = rand() % 10;
                        if (luck_factor < 4) {
                            printf("You missed the alien.\n");
                        } else {
                            int damage = rand() % 10;
                            printf("You dealt %d damage to the alien.\n", damage);
                            alien_health -= damage;
                        }
                        luck_factor = rand() % 10;
                        if (luck_factor < 4) {
                            printf("The alien missed you.\n");
                        } else {
                            int damage = rand() % 10;
                            printf("The alien dealt %d damage to you.\n", damage);
                            player_health -= damage;
                        }
                    } else {
                        printf("You flee from the aliens...\n");
                        fuel -= 10;
                        break;
                    }
                }
                if (alien_health <= 0 && player_health > 0) {
                    printf("You defeated the alien and gained 50 points and 10 fuel.\n");
                    player_points += 50;
                    fuel += 10;
                    aliens_killed++;
                } else if (player_health <= 0) {
                    printf("You were defeated by the alien. Game over.\n");
                    exit(0);
                }
                break;

            case '5':
                printf("Thanks for playing! Here's your final score:\n");
                printf("Player name: %s\n", player_name);
                printf("Player points: %d\n", player_points);
                printf("Aliens killed: %d\n", aliens_killed);
                printf("Distance to planet X: %d miles\n", distance_to_planet);
                printf("Fuel remaining: %d\n", fuel);
                exit(0);
                break;
        }
    }
    printf("You have arrived at planet X! Congratulations on completing your mission.\n");
    printf("Thanks for playing! Here's your final score:\n");
    printf("Player name: %s\n", player_name);
    printf("Player points: %d\n", player_points);
    printf("Aliens killed: %d\n", aliens_killed);
    printf("Distance to planet X: %d miles\n", distance_to_planet);
    printf("Fuel remaining: %d\n", fuel);
    return 0;
}
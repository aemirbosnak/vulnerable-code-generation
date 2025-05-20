//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void space_adventure() {
    int choice, random_number;
    char name[20];

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you are a space explorer on a mission to discover new planets and civilizations.\n", name);
    printf("Your spaceship is equipped with the latest technology and weapons to defend yourself against any threats.\n");
    printf("Are you ready to embark on this exciting journey? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int health = 100, fuel = 100, ammo = 100;
        int planet_number;

        srand(time(NULL));
        planet_number = rand() % 10 + 1;

        while (health > 0 && fuel > 0 && ammo > 0) {
            printf("\nYou have arrived at Planet %d.\n", planet_number);
            printf("Do you want to explore the planet? (y/n): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                random_number = rand() % 3;

                if (random_number == 0) {
                    printf("\nYou discover a peaceful civilization on this planet.\n");
                    printf("They offer you valuable resources and information for your journey.\n");
                    health += 20;
                    fuel += 30;
                    ammo += 10;
                } else if (random_number == 1) {
                    printf("\nYou encounter hostile aliens on this planet.\n");
                    printf("You engage in a fierce battle and manage to defeat them.\n");
                    health -= 30;
                    fuel -= 20;
                    ammo -= 15;
                } else {
                    printf("\nYou find nothing of interest on this planet.\n");
                }
            } else {
                printf("\nYou decide not to explore the planet and continue your journey.\n");
            }

            planet_number++;
        }

        if (health <= 0) {
            printf("\nYour health has reached zero. Game Over.\n");
        } else if (fuel <= 0) {
            printf("\nYour fuel has run out. Game Over.\n");
        } else if (ammo <= 0) {
            printf("\nYou are out of ammo. Game Over.\n");
        } else {
            printf("\nCongratulations! You have completed your mission successfully.\n");
        }
    } else {
        printf("\nAborting mission...\n");
    }
}

int main() {
    space_adventure();
    return 0;
}
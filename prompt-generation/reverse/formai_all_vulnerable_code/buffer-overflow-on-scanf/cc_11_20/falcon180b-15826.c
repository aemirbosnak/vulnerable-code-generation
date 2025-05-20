//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int choice, randomEnemy = rand() % 3 + 1; // Random enemy between 1 and 3
    char name[20];

    printf("What is your name? ");
    scanf("%s", name);

    printf("\nWelcome to the world of paranoia, %s.\n", name);
    printf("You find yourself in a deserted town with no memory of how you got here.\n");
    printf("The air is thick with an eerie silence, and you can't shake off the feeling that you're being watched.\n");
    printf("You must navigate through this town and uncover its secrets before it's too late.\n\n");

    int health = 100;

    while (health > 0) {
        system("clear"); // Clear the console

        printf("\nYou are at a crossroads. Which path do you take?\n");
        printf("1. Go straight ahead.\n");
        printf("2. Turn left.\n");
        printf("3. Turn right.\n");
        printf("4. Go back.\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou continue down the path, your heart pounding in your chest.\n");
                if (randomEnemy == 1) {
                    printf("Suddenly, a shadowy figure jumps out from behind a building and attacks you!\n");
                    health -= 20;
                } else if (randomEnemy == 2) {
                    printf("As you walk, you hear whispers coming from the shadows. They seem to be getting louder...\n");
                } else {
                    printf("You reach a dead end. There's nothing here but an old, abandoned building.\n");
                }
                break;

            case 2:
                printf("\nYou turn left and find yourself in a narrow alleyway.\n");
                if (randomEnemy == 1) {
                    printf("Suddenly, a shadowy figure jumps out from behind a building and attacks you!\n");
                    health -= 20;
                } else if (randomEnemy == 2) {
                    printf("As you walk, you hear whispers coming from the shadows. They seem to be getting louder...\n");
                } else {
                    printf("You find a rusty old key on the ground.\n");
                }
                break;

            case 3:
                printf("\nYou turn right and come across an old, dilapidated house.\n");
                if (randomEnemy == 1) {
                    printf("Suddenly, a shadowy figure jumps out from behind a building and attacks you!\n");
                    health -= 20;
                } else if (randomEnemy == 2) {
                    printf("As you walk, you hear whispers coming from the shadows. They seem to be getting louder...\n");
                } else {
                    printf("The door creaks open, revealing a dusty old room with a single chair in the center.\n");
                }
                break;

            case 4:
                printf("\nYou decide to go back the way you came.\n");
                if (randomEnemy == 1) {
                    printf("Suddenly, a shadowy figure jumps out from behind a building and attacks you!\n");
                    health -= 20;
                } else if (randomEnemy == 2) {
                    printf("As you walk, you hear whispers coming from the shadows. They seem to be getting louder...\n");
                } else {
                    printf("You find yourself back at the crossroads.\n");
                }
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

        if (health <= 0) {
            printf("\n\nYou have died. Game over.\n");
            exit(0);
        }
    }

    printf("\nCongratulations! You have survived the world of paranoia.\n");
}
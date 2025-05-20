//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Procedural Space Adventure! What's your name?\n");
    scanf("%s", name);
    printf("Hello %s! You are now a space explorer. Your mission is to travel through the galaxy, encounter various cosmic phenomena, and survive.\n", name);
    printf("Press 1 to start your journey.\n");
    scanf("%d", &choice);
    if (choice == 1) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        int encounter = rand() % 4;
        int distance = 0;
        while (distance < x * y) {
            printf("You are traveling through space...\n");
            fflush(stdout);
            usleep(100000);
            distance++;
        }
        if (encounter == 0) {
            printf("You encounter a black hole!\n");
            printf("Press 1 to try and escape, or 2 to be sucked in.\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You narrowly escape the black hole!\n");
            } else {
                printf("You are sucked into the black hole and never seen again.\n");
                return 0;
            }
        } else if (encounter == 1) {
            printf("You encounter an asteroid field!\n");
            printf("Press 1 to try and navigate through it, or 2 to give up.\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You successfully navigate through the asteroid field!\n");
            } else {
                printf("You collide with an asteroid and your ship is destroyed.\n");
                return 0;
            }
        } else if (encounter == 2) {
            printf("You encounter an alien spaceship!\n");
            printf("Press 1 to try and communicate, or 2 to attack.\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You successfully communicate with the aliens and make new friends!\n");
            } else {
                printf("You engage in a space battle and your ship is destroyed.\n");
                return 0;
            }
        } else if (encounter == 3) {
            printf("You encounter a supernova!\n");
            printf("Press 1 to try and outrun it, or 2 to accept your fate.\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You narrowly escape the supernova!\n");
            } else {
                printf("You are caught in the supernova and never seen again.\n");
                return 0;
            }
        }
        printf("Congratulations, you have completed your mission!\n");
    } else {
        printf("Thanks for playing!\n");
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int health = 3;
    int flashlight = 1;
    int ran = 0;
    int ghosts_defeated = 0;

    printf("Entering Haunted House...\n\n");

    while (health > 0) {
        int num_ghosts = rand() % 3 + 1;

        printf("Suddenly, you hear strange noises...\n");
        printf("You realize there are %d ghosts near you!\n", num_ghosts);

        if (flashlight) {
            printf("Your flashlight is shining brightly and you can see the ghosts!\n");
        } else {
            printf("You don't have a flashlight, so you can't see the ghosts...\n");
        }

        while (num_ghosts > 0) {
            printf("What do you want to do? (1 = run, 2 = fight)\n");
            scanf("%d", &ran);

            if (ran == 1) {
                printf("You try to run away, but the ghosts catch you!\n");
                num_ghosts--;
                health--;
                printf("You lost 1 health point! You now have %d health points.\n", health);
            } else if (ran == 2) {
                if (flashlight) {
                    printf("You turn on your flashlight and the ghosts disappear!\n");
                } else {
                    printf("You bravely fight the ghosts, but unfortunately you don't have a weapon...\n");
                    num_ghosts--;
                    health--;
                    printf("You lost 1 health point! You now have %d health points.\n", health);
                }

                ghosts_defeated++;
                printf("You defeated %d ghosts so far!\n", ghosts_defeated);
            } else {
                printf("Invalid input. Try again!\n");
            }
        }

        printf("You cleared this room! You can now move on to the next room...\n\n");

        if (ghosts_defeated == 5) {
            printf("Congratulations, you defeated all the ghosts! You win!\n");
            return 0;
        }
    }

    printf("You lost all your health points and died. Game over...\n");
    return 0;
}
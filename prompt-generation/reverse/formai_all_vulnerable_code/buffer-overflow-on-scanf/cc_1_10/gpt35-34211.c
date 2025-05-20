//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to randomly generate alien encounters
int alienEncounter() {
    int alienType = rand() % 3;

    switch (alienType) {
        case 0:
            printf("You've encountered a group of tall, slimy aliens with tentacles for arms!\n");
            printf("You quickly realize they're peaceful and even offer you some delicious space fruit before you continue your journey.\n");
            return 0;
        case 1:
            printf("You've stumbled upon a pack of aggressive, sharp-toothed aliens!\n");
            printf("You draw your laser blaster and the aliens charge towards you. You manage to take down the pack and continue your mission.\n");
            return 1;
        case 2:
            printf("You've found a small group of adorable, fluffy aliens!\n");
            printf("They wave at you with their tiny arms and you can't help but smile. You exchange pleasantries before continuing on your way.\n");
            return 0;
    }
}

int main() {
    // setting up the random number generator
    srand(time(0));

    printf("Welcome, space adventurer!\n");
    printf("You're about to embark on a surreal journey through the vast expanse of space.\n");
    printf("Your objective: journey to the edge of the universe and discover the mysteries that lie beyond.\n");
    printf("Are you ready to begin? (y/n) ");

    char start;
    scanf("%c", &start);

    if (start == 'y') {
        printf("Let the adventure begin!\n");

        int distance = 0;
        int spaceDebris = 0;
        int alienCount = 0;

        while (distance < 10000) {
            int event = rand() % 3;

            switch (event) {
                case 0:
                    printf("You encounter a massive asteroid field. Roll for a chance to avoid it!\n");
                    int roll = rand() % 6 + 1;
                    if (roll >= 4) {
                        printf("You successfully navigate through the asteroid field and continue on your mission.\n");
                    } else {
                        printf("You crash into an asteroid and lose 50 units of your spaceship's health.\n");
                        spaceDebris += 50;
                    }
                    break;
                case 1:
                    printf("You've flown into a rare space cloud that has psychedelic properties. Roll for a chance to avoid it!\n");
                    int roll2 = rand() % 6 + 1;
                    if (roll2 >= 2) {
                        printf("You manage to fly through the space cloud unscathed, though your mind feels a bit fuzzy.\n");
                    } else {
                        printf("You become lost in the space cloud and lose track of your ship's location. You'll need to reroute your course.\n");
                        distance -= 100;
                    }
                    break;
                case 2:
                    printf("Incoming transmission! It's aliens calling from planet Zargon-5. Will you accept the call? (y/n) ");
                    char alienCall;
                    scanf("%c", &alienCall);
                    if (alienCall == 'y') {
                        int alienResult = alienEncounter();
                        if (alienResult == 1) {
                            spaceDebris += 10;
                            alienCount++;
                        } else {
                            distance += 100;
                        }
                    } else {
                        printf("You decline and continue on your mission.\n");
                    }
                    break;
            }
            distance += 500;
        }

        printf("Congratulations! You've successfully flown to the edge of the universe and back!\n");
        printf("Stats:\n");
        printf("Distance Traveled: %d km\n", distance);
        printf("Space Debris Collected: %d units\n", spaceDebris);
        printf("Aliens Encountered: %d\n", alienCount);
    } else {
        printf("Goodbye, space adventurer.\n");
    }

    return 0;
}
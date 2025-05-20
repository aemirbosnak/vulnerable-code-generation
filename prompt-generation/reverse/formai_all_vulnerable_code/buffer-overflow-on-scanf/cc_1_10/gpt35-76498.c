//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds) {
    // Delay function to simulate space travel time
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

int main() {
    int credits = 0, planet_chance, asteroid_chance, blackhole_chance, alien_chance, round = 1;
    char choice;

    srand(time(NULL)); // Seed the random number generator with time

    printf("Welcome to the Procedural Space Adventure!\n");

    printf("\nYou are a space adventurer, looking for credits and exploring the galaxy.\n");

    // Game loop
    while (credits < 1500) {

        // Generate chances of encountering different events
        planet_chance = rand() % 10;
        asteroid_chance = rand() % 10;
        blackhole_chance = rand() % 10;
        alien_chance = rand() % 10;

        printf("\n\nRound %d - Current credits: %d\n", round, credits);

        printf("\nChoose your next action:\n");

        printf("1. Visit a planet\n2. Mine an asteroid field\n3. Warp to a new location\n4. Refuel your ship\n5. Check your inventory\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (planet_chance <= 7) {
                    printf("\nYou found a rich mining planet and earned 200 credits!");
                    credits += 200;
                }
                else {
                    printf("\nThis planet is barren, nothing to find here...");
                }
                break;

            case '2':
                if (asteroid_chance <= 6) {
                    printf("\nYou mined a valuable asteroid field and earned 300 credits!");
                    credits += 300;
                }
                else {
                    printf("\nNothing valuable was found in this asteroid field...");
                }
                break;

            case '3':
                if (blackhole_chance <= 3) {
                    printf("\nYou got sucked into a blackhole, lost 200 credits and ended up in a new location...");
                    credits -= 200;
                }
                else {
                    printf("\nYou successfully warped to a new location!");
                }
                delay(2);
                break;

            case '4':
                printf("\nYou refueled your ship for 100 credits.");
                credits -= 100;
                break;

            case '5':
                printf("\nCurrent funds: %d", credits);
                delay(2);
                break;

            default:
                printf("\nInvalid choice, try again.");
                break;
        }

        round++; // Increase the round count by 1 after each choice
    }

    printf("\nCongratulations, you have successfully earned 1500 credits and completed your space adventure!\n");

    return 0;
}
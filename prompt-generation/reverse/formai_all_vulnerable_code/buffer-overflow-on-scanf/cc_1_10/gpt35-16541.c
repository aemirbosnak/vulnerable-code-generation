//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with system time
    int max_distance = 100; // maximum distance spaceship can travel
    int distance_traveled = 0; // initialize distance traveled to 0
    int event_occurred = 0; // initialize event occurrence to 0
    
    printf("\nWelcome to Procedural Space Adventure!\n");
    printf("Your mission is to travel as far as you can into the depths of space.\n");
    printf("Be careful and good luck!\n\n");
    
    while (distance_traveled < max_distance) {
        int event_chance = rand() % 10 + 1; // generate random number between 1 and 10
        
        if (event_chance <= 3 && event_occurred == 0) {
            printf("Oh no! A meteor shower is heading straight for your ship!\n");
            printf("What will you do?\n");
            printf("1. Try to maneuver through the meteors\n");
            printf("2. Use shields to protect the ship\n");
            
            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                int success_chance = rand() % 10 + 1; // generate random number between 1 and 10
                
                if (success_chance <= 5) {
                    printf("You successfully manuevered through the meteors and avoided damage to the ship!\n\n");
                } else {
                    printf("Unfortunately, the meteors were too intense and caused damage to the ship.\n");
                    printf("You lose 10 distance points.\n\n");
                    distance_traveled -= 10;
                }
            } else {
                printf("The shields were effective in protecting the ship!\n\n");
            }
            
            event_occurred = 1;
        } else if (event_chance >= 8 || event_occurred == 1) {
            printf("You come across a peaceful planet.\n");
            printf("What will you do?\n");
            printf("1. Land on the planet and explore\n");
            printf("2. Continue your journey in space\n");
            
            int choice;
            scanf("%d", &choice);
            
            if (choice == 1) {
                printf("You discover new plant and animal life on the planet!\n");
                printf("You gain 5 distance points.\n\n");
                distance_traveled += 5;
            } else {
                printf("You continue your journey in space.\n\n");
            }
            
            event_occurred = 0;
        } else {
            printf("You continue your journey in space.\n\n");
            event_occurred = 0;
        }
        
        distance_traveled += rand() % 10 + 1; // add distance traveled based on random number
        printf("Distance traveled: %d/%d\n", distance_traveled, max_distance);
    }
    
    printf("\nCongratulations! You have successfully completed your mission.\n");
    printf("Final distance traveled: %d.\n", distance_traveled);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time) {}
}

int main() {
    char player_name[20];
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("What is your name, space adventurer?\n");
    scanf("%s", player_name);
    printf("Greetings, %s! Your adventure begins now.\n\n", player_name);
    
    int fuel_level = 100;
    int oxygen_level = 100;
    int distance_traveled = 0;
    int random_event;
    
    while (1) {
        printf("Fuel level: %d\n", fuel_level);
        printf("Oxygen level: %d\n", oxygen_level);
        printf("Distance traveled: %d\n", distance_traveled);
        
        if (fuel_level <= 0 || oxygen_level <= 0) {
            printf("Game over, %s! You ran out of fuel or oxygen.\n", player_name);
            break;
        }
        
        delay(1);
        printf("\nYou encounter a random event.\n");
        random_event = rand() % 4;
        switch (random_event) {
            case 0: // Fuel asteroid
                printf("You found a fuel asteroid and refueled.\n");
                fuel_level += 20;
                break;
            case 1: // Oxygen asteroid
                printf("You found an oxygen asteroid and replenished your air supply.\n");
                oxygen_level += 20;
                break;
            case 2: // Piracy
                printf("You encountered space pirates and lost some fuel.\n");
                fuel_level -= 20;
                break;
            case 3: // Black hole
                printf("You got too close to a black hole and lost some distance traveled.\n");
                distance_traveled -= 20;
                break;
        }
        
        fuel_level -= 10;
        oxygen_level -= 10;
        distance_traveled += 10;
    }
    
    return 0;
}
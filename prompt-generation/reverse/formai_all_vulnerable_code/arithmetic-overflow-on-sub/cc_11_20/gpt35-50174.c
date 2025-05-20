//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
// Procedural Space Adventure in C
// By [Your Name]
// Inspired by Linus Torvalds

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize seed for random number generation
    
    // Initializing game variables
    int distance = 1000000; // In kilometers
    int fuel = 1000; // In fuel units
    int temperature = 20; // In Celsius
    int health = 100; // In percentage
    char choice; // User's choice (Y/N)
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to travel to a distant planet.\n");
    printf("You have to manage your spaceship's fuel, temperature, and health to reach the planet safely.\n");
    
    // Game loop
    while (distance > 0) {
        printf("Distance remaining: %dkm\n", distance);
        printf("Fuel remaining: %d units\n", fuel);
        printf("Temperature: %dC\n", temperature);
        printf("Health: %d%%\n", health);
        
        printf("Do you want to continue flying? (Y/N)\n");
        scanf(" %c", &choice);
        
        if (choice == 'N' || choice == 'n') {
            printf("Game over. Mission aborted.\n");
            return 0;
        }
        
        // Generate random events
        int event = rand() % 3;
        switch (event) {
            case 0:
                printf("You encounter a meteor shower!\n");
                health -= 20;
                printf("Health decreased by 20%%.\n");
                break;
            case 1:
                printf("Your spaceship's engine malfunctions!\n");
                fuel -= 200;
                printf("Fuel decreased by 200 units.\n");
                break;
            case 2:
                printf("Temperature drops rapidly!\n");
                temperature -= 30;
                printf("Temperature decreased by 30C.\n");
                break;
        }
        
        // Update game variables based on user's choice
        printf("How much fuel do you want to use?\n");
        int used_fuel;
        scanf("%d", &used_fuel);
        fuel -= used_fuel;
        distance -= used_fuel * 10;
        temperature += used_fuel / 10;
        health -= distance / 100000;
        
        // Check if game over conditions are met
        if (distance <= 0) {
            printf("Congratulations! You have reached the planet!\n");
            printf("Mission completed.\n");
            return 0;
        }
        if (fuel <= 0) {
            printf("You have run out of fuel!\n");
            printf("Game over. Mission failed.\n");
            return 0;
        }
        if (temperature >= 50) {
            printf("Your spaceship overheats and explodes!\n");
            printf("Game over. Mission failed.\n");
            return 0;
        }
        if (health <= 0) {
            printf("Your crew succumbs to space sickness!\n");
            printf("Game over. Mission failed.\n");
            return 0;
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number within given range
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Declare variables
    int x, y, fuel, max_fuel, distance, speed, minutes;
    float time_taken;
    
    // Print welcome message
    printf("Welcome to Procedural Space Adventure!\n");
    
    // Get user input for starting x and y coordinates
    printf("Enter starting x coordinate: ");
    scanf("%d", &x);
    printf("Enter starting y coordinate: ");
    scanf("%d", &y);
    
    // Generate random distance from Earth
    distance = random_number(100, 500);
    printf("You are %d miles away from Earth\n\n", distance);
    
    // Set maximum fuel and initialize current fuel
    max_fuel = distance / 10;
    fuel = max_fuel;
    printf("Your spaceship has a maximum fuel capacity of %d\n", max_fuel);
    
    // Get user input for speed
    printf("Enter desired speed (in miles per hour): ");
    scanf("%d", &speed);
    
    // Calculate time taken to reach destination
    minutes = distance * 60 / speed;
    time_taken = (float) minutes / 60;
    printf("It will take %.2f hours to reach your destination\n\n", time_taken);
    
    // Start journey
    printf("Initiating journey...\n\n");
    while (distance > 0 && fuel > 0) {
        // Display current status
        printf("Current X coordinate: %d\n", x);
        printf("Current Y coordinate: %d\n", y);
        printf("Current fuel level: %d/%d\n", fuel, max_fuel);
        printf("Distace remaining to reach destination: %d miles\n\n", distance);
        
        // Generate random events
        if (random_number(1, 10) <= 3) {
            printf("Warning: Space debris detected ahead. Evading...\n");
            x += random_number(-10, 10);
            y += random_number(-10, 10);
        }
        if (random_number(1, 10) <= 2) {
            printf("Alert: Engine failure imminent. Making repairs...\n");
            fuel -= random_number(5, 10);
        }
        
        // Get user input for direction
        printf("Enter direction (1: North, 2: South, 3: East, 4: West): ");
        int direction;
        scanf("%d", &direction);
        switch (direction) {
            case 1: y += random_number(1, 5); break;
            case 2: y -= random_number(1, 5); break;
            case 3: x += random_number(1, 5); break;
            case 4: x -= random_number(1, 5); break;
            default: printf("Invalid direction\n"); break;
        }
        
        // Decrease fuel according to distance traveled
        int distance_traveled = random_number(10, 50);
        fuel -= distance_traveled / 10;
        distance -= distance_traveled;
        
        // Delay for 1 second
        printf("\n");
        for (int i = 0; i < 100000000; i++) {}
    }
    
    // Display final status
    if (distance <= 0) {
        printf("Destination reached successfully!\n");
    } else {
        printf("Out of fuel. Mission failed.\n");
    }
    printf("Final X coordinate: %d\n", x);
    printf("Final Y coordinate: %d\n", y);
    printf("Final fuel level: %d/%d\n", fuel, max_fuel);
    printf("Time taken: %.2f hours\n", time_taken);
    
    return 0;
}
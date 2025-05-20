//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int explore(int fuel, int distance);

int main() {
    int fuel = 1000;
    int distance = 0;
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You have 1000 units of fuel to explore the unknown depths of space!\n\n");
    printf("Begin your journey.\n");
    
    explore(fuel, distance);
    
    return 0;
}

int explore(int fuel, int distance) {
    srand(time(NULL));
    int event = rand() % 3;
    
    if (fuel <= 0) {
        printf("You have run out of fuel and are stranded in space.\n");
        return 0;
    }
    
    if (distance >= 100000) {
        printf("Congratulations! You have reached the edge of our galaxy!\n");
        return 0;
    }
    
    printf("Distance traveled: %d\nFuel remaining: %d\n", distance, fuel);
    printf("Choose your next action:\n");
    printf("1. Warp to a new sector\n2. Scan for resources\n3. Refuel at a nearby station\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    if (choice == 1) {
        int warp_distance = rand() % 10000 + 1000;
        printf("Warping to a new sector...\n");
        printf("You have traveled %d light years.\n", warp_distance);
        distance += warp_distance;
        fuel -= warp_distance / 10;
    }
    else if (choice == 2) {
        int resource_found = rand() % 2;
        if (resource_found) {
            int resource_amount = rand() % 1000 + 500;
            printf("Scanning for resources...\n");
            printf("You have found %d units of resources.\n", resource_amount);
            printf("Adding resources to cargo hold.\n");
        }
        else {
            printf("Scanning for resources...\n");
            printf("No resources found.\n");
        }
        fuel -= 100;
    }
    else if (choice == 3) {
        printf("Refueling at a nearby station...\n");
        printf("Fuel tanks filled.\n");
        fuel = 1000;
    }
    else {
        printf("Invalid choice. Please try again.\n");
    }
    
    printf("\n");
    
    return explore(fuel, distance);
}
//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Time Travel Simulator\n");
    
    // Ask user for current year
    int currentYear;
    printf("Please enter the current year: ");
    scanf("%d", &currentYear);
    
    // Generate random year between current year and 10,000 years in the future
    srand(time(NULL));
    int futureYear = rand() % 10000 + currentYear;
    
    printf("You will be travelling to the year %d\n", futureYear);
    
    // Ask user for mode of transportation
    int choice;
    printf("Please choose a mode of transportation:\n");
    printf("1. Time machine\n");
    printf("2. Teleportation device\n");
    scanf("%d", &choice);
    
    // Switch statement to execute different actions based on mode of transportation
    switch (choice) {
        case 1:
            printf("You will be using a time machine to travel to the future.\n");
            break;
        case 2:
            printf("You will be using a teleportation device to travel to the future.\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }
    
    // Simulate travel to the future
    printf("Preparing for travel...\n");
    int count;
    for (count = 1; count <= 10; count++) {
        printf("%d...\n", count);
    }
    printf("You have arrived in the year %d!\n", futureYear);
    
    // Ask user for their age
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    // Calculate user's age in the future year
    int ageInFuture = age + (futureYear - currentYear);
    
    // Output user's age in the future year
    printf("In the year %d, you will be %d years old!\n", futureYear, ageInFuture);
    
    printf("Thank you for using the Time Travel Simulator!\n");
    
    return 0;
}
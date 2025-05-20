//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main() {
    // Set up a random seed for the timer
    srand(time(NULL));
    
    // Set up some variables
    char name[20];
    int age;
    float weight;
    
    // Prompt the user for their name and age
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    // Calculate the weight based on the age
    if (age < 18) {
        weight = (age / 10) * 10;
    } else if (age >= 18 && age < 40) {
        weight = (age / 2) * 40;
    } else {
        weight = (age - 40) * 20;
    }
    
    // Print out the results
    printf("Your name is %s, and you are %d years old.\n", name, age);
    printf("Your weight is %.2f kilograms.\n", weight);
    
    // Generate a random planet name and coordinate
    char planetName[20];
    float planetX, planetY;
    srand(time(NULL));
    planetName[0] = 'A' + (rand() % 26);
    planetName[1] = 'B' + (rand() % 26);
    planetName[2] = 'C' + (rand() % 26);
    planetName[3] = 'D' + (rand() % 26);
    planetName[4] = 'E' + (rand() % 26);
    planetName[5] = 'F' + (rand() % 26);
    planetName[6] = 'G' + (rand() % 26);
    planetName[7] = 'H' + (rand() % 26);
    planetName[8] = 'I' + (rand() % 26);
    planetName[9] = 'J' + (rand() % 26);
    planetName[10] = 'K' + (rand() % 26);
    planetName[11] = 'L' + (rand() % 26);
    planetName[12] = 'M' + (rand() % 26);
    planetName[13] = 'N' + (rand() % 26);
    planetName[14] = 'O' + (rand() % 26);
    planetName[15] = 'P' + (rand() % 26);
    planetName[16] = 'Q' + (rand() % 26);
    planetName[17] = 'R' + (rand() % 26);
    planetName[18] = 'S' + (rand() % 26);
    planetName[19] = 'T' + (rand() % 26);
    planetX = (rand() % 1000) - 500;
    planetY = (rand() % 1000) - 500;
    
    // Print out the results
    printf("Your ship has landed on %s, located at (%f, %f)\n", planetName, planetX, planetY);
    
    // Sleep for a random amount of time to simulate travel
    sleep(rand() % 10);
    
    return 0;
}
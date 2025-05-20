//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>

// defining a struct for a planet
typedef struct {
    char name[20];
    float radius;
    char atmosphere[50];
} Planet;

// function to display planet info
void displayPlanet(Planet p) {
    printf("Name: %s\n", p.name);
    printf("Radius: %.2f km\n", p.radius);
    printf("Atmosphere: %s\n", p.atmosphere);
}

int main() {
    // creating an array of planets
    Planet planets[] = {
        {"Mercury", 2440, "None"},
        {"Venus", 6052, "Carbon dioxide"},
        {"Earth", 6378, "Nitrogen, oxygen, argon, carbon dioxide"},
        {"Mars", 3396, "Carbon dioxide, nitrogen, argon"},
        {"Jupiter", 69911, "Hydrogen, helium, methane, ammonia"},
        {"Saturn", 58232, "Hydrogen, helium, methane"},
        {"Uranus", 25362, "Hydrogen, helium, methane"},
        {"Neptune", 24622, "Hydrogen, helium, methane"}
    };
    
    // printing a welcome message
    printf("Welcome to the Space Adventure game!\n");
    printf("You are currently on Earth. The goal is to visit all planets in the given order.\n");
    printf("Let's start our journey!\n");
    
    // looping through the planets array
    for (int i = 0; i < 8; i++) {
        // displaying the current planet's info
        printf("\n---\n");
        printf("Planet #%d: ", i+1);
        displayPlanet(planets[i]);
        
        // asking the user if they want to visit the planet
        char choice;
        printf("Do you want to visit this planet? (y/n): ");
        scanf(" %c", &choice);
        
        // checking the user's choice
        if (choice == 'y' || choice == 'Y') {
            // printing a message indicating that the user is visiting the planet
            printf("Great, let's go to %s!\n", planets[i].name);
        } else {
            // printing a message indicating that the user is not visiting the planet
            printf("Okay, we will not visit %s.\n", planets[i].name);
        }
        
        // printing a message indicating that the user is leaving the planet
        printf("Leaving %s...\n", planets[i].name);
    }
    
    // printing a message indicating the end of the game
    printf("\n---\n");
    printf("Congratulations, you have visited all planets in the given order! End of the game.\n");
    
    return 0;
}
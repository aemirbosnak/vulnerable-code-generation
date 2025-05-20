//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// struct to represent a location in space
typedef struct location {
    float x;
    float y;
    float z;
} location;

// function to move the spaceship to a new location
void move(location* current_location, location destination) {
    printf("Moving spaceship to location (%f, %f, %f)\n", destination.x, destination.y, destination.z);
    current_location->x = destination.x;
    current_location->y = destination.y;
    current_location->z = destination.z;
}

// function to simulate a battle with space pirates
int battle(int ship_health, int pirate_health) {
    printf("Initiating battle with space pirates...\n");
    while (ship_health > 0 && pirate_health > 0) {
        // simulate a round of combat
        int ship_damage = rand() % 10 + 1;
        int pirate_damage = rand() % 10 + 1;
        ship_health -= pirate_damage;
        pirate_health -= ship_damage;
    }
    if (ship_health > 0) {
        printf("Victory! Space pirates have been defeated.\n");
        return 1;
    } else {
        printf("Defeat! The spaceship has been destroyed.\n");
        return 0;
    }
}

int main() {
    // create a starting location for the spaceship
    location current_location = {0.0f, 0.0f, 0.0f};

    // prompt the user for a destination location
    location destination;
    printf("Enter the x, y, and z coordinates of your destination (separated by spaces): ");
    scanf("%f%f%f", &destination.x, &destination.y, &destination.z);

    // move the spaceship to the destination
    move(&current_location, destination);

    // simulate a battle with space pirates
    int ship_health = 100;
    int pirate_health = 50;
    int victory = battle(ship_health, pirate_health);

    // print final message based on outcome of battle
    if (victory) {
        printf("Congratulations! You have successfully completed your space adventure.\n");
    } else {
        printf("Better luck next time. Your space adventure has come to an unfortunate end.\n");
    }

    return 0;
}
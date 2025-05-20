//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of planets in the universe
#define MAX_PLANETS 1000

// Define the structure of a planet
typedef struct Planet
{
    char name[20];
    int x, y, z;
    float mass, temperature;
    struct Planet* next;
} Planet;

// Function to create a new planet
Planet* create_planet()
{
    Planet* new_planet = malloc(sizeof(Planet));
    new_planet->name[0] = '\0';
    new_planet->x = 0;
    new_planet->y = 0;
    new_planet->z = 0;
    new_planet->mass = 0.0f;
    new_planet->temperature = 0.0f;
    new_planet->next = NULL;

    return new_planet;
}

// Function to add a new planet to the universe
void add_planet(Planet* universe)
{
    Planet* new_planet = create_planet();

    // Assign a name to the new planet
    printf("Enter the name of the new planet: ");
    scanf("%s", new_planet->name);

    // Assign the new planet to the universe
    new_planet->next = universe;
    universe = new_planet;
}

// Function to print the planets in the universe
void print_planets(Planet* universe)
{
    Planet* current_planet = universe;

    printf("The planets in the universe are:\n");

    while (current_planet)
    {
        printf("%s (%d, %d, %d), mass %.2f, temperature %.2f\n", current_planet->name, current_planet->x, current_planet->y, current_planet->z, current_planet->mass, current_planet->temperature);
        current_planet = current_planet->next;
    }
}

int main()
{
    // Create the first planet in the universe
    Planet* universe = create_planet();

    // Add a few more planets to the universe
    add_planet(universe);
    add_planet(universe);
    add_planet(universe);

    // Print the planets in the universe
    print_planets(universe);

    return 0;
}
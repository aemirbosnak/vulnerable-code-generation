//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Planet structure */
typedef struct planet {
    char name[20];
    int distance;
    bool visited;
} Planet;

/* Function to initialize the Galaxy */
void initGalaxy(Planet galaxy[], int size) {
    char *names[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    
    for (int i = 0; i < size; i++) {
        strcpy(galaxy[i].name, names[i]);
        galaxy[i].distance = rand() % 31 + 10; // Random distance between 10-40 million miles
        galaxy[i].visited = false; // None of the planets are visited initially
    }
}

/* Function to print the current Galaxy */
void printGalaxy(Planet galaxy[], int size) {
    printf("Galaxy:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %d million miles away\n", galaxy[i].name, galaxy[i].distance);
    }
}

/* Function to find the optimal planet to travel to */
int findPlanet(Planet galaxy[], int size) {
    int index = 0; // Starting planet index
    int min_distance = galaxy[0].distance; // Starting planet distance
    
    for (int i = 1; i < size; i++) {
        if (!galaxy[i].visited && galaxy[i].distance < min_distance) {
            index = i;
            min_distance = galaxy[i].distance;
        }
    }
    
    return index;
}

int main() {
    int size = 9; // Total number of planets in the Galaxy
    Planet galaxy[size]; // Needed to declare it here before srand
    
    srand(time(NULL)); // To generate random values
    
    initGalaxy(galaxy, size); // Initializing the Galaxy with random distance values
    
    printf("Welcome to the Procedural Space Adventure!\n");
    
    int current_planet = 0; // Starting planet index
    int total_distance = 0; // Total distance travelled
    
    while (true) {
        printf("\nYou are currently on %s.\n", galaxy[current_planet].name);
        
        int travel_planet = findPlanet(galaxy, size);
        printf("The best planet to travel to next is %s.\n", galaxy[travel_planet].name);
        
        total_distance += galaxy[travel_planet].distance;
        printf("You travelled %d million miles.\n", galaxy[travel_planet].distance);
        
        current_planet = travel_planet;
        galaxy[current_planet].visited = true;
        
        if (current_planet == size - 1) { // If Pluto is visited, end the journey
            printf("\nCongratualations! You completed the Procedural Space Adventure.\n");
            printf("You travelled a total distance of %d million miles.\n", total_distance);
            break;
        }
        
        char choice;
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'n') { // If user wants to quit
            printf("\nYou quit the Procedural Space Adventure.\n");
            printf("You travelled a total distance of %d million miles.\n", total_distance);
            break;
        }
    }
    
    return 0;
}
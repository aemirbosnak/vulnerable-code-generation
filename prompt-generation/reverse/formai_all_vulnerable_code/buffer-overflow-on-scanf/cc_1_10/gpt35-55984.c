//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct planet {
    char name[20];
    int distance;
    int temperature;
    int size;
};

void print_planet_info(struct planet p) {
    printf("Planet name: %s\n", p.name);
    printf("Distance from Earth: %d light years\n", p.distance);
    printf("Surface temperature: %d K\n", p.temperature);
    printf("Size: %d miles in diameter\n", p.size);
}

int main() {
    struct planet exoplanet1 = {"Kepler-452b", 1400, 740, 20000};
    struct planet exoplanet2 = {"Proxima Centauri b", 4, 234, 3214};
    struct planet exoplanet3 = {"HD 219134 b", 21, 1200, 19320};
    struct planet current_planet;
    char choice[10];
    int quit = 0;
    
    printf("Welcome to the C Procedural Space Adventure Program!\n");
    
    while(!quit) {
        printf("You are currently on a spaceship. Where would you like to go?\n");
        printf("1. Kepler-452b\n");
        printf("2. Proxima Centauri b\n");
        printf("3. HD 219134 b\n");
        printf("Q. Quit program\n");
        printf("Enter choice: ");
        scanf("%s", choice);
        
        switch(choice[0]) {
            case '1':
                current_planet = exoplanet1;
                printf("Traveling to Kepler-452b...\n");
                break;
            case '2':
                current_planet = exoplanet2;
                printf("Traveling to Proxima Centauri b...\n");
                break;
            case '3':
                current_planet = exoplanet3;
                printf("Traveling to HD 219134 b...\n");
                break;
            case 'Q':
            case 'q':
                printf("Exiting program...\n");
                quit = 1;
                break;
            default:
                printf("Invalid choice. Please choose again.\n\n");
                continue;
        }
        if(!quit) {
            printf("You have arrived at %s.\n", current_planet.name);
            print_planet_info(current_planet);
            printf("\n");
        }
    }
    
    return 0;
}
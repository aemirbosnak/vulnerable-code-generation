//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int fuel;
    int health;
    int score;
    Position position;
} Spaceship;

typedef struct {
    char name[20];
    Position position;
} Planet;

void print_planets(Planet planets[], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("%d. %s (%d, %d)\n", i+1, planets[i].name, planets[i].position.x, planets[i].position.y);
    }
}

void print_spaceship(Spaceship spaceship) {
    printf("Fuel: %d\n", spaceship.fuel);
    printf("Health: %d\n", spaceship.health);
    printf("Score: %d\n", spaceship.score);
    printf("Position: (%d, %d)\n", spaceship.position.x, spaceship.position.y);
}

int main() {
    int num_planets = 5;
    Planet planets[num_planets];
    
    for (int i = 0; i < num_planets; i++) {
        printf("Enter planet #%d name: ", i+1);
        scanf("%s", planets[i].name);
        printf("Enter planet #%d x coordinate: ", i+1);
        scanf("%d", &planets[i].position.x);
        printf("Enter planet #%d y coordinate: ", i+1);
        scanf("%d", &planets[i].position.y);
    }
    
    printf("Planets:\n");
    print_planets(planets, num_planets);
    
    Spaceship spaceship = {100, 100, 0, {0, 0}};
    
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Travel to planet\n");
        printf("2. Refuel spaceship\n");
        printf("3. Repair spaceship\n");
        printf("4. Quit\n");
        
        int choice = 0;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            {
                printf("Choose a planet to travel to:\n");
                print_planets(planets, num_planets);
                
                int planet_choice = 0;
                scanf("%d", &planet_choice);
                
                if (planet_choice >= 1 && planet_choice <= num_planets) {
                    Planet planet = planets[planet_choice-1];
                    int distance = abs(spaceship.position.x - planet.position.x) + abs(spaceship.position.y - planet.position.y);
                    int fuel_required = distance * 10;
                    
                    if (fuel_required > spaceship.fuel) {
                        printf("Not enough fuel to travel to %s\n", planet.name);
                    } else {
                        spaceship.fuel -= fuel_required;
                        spaceship.position = planet.position;
                        printf("Traveled to %s in %d turns\n", planet.name, distance);
                        
                        // Chance of encountering aliens
                        int chance = rand() % 10;
                        if (chance == 0) {
                            printf("Aliens have attacked your ship! -10 health\n");
                            spaceship.health -= 10;
                            if (spaceship.health <= 0) {
                                printf("Your spaceship has been destroyed. Game over.\n");
                                exit(0);   
                            }
                        }
                        
                        // Chance of finding treasure
                        chance = rand() % 10;
                        if (chance == 0) {
                            int treasure = rand() % 100;
                            printf("You discovered %d points worth of treasure!\n", treasure);
                            spaceship.score += treasure; 
                        }
                    }
                } else {
                    printf("Invalid choice\n");
                }
            }
            break;
            
            case 2:
            {
                printf("Refueling spaceship...\n");
                spaceship.fuel = 100;
                printf("Spaceship refueled!\n");
            }
            break;
            
            case 3:
            {
                printf("Repairing spaceship...\n");
                spaceship.health = 100;
                printf("Spaceship repaired!\n");
            }
            break;
            
            case 4:
            {
                printf("Quitting game...\n");
                exit(0);
            }
            break;
            
            default:
            {
                printf("Invalid choice\n");
            }
            break;
        }
        
        print_spaceship(spaceship);
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Player's name 
    char name[20];
    
    printf("Welcome to the Space Adventure! Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! You are about to embark on a mission into deep space.\n\n", name);
    
    // Initializing game stats 
    int fuel = 100;
    int health = 100;
    int aliens_killed = 0;
    int distance_traveled = 0;
    
    printf("You have just left Earth and are traveling through space.\n");
    printf("Let's see if you have what it takes to survive!\n\n");
    
    // Gameplay loop 
    while (health > 0 && fuel > 0) {
        
        // Random event generator 
        int event = rand() % 4;
        
        switch (event) {
            
            case 0:
                // Travel through space 
                fuel -= 20;
                distance_traveled += 50;
                printf("You traveled 50 light years through space.\n");
                break;
                
            case 1:
                // Encounter an alien 
                health -= 30;
                aliens_killed++;
                printf("You encountered an alien and defeated it.\n");
                break;
                
            case 2:
                // Find a space station 
                health += 20;
                printf("You found a space station and restored your health.\n");
                break;
                
            case 3:
                // Asteroid field 
                fuel -= 10;
                health -= 10;
                printf("You encountered an asteroid field and took some damage.\n");
                break;
        }
        
        // Display player stats 
        printf("Fuel: %d    Health: %d    Aliens Killed: %d    Distance Traveled: %d\n\n", fuel, health, aliens_killed, distance_traveled);
        
    }
    
    // Game over 
    if (health <= 0) {
        printf("Your ship was destroyed. Game over.\n");
    } else if (fuel <= 0) {
        printf("You ran out of fuel and are stranded in space. Game over.\n");
    } else {
        printf("Congratulations, you completed the mission!\n");
        printf("Final stats: Fuel: %d    Health: %d    Aliens Killed: %d    Distance Traveled: %d\n", fuel, health, aliens_killed, distance_traveled);
    }
    
    return 0;
}
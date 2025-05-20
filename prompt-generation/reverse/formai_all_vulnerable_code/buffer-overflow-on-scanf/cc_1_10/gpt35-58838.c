//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: modular
#include <stdio.h>
#include <string.h>

// function to print the spaceship's current status
void printStatus(int fuel, int health, int shield) {
    printf("Fuel: %d\n", fuel);
    printf("Health: %d\n", health);
    printf("Shield: %d\n", shield);
}

// function to simulate the spaceship's movement
void moveSpaceship(int *fuel, int *health, int *shield) {
    *fuel -= 10;
    *health -= 5;
    *shield -= 1;
}

// function to simulate the spaceship's battle
void battleSpaceship(int *health, int *shield) {
    *health -= 20;
    *shield -= 5;
}

int main() {
    // initialize spaceship status
    int fuel = 100;
    int health = 100;
    int shield = 50;
    
    // print current status
    printStatus(fuel, health, shield);
    
    // start space adventure loop
    char choice[10];
    while (1) {
        printf("What would you like to do? (move/battle/quit): ");
        scanf("%s", choice);
        
        if (strcmp(choice, "move") == 0) {
            // simulate spaceship movement
            moveSpaceship(&fuel, &health, &shield);
            
            // check if spaceship ran out of fuel
            if (fuel <= 0) {
                printf("You ran out of fuel! Game over.\n");
                break;
            }
            
            // print current status
            printStatus(fuel, health, shield);
        }
        else if (strcmp(choice, "battle") == 0) {
            // simulate spaceship battle
            battleSpaceship(&health, &shield);
            
            // check if spaceship's health reaches 0
            if (health <= 0) {
                printf("Your spaceship was destroyed! Game over.\n");
                break;
            }
            
            // print current status
            printStatus(fuel, health, shield);
        }
        else if (strcmp(choice, "quit") == 0) {
            // end space adventure loop
            break;
        }
        else {
            // invalid choice
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
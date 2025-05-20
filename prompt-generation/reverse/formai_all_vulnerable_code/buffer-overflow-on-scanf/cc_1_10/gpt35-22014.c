//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself standing in front of an old, creaky house.\n");
    printf("Do you dare enter? (Y/N): ");
    
    char input;
    scanf("%c", &input);
    
    if (input != 'Y' && input != 'y') {
        printf("You turn around and run away. Coward.\n");
        return 0;
    }
    
    printf("You cautiously make your way inside the house.\n");
    printf("The door slams shut behind you, and you are surrounded by darkness.\n");
    
    int room = 1;
    int ghosts = 0;
    int health = 100;
    
    while (health > 0 && room <= 10) {
        printf("\nYou are in room %d.\n", room);
        
        int encounter = rand() % 3;
        
        if (encounter == 0) { // Room is empty
            printf("The room is empty and you breathe a sigh of relief.\n");
        } else if (encounter == 1) { // Room has ghosts
            int numGhosts = rand() % 5 + 1; // random number of ghosts from 1 to 5
            
            ghosts += numGhosts;
            health -= (numGhosts * 10);
            
            printf("There are %d ghosts in this room!\n", numGhosts);
            printf("You lose %d health points.\n", (numGhosts * 10));
            
            if (health <= 0) {
                printf("You have been killed by the ghosts. Game over.\n");
                return 0;
            }
        } else { // Room has treasure
            int treasure = rand() % 1000;
            
            printf("You have found a treasure worth %d gold!\n", treasure);
        }
        
        room++;
    }
    
    printf("\nCongratulations! You have made it out of the haunted house alive.\n");
    printf("You collected %d gold and encountered %d ghosts.\n", (room - 1) * 1000, ghosts);
    
    return 0;
}
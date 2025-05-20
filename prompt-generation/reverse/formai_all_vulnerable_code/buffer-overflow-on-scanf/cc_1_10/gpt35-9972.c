//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int room, turns, ghost, trap, treasure, status;
    time_t t;
    
    srand((unsigned) time(&t)); // initialize random seed
    
    printf("*** Welcome to the Haunted House Simulator! ***\n");
    printf("You have entered a haunted house with 10 rooms.\n");
    printf("There are ghosts, traps, and treasure scattered throughout.\n");
    printf("You must find the treasure and make it out alive!\n\n");
    
    room = 1; // start in room 1
    turns = 0; // initialize turns
    
    while (room != 10) { // game continues until player reaches room 10
        printf("*** Room %d ***\n", room);
        
        ghost = rand() % 2; // randomly determine if there is a ghost in the room
        trap = rand() % 2; // randomly determine if there is a trap in the room
        treasure = rand() % 2; // randomly determine if there is treasure in the room
        
        if (ghost) {
            printf("Oh no, there is a ghost in this room!\n");
            turns++;
            continue; // player cannot leave the room with a ghost
        }
        
        if (trap) {
            printf("There is a trap in this room!\n");
            turns++;
            continue; // player cannot leave the room with a trap
        }
        
        if (treasure) {
            printf("Congratulations, you found the treasure in this room!\n");
            turns++;
        }
        
        printf("Which room would you like to move to? (enter a number 1-10)\n");
        scanf("%d", &room);
        turns++;
    }
    
    printf("*** You made it to room 10 with the treasure! ***\n");
    printf("It took you %d turns to find the treasure.\n", turns);
    
    status = rand() % 2; // randomly determine if player makes it out alive
    if (status)
        printf("Congratulations, you made it out alive!\n");
    else
        printf("Oh no, you were caught by the ghosts and did not make it out alive.\n");
    
    return 0;
}
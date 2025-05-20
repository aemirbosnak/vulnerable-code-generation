//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROOMS 5
#define MAX_GHOSTS 3

int main(){
    int rooms[MAX_ROOMS];
    int ghosts[MAX_GHOSTS];
    int playerLocation = 0;
    int gameOver = 0;
    srand(time(0));

    // Initialize game state
    for(int i=0; i<MAX_ROOMS; i++){
        rooms[i] = 0;   // No ghosts initially
    }
    for(int i=0; i<MAX_GHOSTS; i++){
        ghosts[i] = rand() % MAX_ROOMS; // Randomly assign ghosts to rooms
        rooms[ghosts[i]]++; // Increment ghost count in the room
    }

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in Room %d.\n", playerLocation+1);

    while(!gameOver){
        int ghostCount = rooms[playerLocation];
        if(ghostCount > 0){
            printf("You encounter %d ghost(s) in this room! Game Over.\n", ghostCount);
            gameOver = 1;
        }else{
            printf("This room is safe. You can move to the following rooms:\n");
            for(int i=0; i<MAX_ROOMS; i++){
                if(i == playerLocation){
                    printf("Room %d - You are here.\n", i+1);
                }else{
                    printf("Room %d\n", i+1);
                }
            }
            int choice;
            printf("Which room would you like to move to? ");
            scanf("%d", &choice);
            if(choice < 1 || choice > MAX_ROOMS){
                printf("Invalid choice! Try again.\n");
            }else{
                playerLocation = choice-1;
                printf("You move to Room %d.\n", playerLocation+1);
            }
        }
    }

    printf("Thank you for playing the Haunted House Simulator!\n");
    return 0;
}
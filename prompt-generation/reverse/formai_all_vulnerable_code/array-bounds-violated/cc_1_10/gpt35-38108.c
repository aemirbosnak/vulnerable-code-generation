//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));// initialize random seed

    int rooms[10]; // array to represent 10 rooms in the haunted house

    for(int i = 0; i < 10; i++){
        rooms[i] = rand() % 3; // randomly choose a room type: 0 (empty), 1 (ghost), 2 (treasure)
    }

    int player_pos = 0; // player starts in the first room
    int moves = 0; // initialize moves counter

    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("Try to find the treasure in the least number of moves possible.\n");

    while(1){ // game loop
        
        printf("\nYou are in room %d.\n", player_pos+1);
        printf("There is ");
        
        if(rooms[player_pos] == 0){
            printf("nothing here.");
        }
        else if(rooms[player_pos] == 1){
            printf("a ghost here!");
        }
        else{
            printf("treasure here!");
            printf("\nCongratulations, you found the treasure in %d moves!\n", moves);
            break;
        }
        
        printf("\nWhich room do you want to enter? ");
        scanf("%d", &player_pos);
        player_pos--; // adjust for 0-based array
        
        if(player_pos < 0 || player_pos > 9){
            printf("Invalid room number. Try again.\n");
        }
        else{
            moves++; // increment moves counter
            if(rooms[player_pos] == 1){
                printf("\nA ghost has scared you! You are taken back to the first room.\n");
                player_pos = 0;
            }
        }
        
    }

    return 0;
}
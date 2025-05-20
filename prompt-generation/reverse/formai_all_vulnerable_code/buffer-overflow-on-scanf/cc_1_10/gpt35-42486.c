//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //intro
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself at the entrance of a haunted house. It's getting dark and you need to find shelter, but beware of the ghosts...\n\n");
    printf("Press any key to continue...\n");
    getchar();

    //variables
    int position = 0;
    int steps_left = 10;
    int ghost_seen = 0;
    srand(time(NULL));

    //main loop
    while(steps_left > 0){
        //display current position and remaining steps
        printf("You are now at position %d and have %d steps left.\n", position, steps_left);

        //check if ghost is present
        int ghost_present = rand() % 2;
        if(ghost_present){
            printf("Oh no, you hear a ghost!\n");
            ghost_seen = 1;
        }
        
        //ask user for direction
        printf("Which direction do you want to go? (left or right)\n");
        char input[10];
        scanf("%s", input);

        //update position
        if(input[0] == 'l'){
            position--;
        }
        else if(input[0] == 'r'){
            position++;
        }
        else{
            printf("Invalid input, please try again!\n");
            continue;
        }

        //check if user encountered a ghost
        if(ghost_seen && position == 0){
            printf("You were caught by the ghost, game over!\n");
            return 0;
        }

        //decrease remaining steps
        steps_left--;
    }

    //ending
    printf("Congratulations, you made it through the haunted house!\n");
    return 0;
}
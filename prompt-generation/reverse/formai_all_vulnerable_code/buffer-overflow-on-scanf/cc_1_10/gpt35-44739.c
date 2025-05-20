//FormAI DATASET v1.0 Category: Robot movement control ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello! I am your personal C Robot. Let's move around!\n");

    int position_X = 0; //initialize X position to 0
    int position_Y = 0; //initialize Y position to 0

    printf("Current position: (%d, %d)\n", position_X, position_Y);

    char direction; //store user's input for direction

    do{
        printf("Which direction would you like to go? (U)p, (D)own, (L)eft, or (R)ight?\n");
        scanf(" %c", &direction); //get user's input for direction and store it in direction variable

        switch(direction){
            case 'U':
            case 'u':
                position_Y++; //increment Y position if user chooses up
                break;

            case 'D':
            case 'd':
                position_Y--; //decrement Y position if user chooses down
                break;

            case 'L':
            case 'l':
                position_X--; //decrement X position if user chooses left
                break;

            case 'R':
            case 'r':
                position_X++; //increment X position if user chooses right
                break;

            default:
                printf("Invalid input!\n"); //display error message if user enters invalid input
                break;
        }

        printf("Current position: (%d, %d)\n", position_X, position_Y);

    }while(1); //repeat infinitely

    return 0;
}
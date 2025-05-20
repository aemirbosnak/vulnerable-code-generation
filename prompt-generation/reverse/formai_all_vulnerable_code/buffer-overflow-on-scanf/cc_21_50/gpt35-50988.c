//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed random number generator with current time
    int rooms[10][10]; //2D array representing the haunted house
    int player_x = 0, player_y = 0; //starting position of the player

    //generate random layout for the haunted house
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            rooms[i][j] = rand() % 4; //randomly set room type
        }
    }

    //start the game
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Enter 'q' at any time to quit.\n");
    printf("You are currently in room (%d,%d).\n", player_x, player_y);

    char input = ' ';
    while(input != 'q') {
        //print current room description
        switch(rooms[player_x][player_y]) {
            case 0:
                printf("You are in a dusty old library. There is a book missing from the shelf.\n");
                break;
            case 1:
                printf("You are in a creepy bedroom. The bed is unmade and there is a ghostly figure in the corner.\n");
                break;
            case 2:
                printf("You are in a dark basement. The air is thick with the scent of decay.\n");
                break;
            case 3:
                printf("You are in a kitchen. The sink is filled with blood and there are knives scattered on the counter.\n");
                break;
        }

        //ask for input and update player position
        printf("Where would you like to go? (N/S/E/W)\n");
        scanf(" %c", &input);
        switch(input) {
            case 'n':
            case 'N':
                if(player_x > 0) {
                    player_x--;
                }
                break;
            case 's':
            case 'S':
                if(player_x < 9) {
                    player_x++;
                }
                break;
            case 'e':
            case 'E':
                if(player_y < 9) {
                    player_y++;
                }
                break;
            case 'w':
            case 'W':
                if(player_y > 0) {
                    player_y--;
                }
                break;
        }

        //check if player has won
        if(player_x == 9 && player_y == 9) {
            printf("Congratulations! You have escaped the haunted house!\n");
            input = 'q'; //exit loop
        }
    }

    return 0;
}
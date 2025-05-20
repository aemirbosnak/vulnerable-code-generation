//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to randomly generate movements for the robot
char* get_random_movement() {
    int move = rand() % 4;
    switch(move) {
        case 0:
            return "up";
        case 1:
            return "down";
        case 2:
            return "left";
        case 3:
            return "right";
    }
}

//Main function
int main() {
    srand(time(NULL)); //Seed the random number generator
    
    int x = 0, y = 0; //Initialize robot's position to (0,0)
    printf("Your robot is at position (%d,%d)\n\n", x, y);
    
    int num_players;
    printf("How many players? (2-4): ");
    scanf("%d", &num_players);
    while(num_players < 2 || num_players > 4) {
        printf("Invalid number of players, please enter a number between 2-4: ");
        scanf("%d", &num_players);
    }
    
    int turns = 1; //Initialize turn counter
    while(1) {
        printf("TURN %d\n\n", turns++);
        for(int i=1; i<=num_players; i++) {
            printf("PLAYER %d\n", i);
            printf("Enter your movement: ");
            char* movement = malloc(sizeof(char)*6);
            scanf("%s", movement);
            
            while(strcmp(movement, "up") != 0 && strcmp(movement, "down") != 0 && strcmp(movement, "left") != 0 && strcmp(movement, "right") != 0) {
                printf("Invalid movement, please enter 'up', 'down', 'left' or 'right': ");
                scanf("%s", movement);
            }
            
            if(strcmp(movement, "up") == 0) {
                y++;
            } else if(strcmp(movement, "down") == 0) {
                y--;
            } else if(strcmp(movement, "left") == 0) {
                x--;
            } else if(strcmp(movement, "right") == 0) {
                x++;
            }
            
            printf("Robot moved %s\n", movement);
            printf("Robot is now at position (%d,%d)\n\n", x, y);
            
            free(movement);
        }
        
        //Robot's turn
        char* robot_movement = get_random_movement();
        printf("ROBOT\n");
        printf("Robot moved %s\n", robot_movement);
        
        if(strcmp(robot_movement, "up") == 0) {
            y++;
        } else if(strcmp(robot_movement, "down") == 0) {
            y--;
        } else if(strcmp(robot_movement, "left") == 0) {
            x--;
        } else if(strcmp(robot_movement, "right") == 0) {
            x++;
        }
        
        printf("Robot is now at position (%d,%d)\n\n", x, y);
        
        //Check if robot has won
        if(x == 10 && y == 10) {
            printf("ROBOT WINS!\n");
            break;
        }
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
//include library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define robot structure
typedef struct{
    int x; //x-coordinate of robot
    int y; //y-coordinate of robot
    int health; //health points of robot
    int ammo; //ammo count of robot
} Robot;

//function declarations
void printRobot(Robot* r);
void moveRobot(Robot* r);
void shootRobot(Robot* r, Robot* opponent);

int main(){
    //initialize random seed
    srand(time(0));
    
    //create two robots
    Robot robot1 = {0, 0, 100, 10};
    Robot robot2 = {9, 9, 100, 10};
    
    //print initial robot positions
    printf("Initial positions:\n");
    printRobot(&robot1);
    printRobot(&robot2);
    printf("\n");
    
    //start the game
    int turn = rand() % 2; //randomly choose starting player
    printf("Game start!\n\n");
    while(robot1.health > 0 && robot2.health > 0){
        Robot* curPlayer; //current player
        Robot* otherPlayer; //other player
        
        //determine current and other player
        if(turn % 2 == 0){
            curPlayer = &robot1;
            otherPlayer = &robot2;
        }
        else{
            curPlayer = &robot2;
            otherPlayer = &robot1;
        }
        
        //player's turn
        printf("Player %d's turn:\n", turn % 2 + 1);
        printf("Current position: (%d, %d)\n", curPlayer->x, curPlayer->y);
        
        //ask player what to do
        printf("Enter 'm' to move or 's' to shoot:\n");
        char action;
        scanf(" %c", &action);
        
        //perform action
        if(action == 'm'){
            moveRobot(curPlayer);
        }
        else if(action == 's'){
            shootRobot(curPlayer, otherPlayer);
        }
        else{
            printf("Invalid action.\n");
            continue; //skip turn
        }
        
        //print updated robot positions and stats
        printf("Updated positions:\n");
        printRobot(&robot1);
        printRobot(&robot2);
        printf("\n");
        
        //next turn
        turn++;
    }
    
    //print game result
    printf("Game over!\n");
    if(robot1.health > 0){
        printf("Player 1 wins!\n");
    }
    else if(robot2.health > 0){
        printf("Player 2 wins!\n");
    }
    else{
        printf("It's a tie!\n");
    }
    
    return 0;
}

//function to print robot position and stats
void printRobot(Robot* r){
    printf("Robot position: (%d, %d)\n", r->x, r->y);
    printf("Health: %d\n", r->health);
    printf("Ammo count: %d\n", r->ammo);
}

//function to move robot
void moveRobot(Robot* r){
    //ask player where to move
    printf("Enter 'u' for up, 'd' for down, 'l' for left, 'r' for right:\n");
    char direction;
    scanf(" %c", &direction);
    
    //move robot
    switch(direction){
        case 'u':
            if(r->y > 0){ //check if within bounds
                r->y--;
            }
            break;
        case 'd':
            if(r->y < 9){ //check if within bounds
                r->y++;
            }
            break;
        case 'l':
            if(r->x > 0){ //check if within bounds
                r->x--;
            }
            break;
        case 'r':
            if(r->x < 9){ //check if within bounds
                r->x++;
            }
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

//function to shoot other robot
void shootRobot(Robot* r, Robot* opponent){
    if(r->ammo <= 0){ //check if have ammo
        printf("Out of ammo!\n");
        return;
    }
    
    //ask player where to shoot
    printf("Enter 'u' for up, 'd' for down, 'l' for left, 'r' for right:\n");
    char direction;
    scanf(" %c", &direction);
    
    //calculate distance to opponent
    int dx = opponent->x - r->x;
    int dy = opponent->y - r->y;
    int dist = abs(dx) + abs(dy);
    
    //check if opponent is within shooting range
    if(dist > 2){
        printf("Opponent out of range!\n");
        return;
    }
    
    //shoot opponent
    printf("Bang!\n");
    opponent->health -= 10;
    r->ammo--;
}
//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RC_VEHICLES 20

typedef struct {
    int x, y; //position on the grid
    int speed; //number of grid spaces moved per turn
    int direction; //0=up, 1=right, 2=down, 3=left
    int isActive;
} RC_vehicle;

RC_vehicle rcVehicles[MAX_RC_VEHICLES];
int numPlayers = 0;

void initializePositions(){
    //initialize the positions of the rc vehicles randomly
    srand(time(NULL));
    for(int i = 0; i < MAX_RC_VEHICLES; i++){
        rcVehicles[i].x = rand() % 10;
        rcVehicles[i].y = rand() % 10;
        rcVehicles[i].speed = rand() % 2 + 1;
        rcVehicles[i].direction = rand() % 4;
        rcVehicles[i].isActive = 1;
    }
}

void printGrid(){
    //print out a grid showing the positions of the rc vehicles
    char grid[10][10] = {{'.'}};
    for(int i = 0; i < MAX_RC_VEHICLES; i++){
        if(rcVehicles[i].isActive){
            switch(rcVehicles[i].direction){
                case 0: grid[rcVehicles[i].y - rcVehicles[i].speed][rcVehicles[i].x] = 'O'; break;
                case 1: grid[rcVehicles[i].y][rcVehicles[i].x + rcVehicles[i].speed] = 'O'; break;
                case 2: grid[rcVehicles[i].y + rcVehicles[i].speed][rcVehicles[i].x] = 'O'; break;
                case 3: grid[rcVehicles[i].y][rcVehicles[i].x - rcVehicles[i].speed] = 'O'; break;
                default: break;
            }
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void moveVehicle(int i){
    //move the i-th rc vehicle one space in its current direction
    if(rcVehicles[i].isActive){
        switch(rcVehicles[i].direction){
            case 0: rcVehicles[i].y -= rcVehicles[i].speed; break;
            case 1: rcVehicles[i].x += rcVehicles[i].speed; break;
            case 2: rcVehicles[i].y += rcVehicles[i].speed; break;
            case 3: rcVehicles[i].x -= rcVehicles[i].speed; break;
            default: break;
        }
    }
}

void playGame(){
    initializePositions();
    while(numPlayers > 1){ //continue playing until there is only one active player left
        printGrid();
        for(int i = 0; i < MAX_RC_VEHICLES; i++){
            if(rcVehicles[i].isActive){
                moveVehicle(i);
                int crashedInto = -1;
                for(int j = 0; j < MAX_RC_VEHICLES; j++){
                    if(i != j && rcVehicles[j].isActive && rcVehicles[i].x == rcVehicles[j].x && rcVehicles[i].y == rcVehicles[j].y){
                        crashedInto = j;
                        break;
                    }
                }
                if(crashedInto != -1){
                    numPlayers--;
                    rcVehicles[i].isActive = 0;
                    rcVehicles[crashedInto].isActive = 0;
                }
            }
        }
    }
    for(int i = 0; i < MAX_RC_VEHICLES; i++){
        if(rcVehicles[i].isActive){
            printf("Winner! RC Vehicle %d has won!\n", i);
            break;
        }
    }
}

int main(){
    printf("Welcome to RC Vehicle Simulation!\n");
    printf("How many players will there be? (1-4)\n");
    scanf("%d", &numPlayers);
    while(numPlayers < 1 || numPlayers > 4){
        printf("Invalid number of players. Please enter a number between 1 and 4.\n");
        scanf("%d", &numPlayers);
    }
    playGame();
    return 0;
}
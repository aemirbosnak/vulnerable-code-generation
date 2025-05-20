//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

void generateTraffic(int grid[10][10], int trafficCount);
void moveCars(int grid[10][10]);
void printGrid(int grid[10][10]);

int main(){
    int trafficCount;
    int grid[10][10] = {0};
    srand(time(NULL)); // seed for random function

    printf("Enter number of cars to generate (between 1 and 100): ");
    scanf("%d", &trafficCount);

    generateTraffic(grid, trafficCount);

    while(1){
        printGrid(grid);
        printf("Press any key to simulate next step...\n");
        getchar(); // wait for user input
        moveCars(grid);
    }

    return 0;
}

// Generates initial traffic on the grid
void generateTraffic(int grid[10][10], int trafficCount){
    int x, y;
    for(int i=0; i<trafficCount; i++){
        while(1){
            x = rand() % 10;
            y = rand() % 10;

            if(grid[x][y] == 0){ // check if there is no car in the cell
                grid[x][y] = rand() % 4; // assign random direction
                break;
            }
        }
    }
}

// Moves the cars forward on the grid
void moveCars(int grid[10][10]){
    int x, y, dir;

    for(int i=0; i<10; i++){ // traverse the grid
        for(int j=0; j<10; j++){
            if(grid[i][j] != 0){ // if there is a car in the cell
                x = i;
                y = j;
                dir = grid[i][j];

                switch(dir){ // move the car in the direction
                    case NORTH:
                        x--;
                        break;
                    case EAST:
                        y++;
                        break;
                    case SOUTH:
                        x++;
                        break;
                    case WEST:
                        y--;
                        break;
                }

                if(x >= 0 && x < 10 && y >= 0 && y < 10){ // check if new position is within the grid
                    if(grid[x][y] == 0){ // check if the cell is empty
                        grid[x][y] = dir; // move the car to the new position
                        grid[i][j] = 0; // make the previous position empty
                    }
                }
                else{ // if the car goes out of the grid, remove it
                    grid[i][j] = 0;
                }
            }
        }
    }
}

// Prints the grid with cars
void printGrid(int grid[10][10]){
    printf("\n");
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(grid[i][j] == 0){
                printf(" ");
            }
            else{
                printf("%d", grid[i][j]);
            }
        }
        printf("\n");
    }
}
//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //random seed
    srand(time(NULL)); 

    //initial values
    int xpos = rand() % 20;
    int ypos = rand() % 20;
    int dir = rand() % 4;

    //directions: 0=North, 1=East, 2=South, 3=West
    char* directions[4] = {"North", "East", "South", "West"};

    printf("Welcome to the Remote Control Vehicle Simulator\n");
    printf("----------------------------------------------\n\n");

    //create a loop to simulate RC vehicle movements
    for(int i=0; i<10; i++){
        //print current position and direction
        printf("Current position: (%d,%d)\n", xpos, ypos);
        printf("Current direction: %s\n\n", directions[dir]);

        //ask user for input
        printf("Enter direction (N,E,S,W) or Q to quit: ");
        char input;
        scanf(" %c", &input);

        //check for valid input
        if(input == 'N' || input == 'E' || input == 'S' || input == 'W'){
            //change direction based on input
            if(input == 'N'){
                dir = 0;
            }
            else if(input == 'E'){
                dir = 1;
            }
            else if(input == 'S'){
                dir = 2;
            }
            else if(input == 'W'){
                dir = 3;
            }

            //move in the current direction
            if(dir == 0){
                ypos += 1;
            }
            else if(dir == 1){
                xpos += 1;
            }
            else if(dir == 2){
                ypos -= 1;
            }
            else if(dir == 3){
                xpos -= 1;
            }
        }
        else if(input == 'Q'){
            //quit the program
            printf("\nThank you for using the Remote Control Vehicle Simulator!\n");
            exit(0);
        }
        else{
            //invalid input
            printf("Invalid input! Please enter N, E, S, W or Q.\n\n");
        }
    }

    //program reached end without quitting
    printf("\nSimulation complete!\n");

    return 0;
}
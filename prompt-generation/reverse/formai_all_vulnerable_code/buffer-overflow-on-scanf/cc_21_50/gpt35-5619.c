//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int main(){
    //variables declaration
    int choice;
    int xPosition = 0, yPosition = 0;
    bool engineStatus = false;
    char direction = 'N';


    //seed for random generator
    srand(time(0));

    printf("Welcome to the Remote Control Vehicle Simulation Program!\n");

    //menu and choice
    printf("Please choose your remote control vehicle:\n");
    printf("1. Car\n");
    printf("2. Boat\n");
    printf("3. Helicopter\n");
    printf("Choice: ");
    scanf("%d", &choice);
    printf("\n");

    //validation for choice
    while(choice < 1 || choice > 3){
        printf("Invalid choice! Please choose again: ");
        scanf("%d", &choice);
    }
    printf("\n");
    
    //printing chosen vehicle
    switch(choice){
        case 1: printf("You have chosen a Car!\n\n"); break;
        case 2: printf("You have chosen a Boat!\n\n"); break;
        case 3: printf("You have chosen a Helicopter!\n\n"); break;
    }

    //main loop
    while(true){

        //printing information
        printf("Engine Status: %s\n", engineStatus ? "On" : "Off");
        printf("Position: (%d, %d)\n", xPosition, yPosition);
        printf("Direction: %c\n\n", direction);

        //printing menu
        printf("What do you want to do?\n");
        printf("1. Turn Engine %s\n", engineStatus ? "Off" : "On");
        printf("2. Move Forward\n");
        printf("3. Turn Right\n");
        printf("4. Turn Left\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        //validation for choice
        while(choice < 1 || choice > 5){
            printf("Invalid choice! Please choose again: ");
            scanf("%d", &choice);
        }
        printf("\n");

        //performing action based on choice
        switch(choice){
            case 1: engineStatus = !engineStatus; break;
            case 2: 
                if(engineStatus){
                    int distance = rand() % 11 + 5; //random distance between 5 and 15
                    switch(direction){
                        case 'N': yPosition += distance; break;
                        case 'E': xPosition += distance; break;
                        case 'S': yPosition -= distance; break;
                        case 'W': xPosition -= distance; break;
                    }
                }else{
                    printf("The engine is off! You need to turn it on to move.\n\n");
                }
                break;
            case 3: 
                if(engineStatus){
                    switch(direction){
                        case 'N': direction = 'E'; break;
                        case 'E': direction = 'S'; break;
                        case 'S': direction = 'W'; break;
                        case 'W': direction = 'N'; break;
                    }
                }else{
                    printf("The engine is off! You need to turn it on to turn.\n\n");
                }
                break;
            case 4: 
                if(engineStatus){
                    switch(direction){
                        case 'N': direction = 'W'; break;
                        case 'E': direction = 'N'; break;
                        case 'S': direction = 'E'; break;
                        case 'W': direction = 'S'; break;
                    }
                }else{
                    printf("The engine is off! You need to turn it on to turn.\n\n");
                }
                break;
            case 5: printf("Thank you for playing the Remote Control Vehicle Simulation Program!\n"); exit(0); break;
        }
    }

    return 0;
}
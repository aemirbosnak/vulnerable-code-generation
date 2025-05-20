//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
//Program to control a drone using a remote control

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char instruction[50];
    printf("Welcome to the C Drone Remote Control program\n");
    printf("\n");

    //Instructions to use the drone remote control
    printf("To control the drone, please use the following commands:\n");
    printf("\n");
    printf("1. 'UP' - To make the drone go up\n");
    printf("2. 'DOWN' - To make the drone go down\n");
    printf("3. 'LEFT' - To make the drone go left\n");
    printf("4. 'RIGHT' - To make the drone go right\n");
    printf("5. 'LAND' - To land the drone\n");
    printf("6. 'EXIT' - To exit the program\n");
    printf("\n");

    //Code to read user instructions
    while(1){
        printf("Enter an instruction: ");
        scanf("%s", instruction);

        //Code to process user instructions
        if(strcmp(instruction, "UP")==0){
            printf("Drone moving UP\n");
        }
        else if(strcmp(instruction, "DOWN")==0){
            printf("Drone moving DOWN\n");
        }
        else if(strcmp(instruction, "LEFT")==0){
            printf("Drone moving LEFT\n");
        }
        else if(strcmp(instruction, "RIGHT")==0){
            printf("Drone moving RIGHT\n");
        }
        else if(strcmp(instruction, "LAND")==0){
            printf("Drone landing\n");
        }
        else if(strcmp(instruction, "EXIT")==0){
            printf("Exiting the program\n");
            break;
        }
        else{
            printf("Invalid instruction\n");
        }
        printf("\n");
    }
    return 0;
}
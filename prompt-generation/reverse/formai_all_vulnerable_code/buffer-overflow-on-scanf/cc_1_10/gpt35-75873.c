//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining the struct for the remote control
typedef struct{
    bool power;
    int speed;
    int altitude;
    int direction[2]; // x, y coordinates
} RemoteControl;

// Function to initialize the remote control
RemoteControl initialize(){
    RemoteControl rc;
    rc.power = false;
    rc.speed = 0;
    rc.altitude = 0;
    rc.direction[0] = 0;
    rc.direction[1] = 0;
    return rc;
}

// Function to turn on/off the remote control
void togglePower(RemoteControl *rc){
    rc->power = !rc->power;
    if(rc->power){
        printf("Remote Control Powered ON\n");
        printf("-----------------------------\n");
    }
    else{
        printf("\nBye-bye!\n");
    }
}

// Function to set the speed of the drone
void setSpeed(RemoteControl *rc, int speed){
    if(speed >= 0 && speed <= 100){
        rc->speed = speed;
        printf("Speed set to %d\n", speed);   
    }
    else{
        printf("Invalid speed input. Please enter a value between 0-100\n");
    }
}

// Function to increase/decrease altitude of the drone
void setAltitude(RemoteControl *rc, int alt){
    if(alt >= 0 && alt <= 100){
        rc->altitude = alt;
        printf("Altitude set to %d meters\n", alt);
    }
    else{
        printf("Invalid altitude input. Please enter a value between 0-100\n");
    }
}

// Function to adjust the direction of the drone
void setDirection(RemoteControl *rc, int x, int y){
    rc->direction[0] = x;
    rc->direction[1] = y;
    printf("Direction set to (%d,%d)\n", x, y);
}

int main(){
    RemoteControl rc = initialize();
    printf("Welcome to the Drone Remote Control Program!\n");
    printf("---------------------------------------------\n");
    bool run = true;
    while(run){
        int option;
        printf("\nChoose an option:\n");
        printf("1. Power ON/OFF\n");
        printf("2. Set speed\n");
        printf("3. Set altitude\n");
        printf("4. Set direction\n");
        printf("5. Exit\n\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                togglePower(&rc);
                break;
            case 2:
                if(rc.power){
                    printf("Enter speed value (0-100): ");
                    int speed;
                    scanf("%d", &speed);
                    setSpeed(&rc, speed);
                }
                else{
                    printf("Remote Control is currently OFF. Please turn it on first.\n");
                }
                break;
            case 3:
                if(rc.power){
                    printf("Enter altitude value (0-100): ");
                    int alt;
                    scanf("%d", &alt);
                    setAltitude(&rc, alt);
                }
                else{
                    printf("Remote Control is currently OFF. Please turn it on first.\n");
                }
                break;
            case 4:
                if(rc.power){
                    printf("Enter x-coordinate of direction: ");
                    int x;
                    scanf("%d", &x);
                    printf("Enter y-coordinate of direction: ");
                    int y;
                    scanf("%d", &y);
                    setDirection(&rc, x, y);
                }
                else{
                    printf("Remote Control is currently OFF. Please turn it on first.\n");
                }
                break;
            case 5:
                run = false;
                break;
            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    }
    return 0;
}
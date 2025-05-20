//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
//This is a program for controlling a drone using a remote control

#include <stdio.h>

//initialize variables for drone movement
int altitude = 0;
int yaw = 0;
int pitch = 0;
int roll = 0;

//function for increasing altitude
void increase_altitude(){
    int new_alt = altitude + 1;
    printf("Increasing altitude from %d to %d\n", altitude, new_alt);
    altitude = new_alt;
}

//function for decreasing altitude
void decrease_altitude(){
    int new_alt = altitude - 1;
    printf("Decreasing altitude from %d to %d\n", altitude, new_alt);
    altitude = new_alt;
}

//function for turning the drone left
void turn_left(){
    int new_yaw = yaw - 5;
    printf("Turning left from %d to %d\n", yaw, new_yaw);
    yaw = new_yaw;
}

//function for turning the drone right
void turn_right(){
    int new_yaw = yaw + 5;
    printf("Turning right from %d to %d\n", yaw, new_yaw);
    yaw = new_yaw;
}

//function for tilting the drone forward
void tilt_forward(){
    int new_pitch = pitch + 5;
    printf("Tilting forward from %d to %d\n", pitch, new_pitch);
    pitch = new_pitch;
}

//function for tilting the drone backward
void tilt_backward(){
    int new_pitch = pitch - 5;
    printf("Tilting backward from %d to %d\n", pitch, new_pitch);
    pitch = new_pitch;
}

//function for tilting the drone to the left
void tilt_left(){
    int new_roll = roll - 5;
    printf("Tilting left from %d to %d\n", roll, new_roll);
    roll = new_roll;
}

//function for tilting the drone to the right
void tilt_right(){
    int new_roll = roll + 5;
    printf("Tilting right from %d to %d\n", roll, new_roll);
    roll = new_roll;
}

int main(){
    //initialize variable for user input
    char choice;
    
    //print instructions for user
    printf("Drone remote control program\n");
    printf("Press i to increase altitude\n");
    printf("Press d to decrease altitude\n");
    printf("Press l to turn left\n");
    printf("Press r to turn right\n");
    printf("Press f to tilt forward\n");
    printf("Press b to tilt backward\n");
    printf("Press t to tilt left\n");
    printf("Press q to tilt right\n");
    printf("Press x to exit\n");
    
    //loop to accept user input
    while(1){
        printf("Current drone altitude: %d\n", altitude);
        printf("Current drone yaw: %d\n", yaw);
        printf("Current drone pitch: %d\n", pitch);
        printf("Current drone roll: %d\n", roll);
        printf("Enter command: ");
        scanf(" %c", &choice);
        
        //switch statement to execute corresponding function based on user input
        switch(choice){
            case 'i':
                increase_altitude();
                break;
            case 'd':
                decrease_altitude();
                break;
            case 'l':
                turn_left();
                break;
            case 'r':
                turn_right();
                break;
            case 'f':
                tilt_forward();
                break;
            case 'b':
                tilt_backward();
                break;
            case 't':
                tilt_left();
                break;
            case 'q':
                tilt_right();
                break;
            case 'x':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
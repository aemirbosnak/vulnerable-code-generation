//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: all-encompassing
#include <stdio.h>

// Define the maximum and minimum altitude of the drone
#define MIN_ALTITUDE 0
#define MAX_ALTITUDE 1000

// Define the maximum and minimum left/right rotation angle of the drone
#define MIN_LEFT_RIGHT_ANGLE 0
#define MAX_LEFT_RIGHT_ANGLE 90

// Define the maximum and minimum forward/backward tilt angle of the drone
#define MIN_FORWARD_BACKWARD_ANGLE -90
#define MAX_FORWARD_BACKWARD_ANGLE 90

// Define a function to ensure the drone is within altitude limits
int check_altitude(int desired_altitude){
    if (desired_altitude < MIN_ALTITUDE){
        printf("Error: altitude too low. Adjusting to minimum altitude of %d\n", MIN_ALTITUDE);
        return MIN_ALTITUDE;
    }
    else if (desired_altitude > MAX_ALTITUDE){
        printf("Error: altitude too high. Adjusting to maximum altitude of %d\n", MAX_ALTITUDE);
        return MAX_ALTITUDE;
    }
    else{
        return desired_altitude;
    }
}

// Define a function to ensure the drone is within left/right rotation angle limits
int check_left_right_angle(int desired_angle){
    if (desired_angle < MIN_LEFT_RIGHT_ANGLE){
        printf("Error: left/right angle too low. Adjusting to minimum angle of %d\n", MIN_LEFT_RIGHT_ANGLE);
        return MIN_LEFT_RIGHT_ANGLE;
    }
    else if (desired_angle > MAX_LEFT_RIGHT_ANGLE){
        printf("Error: left/right angle too high. Adjusting to maximum angle of %d\n", MAX_LEFT_RIGHT_ANGLE);
        return MAX_LEFT_RIGHT_ANGLE;
    }
    else{
        return desired_angle;
    }
}

// Define a function to ensure the drone is within forward/backward tilt angle limits
int check_forward_backward_angle(int desired_angle){
    if (desired_angle < MIN_FORWARD_BACKWARD_ANGLE){
        printf("Error: forward/backward angle too low. Adjusting to minimum angle of %d\n", MIN_FORWARD_BACKWARD_ANGLE);
        return MIN_FORWARD_BACKWARD_ANGLE;
    }
    else if (desired_angle > MAX_FORWARD_BACKWARD_ANGLE){
        printf("Error: forward/backward angle too high. Adjusting to maximum angle of %d\n", MAX_FORWARD_BACKWARD_ANGLE);
        return MAX_FORWARD_BACKWARD_ANGLE;
    }
    else{
        return desired_angle;
    }
}

// Define the main function 
int main() {
    int altitude = 0;
    int left_right_angle = 0;
    int forward_backward_angle = 0;
    
    // Print the initial status of the drone
    printf("Drone Status:\nAltitude: %d\nLeft/Right Angle: %d\nForward/Backward Tilt Angle: %d\n\n", altitude, left_right_angle, forward_backward_angle);
    
    // Continuously prompt the user for input and update the drone status accordingly
    while(1){
        char input[10];
        printf("Enter command (altitude/angle/quit): ");
        scanf("%s", input);
        
        if (strcmp(input, "altitude") == 0){
            int desired_altitude;
            printf("Enter desired altitude (between %d and %d): ", MIN_ALTITUDE, MAX_ALTITUDE);
            scanf("%d", &desired_altitude);
            altitude = check_altitude(desired_altitude);
        }
        else if (strcmp(input, "angle") == 0){
            int desired_left_right_angle;
            printf("Enter desired left/right angle (between %d and %d): ", MIN_LEFT_RIGHT_ANGLE, MAX_LEFT_RIGHT_ANGLE);
            scanf("%d", &desired_left_right_angle);
            left_right_angle = check_left_right_angle(desired_left_right_angle);
            
            int desired_forward_backward_angle;
            printf("Enter desired forward/backward angle (between %d and %d): ", MIN_FORWARD_BACKWARD_ANGLE, MAX_FORWARD_BACKWARD_ANGLE);
            scanf("%d", &desired_forward_backward_angle);
            forward_backward_angle = check_forward_backward_angle(desired_forward_backward_angle);
        }
        else if (strcmp(input, "quit") == 0){
            printf("Exiting program\n");
            break;
        }
        else{
            printf("Invalid command. Please try again.\n");
        }
        
        // Print the updated status of the drone
        printf("Drone Status:\nAltitude: %d\nLeft/Right Angle: %d\nForward/Backward Tilt Angle: %d\n\n", altitude, left_right_angle, forward_backward_angle);
    }
    
    return 0;
}
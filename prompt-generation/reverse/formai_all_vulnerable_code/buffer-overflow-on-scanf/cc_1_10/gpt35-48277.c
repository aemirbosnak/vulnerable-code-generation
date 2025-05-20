//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    int drone_id, x_axis = 0, y_axis = 0, z_axis = 0; 
    char direction[10];
    
    printf("Welcome to the C Drone Remote Control Program!\n\n");
    
    // Taking user input for drone ID
    printf("Please enter your Drone ID (1 - 10): ");
    scanf("%d", &drone_id);
    
    // Displaying drone status
    printf("You are now controlling Drone %d\n", drone_id);
    printf("\n");
    
    // Main control loop
    while(1) {
        
        // Prompting user for direction input
        printf("Please enter the direction to move (up, down, left, right, forward, backward): ");
        scanf("%s", direction);
        
        // Updating axis values
        if(strcmp(direction, "up") == 0) {
            y_axis++;
        }
        else if(strcmp(direction, "down") == 0) {
            y_axis--;
        }
        else if(strcmp(direction, "left") == 0) {
            x_axis--;
        }
        else if(strcmp(direction, "right") == 0) {
            x_axis++;
        }
        else if(strcmp(direction, "forward") == 0) {
            z_axis++;
        }
        else if(strcmp(direction, "backward") == 0) {
            z_axis--;
        }
        else {
            printf("Invalid direction input!\n");
        }
        
        // Displaying updated axis values
        printf("Current coordinates: (%d, %d, %d)\n", x_axis, y_axis, z_axis);
        printf("\n");
        
        // Prompting user to continue or exit
        printf("Press c to continue controlling Drone %d or any other key to exit: ", drone_id);
        char choice;
        scanf(" %c", &choice);
        if(choice != 'c') {
            printf("\nExiting Drone Remote Control Program...\n");
            break;
        }
    }

    return 0;
}
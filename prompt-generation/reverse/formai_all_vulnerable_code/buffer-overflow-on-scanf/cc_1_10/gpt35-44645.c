//FormAI DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to turn on/off the lights
void lightOnOff(int roomNum, int lightNum, int status) {
    // Code to control the lights
    if(status == 1) {
        printf("Room %d, Light %d turned ON\n", roomNum, lightNum);
    } else {
        printf("Room %d, Light %d turned OFF\n", roomNum, lightNum);
    }
}

int main() {
    // Variables to store the room and light number, and the status of the light (1 for on, 0 for off)
    int room, light, status;

    // Display the available rooms and lights
    printf("Available Rooms and Lights:\n");
    printf("Room 1: Light 1, Light 2\n");
    printf("Room 2: Light 1\n");

    // Loop to keep the program running until the user exits
    while(1) {
        // Get the user's input
        printf("\nEnter 'exit' to quit\n");
        printf("Enter room number: ");
        scanf("%d", &room);

        // If the user enters "exit", break out of the loop and end the program
        if(room == -1) {
            break;
        }

        // Check if the room number is valid
        if(room < 1 || room > 2) {
            printf("Invalid room number. Select a valid room.\n");
            continue;
        }

        printf("Enter light number: ");
        scanf("%d", &light);

        // Check if the light number is valid
        if((room == 1 && light < 1 || light > 2) || (room == 2 && light != 1)) {
            printf("Invalid light number for the selected room. Select a valid light.\n");
            continue;
        }

        printf("Enter status (1 for ON, 0 for OFF): ");
        scanf("%d", &status);

        // Check if the status is valid
        if(status != 0 && status != 1) {
            printf("Invalid status. Select either 1 or 0.\n");
            continue;
        }

        // Call the function to turn on/off the light
        lightOnOff(room, light, status);
    }

    return 0;
}
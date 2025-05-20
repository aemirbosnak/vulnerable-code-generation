//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the drone remote control structure
struct DroneRemoteControl {
   int thrust;
   int roll;
   int pitch;
   int yaw;
};

// Define the function prototypes
void setDroneRemoteControl(struct DroneRemoteControl*, int, int, int, int);
void printDroneRemoteControl(struct DroneRemoteControl*);
void processCommandInput(int*, int*, int*, int*);
bool validateCommandInput(int, int, int, int);
void executeCommand(struct DroneRemoteControl*, int, int, int, int);

int main() {
   // Declare the drone remote control structure variable
   struct DroneRemoteControl droneRemoteControl;
   
   // Initialize the drone remote control structure with default values
   setDroneRemoteControl(&droneRemoteControl, 0, 0, 0, 0);
   
   // Define the variables used to process user input
   int thrust = 0;
   int roll = 0;
   int pitch = 0;
   int yaw = 0;
   
   // Continuously prompt user for input until user exits program
   while (true) {
      // Prompt user for input
      printf("\nEnter values for thrust, roll, pitch and yaw: ");
      
      // Process user input
      processCommandInput(&thrust, &roll, &pitch, &yaw);
      
      // Validate user input
      if (validateCommandInput(thrust, roll, pitch, yaw)) {
         // Execute the command
         executeCommand(&droneRemoteControl, thrust, roll, pitch, yaw);
         
         // Print the state of the drone remote control
         printDroneRemoteControl(&droneRemoteControl);
      } else {
         // Notify user that input is invalid
         printf("\nInvalid input, please try again.\n");
      }
   }

   return 0;
}

// Set the drone remote control values
void setDroneRemoteControl(struct DroneRemoteControl *droneRemoteControl, 
                           int thrust, int roll, int pitch, int yaw) {
   droneRemoteControl->thrust = thrust;
   droneRemoteControl->roll = roll;
   droneRemoteControl->pitch = pitch;
   droneRemoteControl->yaw = yaw;
}

// Print the state of the drone remote control
void printDroneRemoteControl(struct DroneRemoteControl *droneRemoteControl) {
   printf("\nCurrent Drone Remote Control State:\n\n");
   printf("Thrust: %d\n", droneRemoteControl->thrust);
   printf("Roll: %d\n", droneRemoteControl->roll);
   printf("Pitch: %d\n", droneRemoteControl->pitch);
   printf("Yaw: %d\n", droneRemoteControl->yaw);
}

// Process the raw command input from the user
void processCommandInput(int *thrust, int *roll, int *pitch, int *yaw) {
   scanf("%d %d %d %d", thrust, roll, pitch, yaw);
}

// Validate the command input from the user
bool validateCommandInput(int thrust, int roll, int pitch, int yaw) {
   if (thrust >= 0 && thrust <= 100 && roll >= -90 && roll <= 90 && pitch >= -90 
       && pitch <= 90 && yaw >= -180 && yaw <= 180) {
      return true;
   } else {
      return false;
   }
}

// Execute the drone remote control command
void executeCommand(struct DroneRemoteControl *droneRemoteControl, 
                    int thrust, int roll, int pitch, int yaw) {
   droneRemoteControl->thrust = thrust;
   droneRemoteControl->roll = roll;
   droneRemoteControl->pitch = pitch;
   droneRemoteControl->yaw = yaw;
}
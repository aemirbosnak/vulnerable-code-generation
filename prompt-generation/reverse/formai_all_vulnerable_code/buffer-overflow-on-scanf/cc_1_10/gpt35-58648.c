//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_SPEED 0
#define MAX_SPEED 100

#define MIN_ALTITUDE 1
#define MAX_ALTITUDE 3000

#define MIN_DIRECTION 0
#define MAX_DIRECTION 359

#define MIN_CHANNEL 1
#define MAX_CHANNEL 10

#define MIN_BATTERY_LEVEL 0
#define MAX_BATTERY_LEVEL 100

#define MIN_SIGNAL_STRENGTH 0
#define MAX_SIGNAL_STRENGTH 100

// drone command struct
typedef struct {
    int speed;
    int altitude;
    int direction;
} DroneCommand;

// drone status struct
typedef struct {
    int channel;
    int batteryLevel;
    int signalStrength;
    bool isConnected;
} DroneStatus;

// function to validate and set drone speed
void setDroneSpeed(DroneCommand* command, int speed) {
    if (speed < MIN_SPEED || speed > MAX_SPEED) {
        printf("Invalid drone speed. Speed should be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
    } else {
        command->speed = speed;
        printf("Drone speed set to %d.\n", speed);
    }
}

// function to validate and set drone altitude
void setDroneAltitude(DroneCommand* command, int altitude) {
    if (altitude < MIN_ALTITUDE || altitude > MAX_ALTITUDE) {
        printf("Invalid drone altitude. Altitude should be between %d and %d.\n", MIN_ALTITUDE, MAX_ALTITUDE);
    } else {
        command->altitude = altitude;
        printf("Drone altitude set to %d.\n", altitude);
    }
}

// function to validate and set drone direction
void setDroneDirection(DroneCommand* command, int direction) {
    if (direction < MIN_DIRECTION || direction > MAX_DIRECTION) {
        printf("Invalid drone direction. Direction should be between %d and %d.\n", MIN_DIRECTION, MAX_DIRECTION);
    } else {
        command->direction = direction;
        printf("Drone direction set to %d degrees.\n", direction);
    }
}

// function to validate and set drone channel
void setDroneChannel(DroneStatus* status, int channel) {
    if (channel < MIN_CHANNEL || channel > MAX_CHANNEL) {
        printf("Invalid drone channel. Channel should be between %d and %d.\n", MIN_CHANNEL, MAX_CHANNEL);
    } else {
        status->channel = channel;
        printf("Drone channel set to %d.\n", channel);
    }
}

// function to validate and set drone battery level
void setDroneBatteryLevel(DroneStatus* status, int batteryLevel) {
    if (batteryLevel < MIN_BATTERY_LEVEL || batteryLevel > MAX_BATTERY_LEVEL) {
        printf("Invalid drone battery level. Battery level should be between %d and %d.\n", MIN_BATTERY_LEVEL, MAX_BATTERY_LEVEL);
    } else {
        status->batteryLevel = batteryLevel;
        printf("Drone battery level set to %d%%.\n", batteryLevel);
    }
}

// function to validate and set drone signal strength
void setDroneSignalStrength(DroneStatus* status, int signalStrength) {
    if (signalStrength < MIN_SIGNAL_STRENGTH || signalStrength > MAX_SIGNAL_STRENGTH) {
        printf("Invalid drone signal strength. Signal strength should be between %d and %d.\n", MIN_SIGNAL_STRENGTH, MAX_SIGNAL_STRENGTH);
    } else {
        status->signalStrength = signalStrength;
        printf("Drone signal strength set to %d%%.\n", signalStrength);
    }
}

int main() {
    DroneCommand command = {0, 0, 0}; // initialize drone command with default values
    DroneStatus status = {1, 100, 90, true}; // initialize drone status with default values

    printf("Welcome to the drone remote control program!\n");
    
    // loop to get user input and execute drone commands
    while (status.isConnected) {
        printf("\nDrone Command Menu\n");
        printf("1. Set Drone Speed\n");
        printf("2. Set Drone Altitude\n");
        printf("3. Set Drone Direction\n");
        printf("4. Disconnect Drone\n");
        printf("\nDrone Status\n");
        printf("Channel: %d\n", status.channel);
        printf("Battery Level: %d%%\n", status.batteryLevel);
        printf("Signal Strength: %d%%\n", status.signalStrength);
        
        // get user input
        int choice;
        printf("\nEnter Command: ");
        scanf("%d", &choice);
        
        // execute user command
        switch (choice) {
            case 1: {
                int speed;
                printf("Enter drone speed: ");
                scanf("%d", &speed);
                setDroneSpeed(&command, speed);
                break;
            }
            case 2: {
                int altitude;
                printf("Enter drone altitude: ");
                scanf("%d", &altitude);
                setDroneAltitude(&command, altitude);
                break;
            }
            case 3: {
                int direction;
                printf("Enter drone direction: ");
                scanf("%d", &direction);
                setDroneDirection(&command, direction);
                break;
            }
            case 4: {
                status.isConnected = false;
                break;
            }
            default: {
                printf("Invalid command. Please enter a valid command.\n");
                break;
            }
        }
    }
    
    printf("\nDrone disconnected. Program exiting...\n");
    return 0;
}
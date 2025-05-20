//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: active
#include <stdio.h>
#include <math.h>

#define MAX_SPEED 100 // Maximum speed of drone
#define MIN_SPEED 0 // Minimum speed of drone
#define MAX_ALTITUDE 500 // Maximum altitude of drone
#define MIN_ALTITUDE 0 // Minimum altitude of drone
#define MAX_BATTERY_LEVEL 100 // Maximum battery level
#define MIN_BATTERY_LEVEL 0 // Minimum battery level
#define BATTERY_USAGE_RATE 2 // Battery usage rate during flight
#define MAX_DISTANCE 5000 // Maximum distance that drone can cover
#define MIN_DISTANCE 0 // Minimum distance that drone can cover

void displayMenu();
int getCommand();
int validateCommand(int command);
void takeOff(int *currentAltitude, int *batteryLevel, int *currentSpeed);
void land(int *currentAltitude, int *batteryLevel, int *currentSpeed);
void increaseSpeed(int *currentSpeed);
void decreaseSpeed(int *currentSpeed);
void goUp(int *currentAltitude, int *batteryLevel);
void goDown(int *currentAltitude, int *batteryLevel);
void flyForward(int *currentDistance, int *batteryLevel);
void flyBackward(int *currentDistance, int *batteryLevel);
void showStatus(int currentAltitude, int batteryLevel, int currentSpeed, int currentDistance);

int main()
{
    int currentAltitude = 0; // Current altitude of drone
    int batteryLevel = 100; // Current battery level of drone
    int currentSpeed = 0; // Current speed of drone
    int currentDistance = 0; // Current distance covered by drone

    int command;
    do
    {
        displayMenu(); // Display the menu for user selection
        command = getCommand(); // Get the user selection and validate

        // Execute the selected command
        switch (command)
        {
        case 1:
            takeOff(&currentAltitude, &batteryLevel, &currentSpeed);
            break;
        case 2:
            land(&currentAltitude, &batteryLevel, &currentSpeed);
            break;
        case 3:
            increaseSpeed(&currentSpeed);
            break;
        case 4:
            decreaseSpeed(&currentSpeed);
            break;
        case 5:
            goUp(&currentAltitude, &batteryLevel);
            break;
        case 6:
            goDown(&currentAltitude, &batteryLevel);
            break;
        case 7:
            flyForward(&currentDistance, &batteryLevel);
            break;
        case 8:
            flyBackward(&currentDistance, &batteryLevel);
            break;
        case 9:
            showStatus(currentAltitude, batteryLevel, currentSpeed, currentDistance);
            break;
        }

    } while (command != 0); // Exit program if '0' command is entered by the user

    return 0; // Exit the program
}

/**
 * Display the main menu
 */
void displayMenu()
{
    printf("Welcome to Drone Remote Control\n\n");
    printf("1. Take off\n");
    printf("2. Land\n");
    printf("3. Increase speed\n");
    printf("4. Decrease speed\n");
    printf("5. Go up\n");
    printf("6. Go down\n");
    printf("7. Fly forward\n");
    printf("8. Fly backward\n");
    printf("9. Show status\n");
    printf("0. Exit\n\n");
    printf("Enter command: ");
}

/**
 * Get the user input and validate
 * 
 * @return int The validated command
 */
int getCommand()
{
    int command;
    do
    {
        scanf("%d", &command);

        if (!validateCommand(command))
        {
            printf("\nCommand not recognized. Please enter a valid command: ");
        }

    } while (!validateCommand(command));

    return command;
}

/**
 * Validate the user input
 * 
 * @param int command The user input
 * 
 * @return int The result of validation
 */
int validateCommand(int command)
{
    if (command < 0 || command > 9)
    {
        return 0;
    }

    return 1;
}

/**
 * Take off the drone
 * 
 * @param int *currentAltitude Pointer to current altitude of drone
 * @param int *batteryLevel Pointer to current battery level of drone
 * @param int *currentSpeed Pointer to current speed of drone
 */
void takeOff(int *currentAltitude, int *batteryLevel, int *currentSpeed)
{
    if (*batteryLevel < BATTERY_USAGE_RATE)
    {
        printf("\nNot enough battery power to take off. Charge the drone first.\n");
        return;
    }

    if (*currentAltitude > 0)
    {
        printf("\nDrone is already in the air.\n");
        return;
    }

    if (*currentSpeed < MIN_SPEED || *currentSpeed > MAX_SPEED)
    {
        printf("\nSpeed out of range. Please set a valid speed first.\n");
        return;
    }

    printf("\nTaking off...\n");
    *currentAltitude = 1;
    *batteryLevel -= BATTERY_USAGE_RATE;

    printf("Current altitude: %d\n", *currentAltitude);
    printf("Battery level: %d\n", *batteryLevel);
}

/**
 * Land the drone
 * 
 * @param int *currentAltitude Pointer to current altitude of drone
 * @param int *batteryLevel Pointer to current battery level of drone
 * @param int *currentSpeed Pointer to current speed of drone
 */
void land(int *currentAltitude, int *batteryLevel, int *currentSpeed)
{
    if (*currentAltitude <= 0)
    {
        printf("\nDrone is already on the ground.\n");
        return;
    }

    printf("\nLanding...\n");
    *currentAltitude = 0;
    *batteryLevel -= BATTERY_USAGE_RATE;

    printf("Current altitude: %d\n", *currentAltitude);
    printf("Battery level: %d\n", *batteryLevel);
}

/**
 * Increase the speed of drone
 * 
 * @param int *currentSpeed Pointer to current speed of drone
 */
void increaseSpeed(int *currentSpeed)
{
    if (*currentSpeed >= MAX_SPEED)
    {
        printf("\nMaximum speed reached.\n");
        return;
    }

    printf("\nIncreasing speed...\n");
    *currentSpeed += 10;

    printf("Current speed: %d\n", *currentSpeed);
}

/**
 * Decrease the speed of drone
 * 
 * @param int *currentSpeed Pointer to current speed of drone
 */
void decreaseSpeed(int *currentSpeed)
{
    if (*currentSpeed <= MIN_SPEED)
    {
        printf("\nMinimum speed reached.\n");
        return;
    }

    printf("\nDecreasing speed...\n");
    *currentSpeed -= 10;

    printf("Current speed: %d\n", *currentSpeed);
}

/**
 * Increase the altitude of drone
 * 
 * @param int *currentAltitude Pointer to current altitude of drone
 * @param int *batteryLevel Pointer to current battery level of drone
 */
void goUp(int *currentAltitude, int *batteryLevel)
{
    if (*currentAltitude >= MAX_ALTITUDE)
    {
        printf("\nMaximum altitude reached.\n");
        return;
    }

    if (*batteryLevel < BATTERY_USAGE_RATE)
    {
        printf("\nNot enough battery power to go up. Charge the drone first.\n");
        return;
    }

    printf("\nGoing up...\n");
    *currentAltitude += 10;
    *batteryLevel -= BATTERY_USAGE_RATE;

    printf("Current altitude: %d\n", *currentAltitude);
    printf("Battery level: %d\n", *batteryLevel);
}

/**
 * Decrease the altitude of drone
 * 
 * @param int *currentAltitude Pointer to current altitude of drone
 * @param int *batteryLevel Pointer to current battery level of drone
 */
void goDown(int *currentAltitude, int *batteryLevel)
{
    if (*currentAltitude <= MIN_ALTITUDE)
    {
        printf("\nMinimum altitude reached.\n");
        return;
    }

    if (*batteryLevel < BATTERY_USAGE_RATE)
    {
        printf("\nNot enough battery power to go down. Charge the drone first.\n");
        return;
    }

    printf("\nGoing down...\n");
    *currentAltitude -= 10;
    *batteryLevel -= BATTERY_USAGE_RATE;

    printf("Current altitude: %d\n", *currentAltitude);
    printf("Battery level: %d\n", *batteryLevel);
}

/**
 * Move the drone forward
 * 
 * @param int *currentDistance Pointer to current distance covered by drone
 * @param int *batteryLevel Pointer to current battery level of drone
 */
void flyForward(int *currentDistance, int *batteryLevel)
{
    if (*batteryLevel < BATTERY_USAGE_RATE)
    {
        printf("\nNot enough battery power to fly forward. Charge the drone first.\n");
        return;
    }

    if (*currentDistance >= MAX_DISTANCE)
    {
        printf("\nMaximum distance reached.\n");
        return;
    }

    printf("\nFlying forward...\n");
    *currentDistance += 10;
    *batteryLevel -= BATTERY_USAGE_RATE;

    printf("Current distance: %d\n", *currentDistance);
    printf("Battery level: %d\n", *batteryLevel);
}

/**
 * Move the drone backward
 * 
 * @param int *currentDistance Pointer to current distance covered by drone
 * @param int *batteryLevel Pointer to current battery level of drone
 */
void flyBackward(int *currentDistance, int *batteryLevel)
{
    if (*batteryLevel < BATTERY_USAGE_RATE)
    {
        printf("\nNot enough battery power to fly backward. Charge the drone first.\n");
        return;
    }

    if (*currentDistance <= MIN_DISTANCE)
    {
        printf("\nMinimum distance reached.\n");
        return;
    }

    printf("\nFlying backward...\n");
    *currentDistance -= 10;
    *batteryLevel -= BATTERY_USAGE_RATE;

    printf("Current distance: %d\n", *currentDistance);
    printf("Battery level: %d\n", *batteryLevel);
}

/**
 * Display the status of drone
 * 
 * @param int currentAltitude The current altitude of drone
 * @param int batteryLevel The current battery level of drone
 * @param int currentSpeed The current speed of drone
 * @param int currentDistance The current distance covered by drone
 */
void showStatus(int currentAltitude, int batteryLevel, int currentSpeed, int currentDistance)
{
    printf("\nCurrent status of drone:\n");
    printf("Altitude: %d\n", currentAltitude);
    printf("Battery level: %d\n", batteryLevel);
    printf("Speed: %d\n", currentSpeed);
    printf("Distance covered: %d\n", currentDistance);
}
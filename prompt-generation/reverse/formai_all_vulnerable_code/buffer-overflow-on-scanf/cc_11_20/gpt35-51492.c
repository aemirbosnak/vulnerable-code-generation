//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initializing variables
    int batteryCharge = 100;
    int signalStrength = 100;
    char direction[20];

    printf("Welcome to your Drone Remote Control Program!\n");
    printf("Please enter the direction you want to move (up, down, left, right):\n");
    scanf("%s", direction);

    // Loop to move the drone in the specified direction until battery runs out or signal strength weakens
    while(batteryCharge > 0 && signalStrength > 0) {

        // Checking the direction entered by the user
        if(strcmp(direction, "up") == 0 || strcmp(direction, "Up") == 0) {
            printf("Moving drone up...\n");
            batteryCharge -= 5;
            signalStrength -= 3;
        }
        else if(strcmp(direction, "down") == 0 || strcmp(direction, "Down") == 0) {
            printf("Moving drone down...\n");
            batteryCharge -= 5;
            signalStrength -= 3;
        }
        else if(strcmp(direction, "left") == 0 || strcmp(direction, "Left") == 0) {
            printf("Moving drone left...\n");
            batteryCharge -= 5;
            signalStrength -= 3;
        }
        else if(strcmp(direction, "right") == 0 || strcmp(direction, "Right") == 0) {
            printf("Moving drone right...\n");
            batteryCharge -= 5;
            signalStrength -= 3;
        }
        else {
            printf("Invalid direction entered, please try again (up, down, left, right):\n");
            scanf("%s", direction);
        }

        // Checking if battery or signal strength has weakened
        if(batteryCharge <= 20) {
            printf("Battery is running low, returning drone to base.\n");
            break;
        }
        else if(signalStrength <= 20) {
            printf("Signal strength is weak, drone connection lost.\n");
            break;
        }

        // Prompting user if they want to continue moving in the same direction or change direction
        printf("Current battery charge: %d%%\n", batteryCharge);
        printf("Current signal strength: %d%%\n", signalStrength);
        printf("Do you want to continue moving in the current direction or change direction (C for continue, D for change direction):\n");
        char choice;
        scanf(" %c", &choice);

        // Checking user's choice
        if(choice == 'C' || choice == 'c') {
            continue;
        }
        else if(choice == 'D' || choice == 'd') {
            printf("Please enter the direction you want to move (up, down, left, right):\n");
            scanf("%s", direction);
        }
        else {
            printf("Invalid choice entered, returning drone to base.\n");
            break;
        }
    }

    // Ending program and returning to main menu
    printf("Drone returning to base with battery charge of %d%% and signal strength of %d%%.\n", batteryCharge, signalStrength);
    printf("Thank you for using your Drone Remote Control Program!\n");

    return 0;
}
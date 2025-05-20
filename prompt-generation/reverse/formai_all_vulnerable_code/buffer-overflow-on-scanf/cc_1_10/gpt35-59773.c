//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
 
// function to turn on/off lights based on user input
void controlLights(int livingRoom, int kitchen, int bedroom) {
    printf("Enter 1 to turn on or 0 to turn off lights\n");
    printf("Living Room: ");
    scanf("%d", &livingRoom);
    if(livingRoom == 1) {
        printf("Living room lights on.\n");
    } else {
        printf("Living room lights off.\n");
    }
    printf("Kitchen: ");
    scanf("%d", &kitchen);
    if(kitchen == 1) {
        printf("Kitchen lights on.\n");
    } else {
        printf("Kitchen lights off.\n");
    }
    printf("Bedroom: ");
    scanf("%d", &bedroom);
    if(bedroom == 1) {
        printf("Bedroom lights on.\n");
    } else {
        printf("Bedroom lights off.\n");
    }
}
 
// function to adjust the temperature based on user input
void controlTemperature(int temperature) {
    printf("Enter the desired temperature: ");
    scanf("%d", &temperature);
    printf("Setting temperature to %d degrees.\n", temperature);
}
 
// main function
int main() {
    int livingRoomLights = 0;
    int kitchenLights = 0;
    int bedroomLights = 0;
    int temperature = 0;

    printf("--- Welcome to the Smart Home Automation System ---\n");

    while(1) {
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Control lights\n");
        printf("2. Control temperature\n");
        printf("3. Exit the program\n");

        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
 
        if(choice == 1) {
            controlLights(livingRoomLights, kitchenLights, bedroomLights);
        } else if(choice == 2) {
            controlTemperature(temperature);
        } else if(choice == 3) {
            printf("Exiting the program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
 
    return 0;
}
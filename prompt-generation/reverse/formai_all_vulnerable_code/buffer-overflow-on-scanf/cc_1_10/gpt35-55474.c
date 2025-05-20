//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    int light1 = 0; //initialize light1 to off
    int light2 = 0; //initialize light2 to off
    char command[20];

    printf("Welcome to Smart Home Light Control\n");

    while (1) { //loop forever
        printf("Enter a command (on/off for light1 or light2, or exit to quit): ");
        scanf("%s", command);

        if (strcmp(command, "on") == 0) {
            char light[20];
            printf("Which light would you like to turn on? (light1 or light2): ");
            scanf("%s", light);

            if (strcmp(light, "light1") == 0) {
                light1 = 1; //turn on light1
                printf("Light1 turned on\n");
            } else if (strcmp(light, "light2") == 0) {
                light2 = 1; //turn on light2
                printf("Light2 turned on\n");
            } else {
                printf("Invalid light name\n");
            }
        } else if (strcmp(command, "off") == 0) {
            char light[20];
            printf("Which light would you like to turn off? (light1 or light2): ");
            scanf("%s", light);

            if (strcmp(light, "light1") == 0) {
                light1 = 0; //turn off light1
                printf("Light1 turned off\n");
            } else if (strcmp(light, "light2") == 0) {
                light2 = 0; //turn off light2
                printf("Light2 turned off\n");
            } else {
                printf("Invalid light name\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break; //exit the loop and end the program
        } else {
            printf("Invalid command: %s\n", command); //print error for invalid command
        }
    }

    return 0;
}
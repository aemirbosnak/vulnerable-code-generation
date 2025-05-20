//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
#include <stdio.h>

// function to turn on the lights
void turnOn(int room) {
    printf("Lights turned on in room %d\n", room);
}

// function to turn off the lights
void turnOff(int room) {
    printf("Lights turned off in room %d\n", room);
}

int main() {
    // smart home settings
    int bedroom = 1;
    int livingRoom = 2;
    int kitchen = 3;

    // initial state of the lights
    int lights[3] = {0, 0, 0};

    // user commands
    int command;
    int room;

    printf("Welcome to Smart Home Light Control!\n");

    do {
        printf("\n");
        printf("What do you want to do?\n");
        printf("1. Turn on the lights\n");
        printf("2. Turn off the lights\n");
        printf("3. End program\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("\n");
                printf("Which room do you want to turn on the lights? (1-3): ");
                scanf("%d", &room);

                if (lights[room-1] == 0) { // if the lights are off, turn them on
                    lights[room-1] = 1;
                    turnOn(room);
                }
                else { // if the lights are already on, nothing happens
                    printf("Lights are already on in room %d\n", room);
                }

                break;

            case 2:
                printf("\n");
                printf("Which room do you want to turn off the lights? (1-3): ");
                scanf("%d", &room);

                if (lights[room-1] == 1) { // if the lights are on, turn them off
                    lights[room-1] = 0;
                    turnOff(room);
                }
                else { // if the lights are already off, nothing happens
                    printf("Lights are already off in room %d\n", room);
                }

                break;

            case 3:
                printf("\n");
                printf("Thank you for using Smart Home Light Control!\n");
                break;

            default:
                printf("\n");
                printf("Invalid choice, please try again.\n");
        }

    } while (command != 3);

    return 0;
}
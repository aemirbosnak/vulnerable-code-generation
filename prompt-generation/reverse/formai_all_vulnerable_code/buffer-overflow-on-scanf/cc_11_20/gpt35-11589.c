//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int drone_controls[3] = {0, 0, 0};
    int choice = 0;
    char sequence[] = "hover";
    int i;

    printf("Welcome to Shape-Shifting Drone Remote Control!\n");

    while(1) {
        printf("\nPlease select a control:\n");
        printf("1. Change drone shape\n");
        printf("2. Change drone size\n");
        printf("3. Change drone color\n");
        printf("4. Enter drone sequence\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("What shape would you like to change the drone to? (1-3)\n");
                scanf("%d", &drone_controls[0]);
                printf("Drone shape changed to: %d\n", drone_controls[0]);
                break;
            case 2:
                printf("What size would you like to change the drone to? (1-3)\n");
                scanf("%d", &drone_controls[1]);
                printf("Drone size changed to: %d\n", drone_controls[1]);
                break;
            case 3:
                printf("What color would you like to change the drone to? (1-3)\n");
                scanf("%d", &drone_controls[2]);
                printf("Drone color changed to: %d\n", drone_controls[2]);
                break;
            case 4:
                printf("Please enter a sequence of commands for the drone: (max. 10 characters)\n");
                scanf("%s", sequence);
                printf("Drone sequence set to: %s\n", sequence);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose a number between 1-5.\n");
        }

        printf("Current drone controls:\n");
        printf("- Shape: %d\n", drone_controls[0]);
        printf("- Size: %d\n", drone_controls[1]);
        printf("- Color: %d\n", drone_controls[2]);

        if(choice == 4) {
            printf("Executing drone sequence...\n");

            for(i = 0; i < sizeof(sequence) - 1; i++) {
                if(sequence[i] == 'h') {
                    printf("Drone is hovering...\n");
                    sleep(1);
                }
                else if(sequence[i] == 'm') {
                    printf("Drone is morphing...\n");
                    sleep(1);
                }
                else if(sequence[i] == 'f') {
                    printf("Drone is flying...\n");
                    sleep(1);
                }
                else {
                    printf("Invalid sequence command.\n");
                }
            }

            printf("Sequence execution complete.\n");
        }
    }

    return 0;
}
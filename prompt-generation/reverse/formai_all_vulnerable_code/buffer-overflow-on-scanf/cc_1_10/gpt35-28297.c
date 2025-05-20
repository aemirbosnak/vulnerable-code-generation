//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>

// Function to take user input
void takeInput(int* altitude, int* speed, char* direction) {
    printf("Enter altitude: ");
    scanf("%d",altitude);
    printf("Enter speed: ");
    scanf("%d",speed);
    printf("Enter direction (N,S,E,W): ");
    scanf(" %c",direction);
}

int main() {
    int altitude, speed;
    char direction;
    int run = 1;

    printf("Welcome to the C Drone Remote Control Program!\n");

    while(run) {
        printf("\n----------------------\n");
        printf("1. Take off drone\n");
        printf("2. Move drone to a location\n");
        printf("3. Land drone\n");
        printf("4. Exit\n");

        int userChoice;
        printf("Enter your choice: ");
        scanf("%d",&userChoice);

        switch(userChoice) {
            case 1:
                printf("\n-----Take off-----\n");
                takeInput(&altitude,&speed,&direction);
                printf("Drone has taken off to altitude %d m with speed %d km/h in direction %c\n",altitude,speed,direction);
                break;
            case 2:
                printf("\n-----Move drone-----\n");
                takeInput(&altitude,&speed,&direction);
                printf("Drone moved to altitude %d m with speed %d km/h in direction %c\n",altitude,speed,direction);
                break;
            case 3:
                printf("\n-----Land drone-----\n");
                printf("Drone landed successfully\n");
                break;
            case 4:
                printf("\n-----Exit-----\n");
                printf("Thank you for using the C Drone Remote Control Program!");
                run = 0;
                break;
            default:
                printf("\n-----Invalid choice-----\n");
                break;
        }
    }

    return 0;
}
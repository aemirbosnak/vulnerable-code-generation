//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int drone_control(int altitude, int speed);

int main(){
    int altitude, speed;

    printf("Enter drone altitude: ");
    scanf("%d", &altitude);

    printf("Enter drone speed: ");
    scanf("%d", &speed);

    drone_control(altitude, speed);

    return 0;
}

int drone_control(int altitude, int speed){
    int action_choice;

    printf("\n\nAltitude: %d\nSpeed: %d\n", altitude, speed);

    printf("Select action:\n");
    printf("1. Increase altitude\n");
    printf("2. Decrease altitude\n");
    printf("3. Increase speed\n");
    printf("4. Decrease speed\n");
    printf("5. Exit\n");

    scanf("%d", &action_choice);

    switch(action_choice){
        case 1: 
            altitude += 100;
            printf("\n\nAltitude increased to %d ft", altitude);
            drone_control(altitude, speed);
            break;

        case 2: 
            altitude -= 100;
            printf("\n\nAltitude decreased to %d ft", altitude);
            drone_control(altitude, speed);
            break;

        case 3: 
            speed += 10;
            printf("\n\nSpeed increased to %d mph", speed);
            drone_control(altitude, speed);
            break;

        case 4: 
            speed -= 10;
            printf("\n\nSpeed decreased to %d mph", speed);
            drone_control(altitude, speed);
            break;

        case 5: 
            printf("\n\nExiting control program...");
            break;

        default: 
            printf("\n\nInvalid selection. Exiting control program...");
            break;
    }

    return 0;
}
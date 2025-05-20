//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>

int main() {

    int choice;
    float x, y, z, x1, y1, z1, distance, height, speed, angle, roll, pitch, yaw;
    char input[100];
    float values[6];
    int i = 0;

    printf("Welcome to the Drone Remote Control Program!\n");
    printf("Please choose an option:\n");
    printf("1. Takeoff\n");
    printf("2. Hover\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Rotate Left\n");
    printf("8. Rotate Right\n");
    printf("9. Land\n");
    printf("0. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1: //Takeoff
            printf("Enter takeoff speed:\n");
            scanf("%f", &speed);
            printf("Enter takeoff height:\n");
            scanf("%f", &height);
            printf("Takeoff initiated...\n");
            printf("Drone is now %f meters in the air...\n", height);
            break;
        case 2: //Hover
            printf("Drone is now hovering...\n");
            break;
        case 3: //Move Forward
            printf("Enter forward speed:\n");
            scanf("%f", &speed);
            printf("Drone is moving forward at %f meters per second...\n", speed);
            break;
        case 4: //Move Backward
            printf("Enter backward speed:\n");
            scanf("%f", &speed);
            printf("Drone is moving backward at %f meters per second...\n", speed);
            break;
        case 5: //Move Left
            printf("Enter left speed:\n");
            scanf("%f", &speed);
            printf("Drone is moving left at %f meters per second...\n", speed);
            break;
        case 6: //Move Right
            printf("Enter right speed:\n");
            scanf("%f", &speed);
            printf("Drone is moving right at %f meters per second...\n", speed);
            break;
        case 7: //Rotate Left
            printf("Enter rotation speed:\n");
            scanf("%f", &speed);
            printf("Drone is rotating left at %f radians per second...\n", speed);
            break;
        case 8: //Rotate Right
            printf("Enter rotation speed:\n");
            scanf("%f", &speed);
            printf("Drone is rotating right at %f radians per second...\n", speed);
            break;
        case 9: //Land
            printf("Landing initiated...\n");
            printf("Drone is now 0 meters in the air...\n");
            break;
        case 0: //Exit
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
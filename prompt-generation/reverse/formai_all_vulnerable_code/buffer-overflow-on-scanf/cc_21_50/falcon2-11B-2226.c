//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int drone_id = 12345;
    int battery_level = 100;
    int altitude = 10;
    int heading = 90;
    int speed = 30;
    int current_state = 0;

    while (current_state!= -1) {
        printf("Drone Remote Control (press -1 to exit):\n");
        printf("1. Takeoff\n");
        printf("2. Land\n");
        printf("3. Move forward\n");
        printf("4. Move backward\n");
        printf("5. Move left\n");
        printf("6. Move right\n");
        printf("7. Increase altitude\n");
        printf("8. Decrease altitude\n");
        printf("9. Increase heading\n");
        printf("10. Decrease heading\n");
        printf("11. Increase speed\n");
        printf("12. Decrease speed\n");
        printf("13. Display battery level\n");
        printf("14. Display altitude\n");
        printf("15. Display heading\n");
        printf("16. Display speed\n");
        printf("17. Display drone ID\n");
        printf("18. Display current state\n");
        printf("19. Display state changes\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_state = 1;
                printf("Drone is taking off...\n");
                sleep(2);
                printf("Drone is now flying at %d m.\n", altitude);
                break;
            case 2:
                current_state = 2;
                printf("Drone is landing...\n");
                sleep(2);
                printf("Drone has landed.\n");
                break;
            case 3:
                current_state = 3;
                printf("Drone is moving forward...\n");
                sleep(2);
                printf("Drone is now at %d m.\n", altitude);
                break;
            case 4:
                current_state = 4;
                printf("Drone is moving backward...\n");
                sleep(2);
                printf("Drone is now at %d m.\n", altitude);
                break;
            case 5:
                current_state = 5;
                printf("Drone is moving left...\n");
                sleep(2);
                printf("Drone is now at %d m.\n", altitude);
                break;
            case 6:
                current_state = 6;
                printf("Drone is moving right...\n");
                sleep(2);
                printf("Drone is now at %d m.\n", altitude);
                break;
            case 7:
                current_state = 7;
                altitude += 10;
                printf("Drone is now at %d m.\n", altitude);
                break;
            case 8:
                current_state = 8;
                altitude -= 10;
                printf("Drone is now at %d m.\n", altitude);
                break;
            case 9:
                current_state = 9;
                heading += 10;
                printf("Drone is now heading %d degrees.\n", heading);
                break;
            case 10:
                current_state = 10;
                heading -= 10;
                printf("Drone is now heading %d degrees.\n", heading);
                break;
            case 11:
                current_state = 11;
                speed += 10;
                printf("Drone is now moving at %d m/s.\n", speed);
                break;
            case 12:
                current_state = 12;
                speed -= 10;
                printf("Drone is now moving at %d m/s.\n", speed);
                break;
            case 13:
                printf("Battery level: %d\n", battery_level);
                break;
            case 14:
                printf("Altitude: %d m\n", altitude);
                break;
            case 15:
                printf("Heading: %d degrees\n", heading);
                break;
            case 16:
                printf("Speed: %d m/s\n", speed);
                break;
            case 17:
                printf("Drone ID: %d\n", drone_id);
                break;
            case 18:
                printf("Current state: %d\n", current_state);
                break;
            case 19:
                printf("State changes:\n");
                printf("1. %d\n", current_state);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
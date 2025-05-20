//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Initializing drone communications...\n");
    
    bool isArmed = false;
    int altitude = 0;
    int thrust = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    
    printf("Drone initialized!\n");

    while (true) {
        printf("\nSelect an option:\n");
        printf("1. Arm Drone\n");
        printf("2. Disarm Drone\n");
        printf("3. Increase Altitude\n");
        printf("4. Decrease Altitude\n");
        printf("5. Increase Thrust\n");
        printf("6. Decrease Thrust\n");
        printf("7. Pitch Forward\n");
        printf("8. Pitch Backward\n");
        printf("9. Roll Left\n");
        printf("10. Roll Right\n");
        printf("11. Yaw Left\n");
        printf("12. Yaw Right\n");
        printf("13. Exit Program\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (isArmed) {
                    printf("The drone is already armed!\n");
                } else {
                    printf("Arming the drone...\n");
                    isArmed = true;
                    printf("Drone armed!\n");
                }
                break;
            case 2:
                if (isArmed) {
                    printf("Disarming the drone...\n");
                    isArmed = false;
                    printf("Drone disarmed!\n");
                } else {
                    printf("The drone is already disarmed!\n");
                }
                break;
            case 3:
                if (isArmed) {
                    altitude++;
                    printf("Altitude increased to %d!\n", altitude);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 4:
                if (isArmed) {
                    altitude--;
                    printf("Altitude decreased to %d!\n", altitude);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 5:
                if (isArmed) {
                    thrust++;
                    printf("Thrust increased to %d!\n", thrust);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 6:
                if (isArmed) {
                    thrust--;
                    printf("Thrust decreased to %d!\n", thrust);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 7:
                if (isArmed) {
                    pitch++;
                    printf("Pitch increased to %d!\n", pitch);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 8:
                if (isArmed) {
                    pitch--;
                    printf("Pitch decreased to %d!\n", pitch);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 9:
                if (isArmed) {
                    roll--;
                    printf("Roll left! Roll is now %d!\n", roll);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 10:
                if (isArmed) {
                    roll++;
                    printf("Roll right! Roll is now %d!\n", roll);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 11:
                if (isArmed) {
                    yaw--;
                    printf("Yaw left! Yaw is now %d!\n", yaw);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 12:
                if (isArmed) {
                    yaw++;
                    printf("Yaw right! Yaw is now %d!\n", yaw);
                } else {
                    printf("The drone is not armed. Please arm the drone first!\n");
                }
                break;
            case 13:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }
}
//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

//initialize variables
int battery_level = 100;
int altitude = 0;
int drone_status = 1; // 1 for activated and 0 for deactivated
int speed = 0;
int direction = 0; // 0 means North, 1 means East, 2 means South and 3 means West

//function to increase the speed
void increase_speed() {
    if (drone_status == 1) {
        speed += 5;
        printf("Speed increased to %d mph\n", speed);
    } else {
        printf("Drone is not activated\n");
    }
}

//function to decrease the speed
void decrease_speed() {
    if (drone_status == 1) {
        speed -= 5;
        printf("Speed decreased to %d mph\n", speed);
    } else {
        printf("Drone is not activated\n");
    }
}

//function to increase altitude
void increase_altitude() {
    if (drone_status == 1) {
        altitude += 50;
        printf("Altitude increased to %d feet\n", altitude);
    } else {
        printf("Drone is not activated\n");
    }
}

//function to decrease altitude
void decrease_altitude() {
    if (drone_status == 1) {
        altitude -= 50;
        printf("Altitude decreased to %d feet\n", altitude);
    } else {
        printf("Drone is not activated\n");
    }
}

//function to change direction
void change_direction(int new_direction) {
    if (drone_status == 1) {
        if (new_direction >= 0 && new_direction <= 3) {
            direction = new_direction;
            printf("Direction changed to %d\n", direction);
        } else {
            printf("Invalid direction\n");
        }
    } else {
        printf("Drone is not activated\n");
    }
}

//function to activate the drone
void activate_drone() {
    printf("Drone activated\n");
    drone_status = 1;
}

//function to deactivate the drone
void deactivate_drone() {
    printf("Drone deactivated\n");
    drone_status = 0;
}

//function to check battery level
void check_battery_level() {
    printf("Battery level: %d%%\n", battery_level);
}

int main() {
    //initialize variables
    int choice;

    printf("Welcome to C Drone Remote Control Program\n");
    printf("-----------------------------------------\n");

    //loop until user chooses to exit
    while (1) {

        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Increase altitude\n");
        printf("4. Decrease altitude\n");
        printf("5. Change direction\n");
        printf("6. Activate drone\n");
        printf("7. Deactivate drone\n");
        printf("8. Check battery level\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                increase_speed();
                break;
            case 2:
                decrease_speed();
                break;
            case 3:
                increase_altitude();
                break;
            case 4:
                decrease_altitude();
                break;
            case 5:
                printf("Enter new direction (0-North, 1-East, 2-South, 3-West):");
                scanf("%d", &direction);
                change_direction(direction);
                break;
            case 6:
                activate_drone();
                break;
            case 7:
                deactivate_drone();
                break;
            case 8:
                check_battery_level();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        //reduce battery level by 5% with each operation
        battery_level -= 5;

        //check if battery level is too low
        if (battery_level <= 20) {
            printf("Battery level too low! Drone returning to base.\n");
            deactivate_drone();
            battery_level = 100; //fully charge the battery again
        }

    }//end while loop

    return 0;
}
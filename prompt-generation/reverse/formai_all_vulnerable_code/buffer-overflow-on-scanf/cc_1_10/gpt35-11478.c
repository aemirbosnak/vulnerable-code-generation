//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DRONES 10

// function prototypes
void drone_status(int);
void drone_controller(int);
void drone_hover(int);
void drone_takeoff(int);
void drone_land(int);
void drone_move(int, char);
void drone_emergency_stop(int);
void drone_video_feed(int);
int get_valid_drone_num();

// global variables
bool is_connected[MAX_DRONES] = {false}; // list of connected drones
bool is_flying[MAX_DRONES] = {false}; // list of flying drones

int main()
{
    int choice, drone_num;

    printf("Welcome to the C Drone Remote Control Program!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Connect a drone\n");
        printf("2. Disconnect a drone\n");
        printf("3. Check drone status\n");
        printf("4. Control drone\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                drone_num = get_valid_drone_num();
                printf("Drone %d has been connected.\n", drone_num);
                is_connected[drone_num] = true;
                break;
            case 2:
                drone_num = get_valid_drone_num();
                printf("Drone %d has been disconnected.\n", drone_num);
                is_connected[drone_num] = false;
                break;
            case 3:
                drone_num = get_valid_drone_num();
                drone_status(drone_num);
                break;
            case 4:
                drone_num = get_valid_drone_num();
                drone_controller(drone_num);
                break;
            case 5:
                printf("Exiting program...goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

void drone_status(int drone_num)
{
    if (!is_connected[drone_num]) {
        printf("Drone %d is not connected.\n", drone_num);
    } else {
        printf("Drone %d status:\n", drone_num);
        printf("Connected: %s\n", is_connected[drone_num] ? "yes" : "no");
        printf("Flying: %s\n", is_flying[drone_num] ? "yes" : "no");
    }
}

void drone_controller(int drone_num)
{
    int choice, altitude = 0;
    char direction;
    bool emergency_stop = false;

    if (!is_connected[drone_num]) {
        printf("Drone %d is not connected.\n", drone_num);
        return;
    }

    do {
        printf("\nDrone %d controller:\n", drone_num);
        printf("1. Hover\n");
        printf("2. Takeoff\n");
        printf("3. Land\n");
        printf("4. Move\n");
        printf("5. Video feed\n");
        printf("6. Emergency stop\n");
        printf("7. Exit controller\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                drone_hover(drone_num);
                break;
            case 2:
                if (!is_flying[drone_num]) {
                    printf("Enter altitude (in meters): ");
                    scanf("%d", &altitude);
                    drone_takeoff(drone_num);
                    is_flying[drone_num] = true;
                    printf("Drone %d is now flying at %d meters.\n", drone_num, altitude);
                } else {
                    printf("Drone %d is already flying.\n", drone_num);
                }
                break;
            case 3:
                if (is_flying[drone_num]) {
                    drone_land(drone_num);
                    is_flying[drone_num] = false;
                    printf("Drone %d has landed.\n", drone_num);
                } else {
                    printf("Drone %d is already landed.\n", drone_num);
                }
                break;
            case 4:
                if (is_flying[drone_num]) {
                    printf("Enter direction (N, S, E, W): ");
                    scanf(" %c", &direction);
                    drone_move(drone_num, direction);
                } else {
                    printf("Drone %d must be flying to move.\n", drone_num);
                }
                break;
            case 5:
                drone_video_feed(drone_num);
                break;
            case 6:
                drone_emergency_stop(drone_num);
                emergency_stop = true;
                break;
            case 7:
                printf("Exiting drone %d controller.\n", drone_num);
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (!emergency_stop);
}

void drone_hover(int drone_num)
{
    printf("Drone %d is hovering.\n", drone_num);
}

void drone_takeoff(int drone_num)
{
    printf("Drone %d is taking off.\n", drone_num);
}

void drone_land(int drone_num)
{
    printf("Drone %d is landing.\n", drone_num);
}

void drone_move(int drone_num, char direction)
{
    printf("Drone %d is moving %c.\n", drone_num, direction);
}

void drone_emergency_stop(int drone_num)
{
    printf("Drone %d has activated emergency stop.\n", drone_num);
}

void drone_video_feed(int drone_num)
{
    printf("Drone %d video feed is active.\n", drone_num);
}

int get_valid_drone_num()
{
    int drone_num;

    do {
        printf("\nEnter drone number (0-%d): ", MAX_DRONES - 1);
        scanf("%d", &drone_num);

        if (drone_num < 0 || drone_num >= MAX_DRONES) {
            printf("Invalid drone number. Please try again.\n");
        } else {
            return drone_num;
        }
    } while (1);
}
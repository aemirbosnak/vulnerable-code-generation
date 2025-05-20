//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

#define DRONE_SPEED_LOW 0x01
#define DRONE_SPEED_MEDIUM 0x02
#define DRONE_SPEED_HIGH 0x03

#define DRONE_DIRECTION_UP 0x01
#define DRONE_DIRECTION_DOWN 0x02
#define DRONE_DIRECTION_LEFT 0x04
#define DRONE_DIRECTION_RIGHT 0x08
#define DRONE_DIRECTION_FORWARD 0x10
#define DRONE_DIRECTION_BACKWARD 0x20

typedef struct {
    int speed;
    int direction;
} drone_command_t;

int main() {
    printf("Welcome to the Drone Remote Control!\n");
    printf("Commands:\n");
    printf("1 - Move forward\n");
    printf("2 - Move backward\n");
    printf("3 - Move left\n");
    printf("4 - Move right\n");
    printf("5 - Move up\n");
    printf("6 - Move down\n");
    printf("Enter command: ");

    char command[10];
    scanf("%s", command);

    switch (command[0]) {
        case '1':
            printf("Drone moving forward...\n");
            break;
        case '2':
            printf("Drone moving backward...\n");
            break;
        case '3':
            printf("Drone moving left...\n");
            break;
        case '4':
            printf("Drone moving right...\n");
            break;
        case '5':
            printf("Drone moving up...\n");
            break;
        case '6':
            printf("Drone moving down...\n");
            break;
        default:
            printf("Invalid command!\n");
            break;
    }

    return 0;
}
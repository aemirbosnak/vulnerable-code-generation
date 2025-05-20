//MISTRAL-7B DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUTTON_FORWARD 0
#define BUTTON_BACKWARD 1
#define BUTTON_LEFT 2
#define BUTTON_RIGHT 3
#define BUTTON_UP 4
#define BUTTON_DOWN 5

#define DRONE_X_POSITION 0
#define DRONE_Y_POSITION 1
#define DRONE_Z_POSITION 2
#define DRONE_BATTERY_LEVEL 3

typedef struct {
    int x_position;
    int y_position;
    int z_position;
    float battery_level;
} Drone;

typedef struct {
    bool is_pressed[6];
} RemoteControl;

void drone_move(Drone *drone, int button) {
    switch (button) {
        case BUTTON_FORWARD:
            drone->x_position++;
            break;
        case BUTTON_BACKWARD:
            drone->x_position--;
            break;
        case BUTTON_LEFT:
            drone->y_position--;
            break;
        case BUTTON_RIGHT:
            drone->y_position++;
            break;
        case BUTTON_UP:
            drone->z_position++;
            break;
        case BUTTON_DOWN:
            drone->z_position--;
            break;
        default:
            break;
    }
}

void remote_control_update(RemoteControl *remote_control) {
    char input[6] = {0};

    scanf("%s", input);

    int button;
    if (sscanf(input, "%d", &button) == 1) {
        remote_control->is_pressed[button] = true;
    }
}

void drone_display_position_and_battery(Drone drone) {
    printf("Drone Position: (%d, %d, %d)\n", drone.x_position, drone.y_position, drone.z_position);
    printf("Drone Battery Level: %.2f\n", drone.battery_level);
}

int main() {
    Drone drone = {0};
    RemoteControl remote_control = {0};

    while (true) {
        remote_control_update(&remote_control);

        for (int i = 0; i < 6; i++) {
            if (remote_control.is_pressed[i]) {
                drone_move(&drone, i);
            }
        }

        drone_display_position_and_battery(drone);
    }

    return 0;
}
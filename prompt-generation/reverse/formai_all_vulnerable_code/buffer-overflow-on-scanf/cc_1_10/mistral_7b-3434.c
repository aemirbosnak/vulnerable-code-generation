//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Remote Control Class
typedef struct {
    char name[20];
    int channel[5];
    bool is_on;
} RemoteControl;

void rc_init(RemoteControl *rc, char *name) {
    strcpy(rc->name, name);
    for (int i = 0; i < 5; i++) {
        rc->channel[i] = -1;
    }
    rc->is_on = false;
}

void rc_turn_on(RemoteControl *rc) {
    rc->is_on = true;
}

void rc_turn_off(RemoteControl *rc) {
    rc->is_on = false;
}

void rc_set_channel(RemoteControl *rc, int channel, int value) {
    if (channel >= 0 && channel < 5) {
        rc->channel[channel] = value;
    }
}

// Vehicle Class
typedef struct {
    char name[20];
    int x;
    int y;
    int speed;
    RemoteControl rc;
} Vehicle;

void v_init(Vehicle *v, char *name, int start_x, int start_y) {
    strcpy(v->name, name);
    v->x = start_x;
    v->y = start_y;
    v->speed = 0;
    rc_init(&v->rc, "RC for Vehicle");
}

void v_move_forward(Vehicle *v) {
    v->speed += 5;
}

void v_move_backward(Vehicle *v) {
    v->speed -= 5;
}

void v_move_left(Vehicle *v) {
    v->x -= 5;
}

void v_move_right(Vehicle *v) {
    v->x += 5;
}

void v_control(Vehicle *v, int channel) {
    switch (channel) {
        case 0:
            v_move_forward(v);
            break;
        case 1:
            v_move_backward(v);
            break;
        case 2:
            v_move_left(v);
            break;
        case 3:
            v_move_right(v);
            break;
        default:
            printf("Invalid Channel!\n");
            break;
    }
}

int main() {
    // Initialize Remote Control and Vehicle
    RemoteControl rc;
    rc_init(&rc, "RC for Simulation");

    Vehicle car;
    v_init(&car, "Car", 0, 0);

    // Start Simulation
    printf("Simulation Started\n");
    rc_turn_on(&rc);

    while (true) {
        printf("Enter Channel and Value (0-4, -1 to exit): ");
        int channel, value;
        scanf("%d%d", &channel, &value);

        if (channel == -1) {
            rc_turn_off(&rc);
            break;
        }

        rc_set_channel(&rc, channel, value);
        v_control(&car, channel);
        printf("Car (%s, %d, %d)\n", car.name, car.x, car.y);
    }

    printf("Simulation Ended\n");
    return 0;
}
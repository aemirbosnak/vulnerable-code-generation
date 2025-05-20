//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int x;
    int y;
    int (*move_func)(int, int);
} Vehicle;

void print_vehicle_info(Vehicle vehicle) {
    printf("\nName: %s\nPosition: (%d, %d)", vehicle.name, vehicle.x, vehicle.y);
}

int move_forward(int x, int y) {
    x += 1;
    y += 1;
    return x, y;
}

int move_backward(int x, int y) {
    x -= 1;
    y -= 1;
    return x, y;
}

int move_left(int x, int y) {
    x -= 1;
    return x, y;
}

int move_right(int x, int y) {
    y += 1;
    return x, y;
}

int (*get_move_func(char* func_name))(int, int) {
    static const struct {
        char name[20];
        int (*func)(int, int);
    } functions[] = {{"forward", move_forward}, {"backward", move_backward}, {"left", move_left}, {"right", move_right}};

    for (int i = 0; i < 4; i++) {
        if (strcmp(func_name, functions[i].name) == 0)
            return functions[i].func;
    }

    return NULL;
}

int main() {
    Vehicle vehicle = {"Car", 0, 0};
    char action[20];

    while (1) {
        printf("\nEnter action (forward, backward, left, right): ");
        scanf("%s", action);

        if (get_move_func(action)) {
            int x = vehicle.x, y = vehicle.y;
            vehicle.x = vehicle.x + get_move_func(action)(x, y - get_move_func(action)(x, y));
            vehicle.y = vehicle.y + get_move_func(action)(x, y - get_move_func(action)(x, y));
            print_vehicle_info(vehicle);
        } else {
            printf("Invalid action\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10

typedef struct {
    char *command;
    int (*function)();
} command_t;

void forward(int speed) {
    printf("Vehicle is moving forward at %d km/h\n", speed);
}

void backward(int speed) {
    printf("Vehicle is moving backward at %d km/h\n", speed);
}

void turn_left(int angle) {
    printf("Vehicle is turning left at %d degrees\n", angle);
}

void turn_right(int angle) {
    printf("Vehicle is turning right at %d degrees\n", angle);
}

int main() {
    command_t commands[MAX_COMMANDS] = {
        {"forward", (int (*)())forward},
        {"backward", (int (*)())backward},
        {"turn_left", (int (*)())turn_left},
        {"turn_right", (int (*)())turn_right}
    };

    char input[100];
    while(1) {
        printf("Enter command: ");
        scanf("%s", input);

        int i;
        for(i=0; i<MAX_COMMANDS; i++) {
            if(strcmp(input, commands[i].command) == 0) {
                (*commands[i].function)();
            }
        }
    }

    return 0;
}
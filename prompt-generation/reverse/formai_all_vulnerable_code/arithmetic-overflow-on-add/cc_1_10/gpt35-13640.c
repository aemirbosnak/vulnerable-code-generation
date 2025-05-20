//FormAI DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movement functions

void forward(int distance) {
    printf("Moving Forward %d units\n", distance);
}

void backward(int distance) {
    printf("Moving Backward %d units\n", distance);
}

void turn_left(int degrees) {
    printf("Turning Left %d degrees\n", degrees);
}

void turn_right(int degrees) {
    printf("Turning Right %d degrees\n", degrees);
}

// Control functions

void move(char direction, int distance) {
    switch(direction) {
        case 'F':
        case 'f':
            forward(distance);
            break;
        case 'B':
        case 'b':
            backward(distance);
            break;
        case 'L':
        case 'l':
            turn_left(distance);
            break;
        case 'R':
        case 'r':
            turn_right(distance);
            break;
        default:
            printf("Invalid direction. Please enter F, B ,L or R\n");
            break;
    }
}

void execute_command(char *command) {
    int i = 0;
    int len = strlen(command);
    int distance = 0;
    int degrees = 0;
    char direction;

    for (i = 0; i < len; i++) {
        char current_char = command[i];
        if (current_char >= '0' && current_char <= '9') {
            distance = distance * 10 + (current_char - '0');
        } else if (current_char == 'F' || 
                   current_char == 'f' ||
                   current_char == 'B' ||
                   current_char == 'b' ||
                   current_char == 'L' ||
                   current_char == 'l' ||
                   current_char == 'R' ||
                   current_char == 'r') {
            move(direction, distance);
            distance = 0;
            direction = current_char;
        } else if (current_char == ' ') {
            continue;
        } else {
            printf("Invalid character in command: %c", current_char);
            break;
        }
    }
    move(direction, distance);
}

int main() {
    char command[100];
    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);
    execute_command(command);
    return 0;
}
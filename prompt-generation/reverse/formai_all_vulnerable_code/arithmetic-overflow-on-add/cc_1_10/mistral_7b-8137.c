//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define CAR_SPEED 10
#define MAX_MORSE_CODE_LENGTH 20
#define DASH "-."
#define DOT ".."
#define BULLET "*"

typedef struct {
    int x, y;
} position;

typedef struct {
    int forward, backward, left, right;
} direction;

void morse_code_to_direction(const char* morse_code, direction* dir) {
    switch (*morse_code) {
        case 'F': dir->forward = 1; break;
        case 'B': dir->backward = 1; break;
        case 'L': dir->left = 1; break;
        case 'R': dir->right = 1; break;
        case 'S': // Stop
            dir->forward = dir->backward = dir->left = dir->right = 0;
            break;
        default:
            fprintf(stderr, "Invalid Morse code: %c\n", *morse_code);
            exit(EXIT_FAILURE);
    }
}

void print_car_position(const position* pos) {
    printf("(%d, %d)\n", pos->x, pos->y);
}

void move_car(position* pos, const direction* dir) {
    pos->x += dir->right - dir->left;
    pos->y += dir->forward - dir->backward;
}

void simulate_remote_control_car(void) {
    srand(time(NULL));

    position car = {0, 0};
    direction direction;

    while (1) {
        printf("Car position: ");
        print_car_position(&car);
        printf("Enter Morse code: ");

        char morse_code[MAX_MORSE_CODE_LENGTH + 1];
        fgets(morse_code, MAX_MORSE_CODE_LENGTH + 1, stdin);
        morse_code[strcspn(morse_code, "\n")] = '\0';

        if (strlen(morse_code) > MAX_MORSE_CODE_LENGTH) {
            fprintf(stderr, "Morse code too long.\n");
            continue;
        }

        morse_code_to_direction(morse_code, &direction);
        move_car(&car, &direction);
        usleep(rand() % 100 + CAR_SPEED * 1000);
    }
}

int main() {
    simulate_remote_control_car();
    return 0;
}
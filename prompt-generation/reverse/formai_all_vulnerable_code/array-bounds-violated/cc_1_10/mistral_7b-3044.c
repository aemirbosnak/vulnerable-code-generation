//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define BUTTONS_ROWS 5
#define BUTTONS_COLS 10

int elevator_pos = 0;
int buttons[BUTTONS_ROWS][BUTTONS_COLS];

void init_buttons() {
    int i, j;
    for (i = 0; i < BUTTONS_ROWS; i++) {
        for (j = 0; j < BUTTONS_COLS; j++) {
            buttons[i][j] = 0;
        }
    }
}

void move_elevator(int floor) {
    if (elevator_pos == floor) {
        printf("Elevator is already at floor %d.\n", floor);
        return;
    }

    printf("Moving elevator to floor %d.\n", floor);
    elevator_pos = floor;
}

int is_button_pressed(int row, int col) {
    if (row < 0 || row >= BUTTONS_ROWS || col < 0 || col >= BUTTONS_COLS) {
        return 0;
    }

    return buttons[row][col];
}

void print_elevator_status() {
    printf("Current floor: %d\n", elevator_pos);
    int i, j;
    for (i = 0; i < BUTTONS_ROWS; i++) {
        for (j = 0; j < BUTTONS_COLS; j++) {
            if (is_button_pressed(i, j)) {
                printf("Button (%d, %d) is pressed.\n", i, j);
            }
        }
    }
}

void handle_user_input() {
    int row, col;
    printf("Enter button row (0 to %d): ", BUTTONS_ROWS - 1);
    scanf("%d", &row);

    printf("Enter button column (0 to %d): ", BUTTONS_COLS - 1);
    scanf("%d", &col);

    buttons[row][col] = 1;
    move_elevator(row + 1);
}

int main() {
    init_buttons();
    while (1) {
        print_elevator_status();
        handle_user_input();
    }
    return 0;
}
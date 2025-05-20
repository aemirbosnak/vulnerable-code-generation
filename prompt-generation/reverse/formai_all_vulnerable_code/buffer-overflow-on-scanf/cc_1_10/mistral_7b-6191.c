//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct Shape {
    int id;
    char name[20];
    uint8_t bits[8];
} Shape;

const Shape shapes[] = {
    {.id = 0, .name = "Triangle", .bits = {0x01, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
    {.id = 1, .name = "Square", .bits = {0x0, 0x0, 0x01, 0x0, 0x0, 0x0, 0x0, 0x0}},
    {.id = 2, .name = "Circle", .bits = {0x0, 0x0, 0x0, 0x01, 0x0, 0x0, 0x0, 0x0}},
    {.id = 3, .name = "Hexagon", .bits = {0x0, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0, 0x0}},
};

int main() {
    int shape_id = 0;
    int user_input;

    printf("Welcome to the Shape Shifter!\n");
    printf("Please enter the ID of the shape you want to display (0 for Triangle, 1 for Square, 2 for Circle, or 3 for Hexagon):\n");
    scanf("%d", &user_input);

    if (user_input < 0 || user_input > 3) {
        printf("Invalid shape ID. Exiting...\n");
        return 1;
    }

    shape_id = user_input;

    Shape current_shape = shapes[shape_id];

    printf("Current shape: %s\n", current_shape.name);

    printf("Press any key to shift the shape...\n");
    getchar();

    for (int i = 0; i < 10; i++) {
        bool shift_right = false;
        for (int j = 0; j < 8; j++) {
            if (current_shape.bits[j] == 1) {
                shift_right = true;
                break;
            }
        }

        if (shift_right) {
            for (int j = 7; j > 0; j--) {
                current_shape.bits[j] = current_shape.bits[j - 1];
            }
            current_shape.bits[0] = 0;
        } else {
            for (int j = 0; j < 7; j++) {
                current_shape.bits[j] = current_shape.bits[j + 1];
            }
            current_shape.bits[7] = 1;
        }

        printf("Shape after %d shift(s): %s\n", i + 1, current_shape.name);
    }

    return 0;
}
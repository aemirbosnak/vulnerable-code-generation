//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_CONFIGURATION_LENGTH 100

// Structure to hold the pattern configuration
typedef struct {
    char direction; // 'L' for left to right, 'R' for right to left
    char shape; // 'L' for left-justified, 'C' for centered, 'R' for right-justified
    char fill; // 'S' for solid, 'L' for line-filled, 'R' for random-filled
    int size; // size of the pattern
} pattern_config_t;

// Function to print the pattern based on the configuration
void print_pattern(pattern_config_t config) {
    char pattern[MAX_PATTERN_LENGTH];
    int i, j;

    // Initialize the pattern with spaces
    for (i = 0; i < MAX_PATTERN_LENGTH; i++) {
        pattern[i] = ' ';
    }

    // Set the direction of the pattern
    switch (config.direction) {
        case 'L':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'L';
            }
            break;
        case 'R':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'R';
            }
            break;
        default:
            pattern[0] = 'L';
            for (i = 1; i < config.size; i++) {
                pattern[i] = 'R';
            }
            break;
    }

    // Set the shape of the pattern
    switch (config.shape) {
        case 'L':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'L';
            }
            break;
        case 'C':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'C';
            }
            break;
        case 'R':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'R';
            }
            break;
        default:
            pattern[0] = 'L';
            for (i = 1; i < config.size; i++) {
                pattern[i] = 'R';
            }
            break;
    }

    // Set the fill of the pattern
    switch (config.fill) {
        case 'S':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'S';
            }
            break;
        case 'L':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'L';
            }
            break;
        case 'R':
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'R';
            }
            break;
        default:
            for (i = 0; i < config.size; i++) {
                pattern[i] = 'X';
            }
            break;
    }

    // Print the pattern
    for (i = 0; i < config.size; i++) {
        printf("%c", pattern[i]);
    }
    printf("\n");
}

int main() {
    // Read the configuration from the user
    char direction, shape, fill;
    int size;
    printf("Enter the pattern configuration:\n");
    printf("Direction (L/R): ");
    scanf(" %c", &direction);
    printf("Shape (L/C/R): ");
    scanf(" %c", &shape);
    printf("Fill (S/L/R): ");
    scanf(" %c", &fill);
    printf("Size: ");
    scanf("%d", &size);

    // Create a pattern configuration structure based on the user input
    pattern_config_t config = {
        .direction = direction,
        .shape = shape,
        .fill = fill,
        .size = size
    };

    // Print the pattern based on the configuration
    print_pattern(config);

    return 0;
}
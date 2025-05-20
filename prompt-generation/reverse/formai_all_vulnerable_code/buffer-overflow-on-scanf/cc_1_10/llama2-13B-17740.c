//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_CONFIGURATION_LENGTH 100

// Structure to hold the pattern configuration
typedef struct {
    char direction;  // 'H' for horizontal, 'V' for vertical, or 'A' for arbitrary
    char shape;     // 'L' for line, 'O' for circle, or 'S' for square
    int size;      // Size of the shape
    int gap;      // Gap between shapes
} pattern_config_t;

// Function to print a pattern based on the configuration
void print_pattern(pattern_config_t config) {
    char pattern[MAX_PATTERN_LENGTH];
    int i, j;

    // Initialize the pattern
    for (i = 0; i < MAX_PATTERN_LENGTH; i++) {
        pattern[i] = ' ';
    }

    // Set the direction and shape based on the configuration
    if (config.direction == 'H') {
        // Horizontal direction
        if (config.shape == 'L') {
            // Line
            for (j = 0; j < config.size; j++) {
                pattern[i * config.size + j] = '>';
            }
        } else if (config.shape == 'O') {
            // Circle
            for (j = 0; j < config.size; j++) {
                pattern[i * config.size + j] = 'o';
            }
        } else {
            // Square
            for (j = 0; j < config.size; j++) {
                pattern[i * config.size + j] = 'X';
            }
        }
    } else if (config.direction == 'V') {
        // Vertical direction
        if (config.shape == 'L') {
            // Line
            for (j = 0; j < config.size; j++) {
                pattern[i * config.size + j] = '>';
            }
        } else if (config.shape == 'O') {
            // Circle
            for (j = 0; j < config.size; j++) {
                pattern[i * config.size + j] = 'o';
            }
        } else {
            // Square
            for (j = 0; j < config.size; j++) {
                pattern[i * config.size + j] = 'X';
            }
        }
    } else {
        // Arbitrary direction
        for (j = 0; j < config.size; j++) {
            pattern[i * config.size + j] = 'X';
        }
    }

    // Add gaps between shapes
    for (int k = 0; k < config.gap; k++) {
        pattern[i * config.size + k] = ' ';
    }

    // Print the pattern
    printf("%s\n", pattern);
}

int main() {
    // Get the pattern configuration from the user
    char direction;
    char shape;
    int size;
    int gap;

    printf("Enter the pattern direction (H/V/A): ");
    scanf("%c", &direction);

    printf("Enter the pattern shape (L/O/S): ");
    scanf("%c", &shape);

    printf("Enter the pattern size: ");
    scanf("%d", &size);

    printf("Enter the gap between shapes: ");
    scanf("%d", &gap);

    // Create the pattern configuration struct
    pattern_config_t config;
    config.direction = direction;
    config.shape = shape;
    config.size = size;
    config.gap = gap;

    // Print the pattern based on the configuration
    print_pattern(config);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_VERSION 2
#define QR_SIZE ((QR_VERSION * 4) + 17)

// Pattern shapes
#define SHAPE_DARK 1
#define SHAPE_LIGHT 0

// Alignment patterns
static const int ALIGNMENT_PATTERNS[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  1,  1,  1,  0,
    0,  0,  0,  0,  0,  0,  1,  0,  1,  0,
    0,  0,  0,  0,  0,  0,  1,  0,  1,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

// Function prototypes
static int get_value(unsigned char *data, int x, int y);

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get input string
    int input_length = strlen(argv[1]);
    unsigned char input[input_length + 1];
    strcpy((char *)input, argv[1]);

    // Initialize QR code data
    unsigned char data[QR_SIZE][QR_SIZE];
    memset(data, SHAPE_LIGHT, sizeof(data));

    // Encode version information
    int version_bit_pattern = 0;
    for (int i = 0; i < 6; i++) {
        version_bit_pattern |= (QR_VERSION << i);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            data[i + 1][QR_SIZE - (j + 1)] = SHAPE_DARK & ((version_bit_pattern >> (i * 6 + j)) & 1);
        }
    }

    // Encode alignment patterns
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            data[i][j] &= ALIGNMENT_PATTERNS[i * QR_SIZE + j];
        }
    }

    // Encode input data
    int data_index = 0;
    int x = QR_SIZE - 1;
    int y = QR_SIZE - 1;
    int direction = -1;
    while (data_index < input_length) {
        while (data[y][x] != SHAPE_LIGHT) {
            if (direction == -1) {
                x--;
            } else if (direction == 1) {
                x++;
            }
        }
        data[y][x] = SHAPE_DARK;
        int value = get_value(input, input_length, data_index);
        for (int i = 0; i < 8; i++) {
            if ((value >> i) & 1) {
                data[y][x - i] = SHAPE_DARK;
            }
        }
        data_index++;
        if (direction == -1) {
            y--;
        } else if (direction == 1) {
            y++;
        }
        if (y == 0) {
            direction = 1;
        } else if (y == QR_SIZE - 1) {
            direction = -1;
        }
    }

    // Generate QR code image
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if (data[i][j] == SHAPE_DARK) {
                printf("%s", "#");
            } else {
                printf("%s", ".");
            }
        }
        printf("%s", "\n");
    }

    return EXIT_SUCCESS;
}

// Get value from binary input data
static int get_value(unsigned char *data, int length, int index) {
    int value = 0;
    for (int i = 0; i < 8; i++) {
        if (index + i < length) {
            value |= ((data[index + i] & 0x80) >> (7 - i));
        }
    }
    return value;
}
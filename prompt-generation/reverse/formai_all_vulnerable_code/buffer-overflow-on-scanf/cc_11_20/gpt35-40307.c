//FormAI DATASET v1.0 Category: QR code reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

// They said QR code reading couldn't be done in C, but we're about to prove them wrong!
typedef struct qr_code {
    uint8_t data[72][72]; // QR code can store up to 177x177 bits of data, but we're using a smaller array for simplicity
    int version; // version number of the QR code, dictates size and error correction level
} qr_code;

/* 
 * Will this code handle all possible QR codes? Absolutely not.
 * But for our purposes, we'll assume the data conforms to standard QR code formatting.
 * This function will parse the input string and populate a QR code structure accordingly.
 * (Disclaimer: this is a very condensed version of actual QR code parsing, but you get the gist)
 */
qr_code parse_qr_code(const char* input_string) {
    // Initialize struct and some common metadata
    qr_code code;
    code.version = 1;
    memset(code.data, 0, sizeof(code.data));

    // Iterate over string, populating QR code with data
    int row = 0, col = 0;
    for (int i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == '1') {
            code.data[row][col] = 1;
        }
        col++;
        if (col >= 72) {
            row++;
            col = 0;
        }
    }

    // Return parsed struct
    return code;
}

// Check if the given 3x3 module at row,col is a valid QR code alignment marker
bool is_valid_alignment_marker(qr_code code, int row, int col) {
    // Check for falgs at three corners of the module
    bool top_left = code.data[row][col];
    bool top_right = code.data[row][col+2];
    bool bottom_left = code.data[row+2][col];

    // Check for dark modules in the surrounding 5x5 area
    bool surroundings[5][5];
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            surroundings[i+2][j+2] = code.data[row+i][col+j];
        }
    }
    bool top = surroundings[0][2] && surroundings[1][1] && surroundings[1][2] && surroundings[1][3] && surroundings[2][2];
    bool left = surroundings[2][0] && surroundings[1][1] && surroundings[2][1] && surroundings[3][1] && surroundings[2][2];
    bool bottom = surroundings[4][2] && surroundings[3][1] && surroundings[3][2] && surroundings[3][3] && surroundings[2][2];
    bool right = surroundings[2][4] && surroundings[1][3] && surroundings[2][3] && surroundings[3][3] && surroundings[2][2];

    // Determine validity
    return top_left && top_right && bottom_left && top && left && bottom && right;
}

// Find and return the location of the alignment markers in the QR code
int* find_alignment_markers(qr_code code) {
    // Determine the number of alignment markers based on version number
    int num_markers;
    if (code.version <= 1) {
        num_markers = 0;
    } else if (code.version <= 6) {
        num_markers = 1;
    } else if (code.version <= 13) {
        num_markers = 2;
    } else if (code.version <= 22) {
        num_markers = 3;
    } else if (code.version <= 30) {
        num_markers = 4;
    } else {
        num_markers = 5;
    }

    // Initialize array to store marker locations
    int* markers = malloc(num_markers * 2 * sizeof(int)); // 2*num_markers since each marker has a row/col coordinate

    // Attempt to find markers at increasing distances from the top left corner
    int min_distance = (code.version - 1) * 4 + 21; // formula for minimum marker distance based on version number
    for (int distance = min_distance; distance < 72; distance++) {
        for (int row = distance; row <= 72 - distance; row++) {
            for (int col = distance; col <= 72 - distance; col++) {
                if (is_valid_alignment_marker(code, row, col)) {
                    // Calculate the offset of this marker from the top left corner
                    int offset = (distance - min_distance) / (num_markers - 1);
                    int index = (distance - min_distance) / offset;
                    if (index >= num_markers) {
                        break; // last marker already found
                    }

                    // Store marker location in array
                    markers[2*index] = row;
                    markers[2*index+1] = col;
                }
            }
        }
        if (markers[2*(num_markers-1)] != 0) {
            break; // last marker found, exit loop
        }
    }

    // Return array of marker locations
    return markers;
}

int main() {
    // Read in QR code from user input
    printf("Please enter a QR code (represented by a string of 0's and 1's): ");
    char input[5200]; // 72*72 bits = 5184 bits max
    scanf("%s", input);

    // Parse input into QR code structure
    qr_code code = parse_qr_code(input);

    // Find alignment markers in QR code and print their locations
    int* markers = find_alignment_markers(code);
    printf("Found %d alignment marker(s):\n", code.version >= 2 ? markers[3] ? 4 : 3 : markers[1] ? 2 : 1);
    for (int i = 0; i < code.version >= 2 ? markers[3] ? 4 : 3 : markers[1] ? 2 : 1; i++) {
        printf("(%d, %d)\n", markers[2*i], markers[2*i+1]);
    }

    // Let's add a dramatic pause to build suspense before we exit
    printf("Scanning...\n");
    time_t start, end;
    time(&start);
    do {
        time(&end);
    } while(difftime(end, start) < 3);
    printf("Scan complete. Exiting...\n");

    // Free dynamically allocated memory before exiting
    free(markers);

    return 0;
}
//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 40

void draw_ascii(char* input);

int main(void) {
    char input[256]; // Arbitrary size for input string
    printf("Enter text to convert to ASCII art:\n");
    fgets(input, 256, stdin);

    // Remove trailing newline character
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = 0;
    }

    draw_ascii(input);
    return 0;
}

void draw_ascii(char* input) {
    char ascii_art[ASCII_HEIGHT][ASCII_WIDTH]; // 2D array to store ASCII art
    int i, j, k;
    for (i = 0; i < strlen(input); i++) {
        char letter = input[i];

        // Fill 2D array with ASCII art for current letter
        if (letter == ' ') {
            for (j = 0; j < ASCII_HEIGHT; j++) {
                for (k = 0; k < 7; k++) {
                    ascii_art[j][(i * 7) + k] = ' ';
                }
            }
        } else {
            // Open file containing ASCII art for current letter
            char file_name[30];
            sprintf(file_name, "letters/%c.txt", letter);
            FILE* file = fopen(file_name, "r");
            if (file == NULL) {
                printf("Could not open file %s\n", file_name);
                return;
            }

            // Read ASCII art from file into 2D array
            char line[ASCII_WIDTH];
            int line_num = 0;
            while (fgets(line, ASCII_WIDTH, file) != NULL && line_num < ASCII_HEIGHT) {
                strcpy(ascii_art[line_num] + (i * 7), line); // Add 7 spaces for each character width
                line_num++;
            }

            // Close file and move on to the next letter
            fclose(file);
        }
    }

    // Print 2D array of ASCII art
    for (i = 0; i < ASCII_HEIGHT; i++) {
        for (j = 0; j < strlen(input) * 7; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}
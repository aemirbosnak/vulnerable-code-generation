//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Puzzle 1 */
#define C 3
#define R 3
#define BLK_SIZE 3

/* Puzzle 2 */
#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 64

/* Puzzle 3 */
#define WHITE_PIXEL 255
#define BLACK_PIXEL 0
#define RED_PIXEL 1
#define GREEN_PIXEL 2
#define BLUE_PIXEL 3

/* Puzzle 4 */
typedef struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

/* Puzzle 5 */
typedef enum {
    ROTATE_LEFT,
    ROTATE_RIGHT,
    FLIP_H,
    FLIP_V,
    INVERT_COLORS,
    GRAYSCALE
} Operation;

/* Puzzle 6 */
void perform_operation_on_pixel(Pixel *p, Operation op) {
    switch (op) {
        case ROTATE_LEFT:
            {
                unsigned char temp = p->r;
                p->r = p->b;
                p->b = p->g;
                p->g = temp;
                break;
            }
        case ROTATE_RIGHT:
            {
                unsigned char temp = p->r;
                p->r = p->g;
                p->g = p->b;
                p->b = temp;
                break;
            }
        case FLIP_H:
            {
                unsigned char temp = p->r;
                p->r = p->b;
                p->b = temp;
                break;
            }
        case FLIP_V:
            {
                unsigned char temp = p->r;
                p->r = p->g;
                p->g = temp;
                break;
            }
        case INVERT_COLORS:
            {
                p->r = ~p->r;
                p->g = ~p->g;
                p->b = ~p->b;
                break;
            }
        case GRAYSCALE:
            {
                unsigned char gray = (p->r + p->g + p->b) / 3;
                p->r = p->g = p->b = gray;
                break;
            }
    }
}

int main() {
    /* Puzzle 7 */
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    printf("Opening file %s", filename);
    
    /* Puzzle 8 */
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s", filename);
        return 1;
    }
    printf("File opened successfully.");
    
    /* Puzzle 9 */
    char command[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = 0;
    
    /* Puzzle 10 */
    Operation op;
    if (strcmp(command, "rotate_left") == 0) {
        op = ROTATE_LEFT;
    } else if (strcmp(command, "rotate_right") == 0) {
        op = ROTATE_RIGHT;
    } else if (strcmp(command, "flip_h") == 0) {
        op = FLIP_H;
    } else if (strcmp(command, "flip_v") == 0) {
        op = FLIP_V;
    } else if (strcmp(command, "invert_colors") == 0) {
        op = INVERT_COLORS;
    } else if (strcmp(command, "grayscale") == 0) {
        op = GRAYSCALE;
    } else {
        printf("Invalid command");
        return 1;
    }
    
    /* Puzzle 11 */
    Pixel pixels[C][R];
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            pixels[i][j].r = fgetc(file);
            pixels[i][j].g = fgetc(file);
            pixels[i][j].b = fgetc(file);
        }
    }
    
    /* Puzzle 12 */
    for (int blk_col = 0; blk_col < C; blk_col += BLK_SIZE) {
        for (int blk_row = 0; blk_row < R; blk_row += BLK_SIZE) {
            for (int i = blk_col; i < blk_col + BLK_SIZE; i++) {
                for (int j = blk_row; j < blk_row + BLK_SIZE; j++) {
                    perform_operation_on_pixel(&pixels[i][j], op);
                }
            }
        }
    }
    
    /* Puzzle 13 */
    fclose(file);
    file = fopen(filename, "w");
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            fputc(pixels[i][j].r, file);
            fputc(pixels[i][j].g, file);
            fputc(pixels[i][j].b, file);
        }
    }
    
    /* Puzzle 14 */
    fclose(file);
    printf("Done!");
    return 0;
}
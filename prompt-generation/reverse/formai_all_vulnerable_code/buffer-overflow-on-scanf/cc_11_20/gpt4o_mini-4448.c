//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void draw_pixel_art(int size) {
    int dimension = size * 5; // Overall dimension based on pixel size
    
    // Top part of the smiley face
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j >= size * 1 && j < size * 4) {
                // Draw the top arc of the head
                if (j == size * 1 + size - 1 || j == size * 4 - size) {
                    printf("O");
                } else {
                    printf("o");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Middle part of the smiley face
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j >= size * 1 && j < size * 4) {
                // Draw the middle part of the face
                if (i == size / 2) {
                    if (j == size * 2 + size / 2 - 1) {
                        printf(" ");
                    } else {
                        printf(" ");
                    }
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Bottom part of the smiley face (the mouth)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j >= size * 1 && j < size * 4) {
                // Draw the mouth
                if (j == size * 2 || j == size * 3) {
                    printf(" ");
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Draw the smile
    for (int i = 0; i < size / 2; i++) {
        for (int j = 0; j < dimension; j++) {
            if (j >= size * 1 && j < size * 4) {
                // Draw a smile
                if (j == size * 2) {
                    for (int k = 0; k < size; k++) {
                        printf(" ");
                    }
                    printf("~");
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int pixel_size;

    // Get the desired pixel size from user
    printf("Enter the pixel size (1-5): ");
    scanf("%d", &pixel_size);

    // Input validation
    if (pixel_size < 1 || pixel_size > 5) {
        printf("Invalid size. Please enter a size between 1 and 5.\n");
        return 1;
    }

    // Draw the pixel art
    draw_pixel_art(pixel_size);

    return 0;
}
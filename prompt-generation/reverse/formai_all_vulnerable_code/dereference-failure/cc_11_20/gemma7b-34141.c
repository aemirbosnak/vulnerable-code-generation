//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Prepare the cosmic canvas
    int x_size = 100;
    int y_size = 100;
    int **stars = (int**)malloc(y_size * sizeof(int*));
    for (int i = 0; i < y_size; i++) {
        stars[i] = (int*)malloc(x_size * sizeof(int));
    }

    // Paint the cosmic tapestry
    for (int y = 0; y < y_size; y++) {
        for (int x = 0; x < x_size; x++) {
            stars[y][x] = rand() % 2;
        }
    }

    // Embark on a cosmic journey
    int current_x = 0;
    int current_y = 0;
    int direction = 1;

    // Traverse the cosmic canvas
    while (stars[current_y][current_x] != -1) {
        switch (direction) {
            case 1:
                current_x++;
                break;
            case 2:
                current_y++;
                break;
            case 3:
                current_x--;
                break;
            case 4:
                current_y--;
                break;
        }

        // Check if the new position is within the bounds of the canvas
        if (current_x < 0 || current_x >= x_size) {
            direction = 3;
        }
        if (current_y < 0 || current_y >= y_size) {
            direction = 4;
        }

        // Print the star pattern
        for (int y = 0; y < y_size; y++) {
            for (int x = 0; x < x_size; x++) {
                if (stars[y][x] == 1 && current_x == x && current_y == y) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }

        // Sleep for a cosmic moment
        sleep(1);
    }

    // Conclude the cosmic adventure
    printf("Congratulations! You have reached the end of the cosmic canvas.\n");

    // Free the cosmic memory
    for (int i = 0; i < y_size; i++) {
        free(stars[i]);
    }
    free(stars);

    return 0;
}
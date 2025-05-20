//Falcon-180B DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a star pattern
void star_pattern(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == n - j - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int width, height, num_stars;

    // Get user input for canvas size and number of stars
    printf("Enter canvas width: ");
    scanf("%d", &width);
    printf("Enter canvas height: ");
    scanf("%d", &height);
    printf("Enter number of stars: ");
    scanf("%d", &num_stars);

    // Create a star pattern in the center of the canvas
    int center_x = width / 2;
    int center_y = height / 2;
    int star_size = (width < height)? width : height;
    for (int i = 0; i < num_stars; i++) {
        int x = rand_range(center_x - star_size / 2, center_x + star_size / 2);
        int y = rand_range(center_y - star_size / 2, center_y + star_size / 2);
        printf("*");
    }

    // Print the star pattern to the console
    star_pattern(width);

    return 0;
}
//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int image[100][100];
    int width, height, numChanges;
    char puzzle[200];

    // Prompt user for image dimensions
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    // Prompt user for number of changes to make
    printf("How many changes would you like to make to the image? ");
    scanf("%d", &numChanges);

    // Loop through the image and set initial values
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] = 0;
        }
    }

    // Prompt user for puzzle message
    printf("Enter a puzzle message (up to 200 characters): ");
    scanf("%s", &puzzle);

    // Loop through the puzzle message and update image values accordingly
    for(int i=0; i<numChanges; i++) {
        int x = (int) puzzle[i];
        int y = (int) puzzle[i+1];

        image[x%height][y%width] = image[x%height][y%width] + 1;

        if(x%2 == 0) {
            image[y%height][x%width] = image[y%height][x%width] + 2; 
        } else {
            image[(x+y)%height][(x+y)%width] = image[(x+y)%height][(x+y)%width] + 3;
        }
    }

    // Print out final image values
    printf("Final image values:\n\n");

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
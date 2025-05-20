//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100

int main() {
    char image[HEIGHT][WIDTH];
    int x, y, choice;

    printf("Welcome to the Medieval Image Editor!\n");
    printf("Enter 1 to draw a pixel, 2 to erase a pixel, 3 to save the image, or 4 to exit.\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the x and y coordinates of the pixel to draw: ");
                scanf("%d %d", &x, &y);

                if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                    image[y][x] = 1;
                    printf("Pixel drawn at (%d, %d).\n", x, y);
                } else {
                    printf("Invalid coordinates.\n");
                }
                break;

            case 2:
                printf("Enter the x and y coordinates of the pixel to erase: ");
                scanf("%d %d", &x, &y);

                if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
                    image[y][x] = 0;
                    printf("Pixel erased at (%d, %d).\n", x, y);
                } else {
                    printf("Invalid coordinates.\n");
                }
                break;

            case 3:
                printf("Enter the filename to save the image as: ");
                char filename[100];
                scanf("%s", filename);

                FILE *file = fopen(filename, "wb");

                if (file == NULL) {
                    printf("Error: could not open file.\n");
                } else {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            fputc(image[i][j], file);
                        }
                    }

                    fclose(file);
                    printf("Image saved successfully!\n");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
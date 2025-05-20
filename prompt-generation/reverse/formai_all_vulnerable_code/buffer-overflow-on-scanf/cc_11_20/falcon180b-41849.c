//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

int main() {
    int w, h, c, x, y, k, n;
    int **image;
    FILE *fp;
    char filename[20];
    float scale;
    int choice;

    // Load image
    printf("Enter image filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error loading image.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image = (int **) malloc(h = HEIGHT * sizeof(int *));
    for (c = 0; c < HEIGHT; c++) {
        image[c] = (int *) malloc(w = WIDTH * sizeof(int));
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fread(&image[y][x], sizeof(int), 1, fp);
        }
    }
    fclose(fp);

    // Main menu
    do {
        printf("\nCyberpunk Image Processing\n");
        printf("1. Flip image\n");
        printf("2. Change brightness/contrast\n");
        printf("3. Save image\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            // Flip image
            for (y = 0; y < HEIGHT; y++) {
                for (x = 0; x < WIDTH / 2; x++) {
                    k = x;
                    image[y][x] = image[y][WIDTH - x - 1];
                    image[y][WIDTH - x - 1] = image[y][k];
                }
            }
            break;
        case 2:
            // Change brightness/contrast
            printf("Enter brightness (0-255): ");
            scanf("%d", &scale);
            for (y = 0; y < HEIGHT; y++) {
                for (x = 0; x < WIDTH; x++) {
                    image[y][x] = (int) (image[y][x] * scale / 255.0);
                }
            }
            break;
        case 3:
            // Save image
            printf("Enter output filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                printf("Error saving image.\n");
                exit(1);
            }
            for (y = 0; y < HEIGHT; y++) {
                for (x = 0; x < WIDTH; x++) {
                    fwrite(&image[y][x], sizeof(int), 1, fp);
                }
            }
            fclose(fp);
            break;
        case 4:
            // Exit
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
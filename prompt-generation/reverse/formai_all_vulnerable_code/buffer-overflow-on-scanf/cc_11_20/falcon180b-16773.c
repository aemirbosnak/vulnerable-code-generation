//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define HEIGHT 100
#define WIDTH 100

int main() {
    char image[HEIGHT][WIDTH];
    int x = 0, y = 0;
    int color = 0;
    int choice;
    bool done = false;
    srand(time(NULL));

    do {
        system("clear");
        printf("Enter your choice:\n");
        printf("1. Draw pixel\n2. Fill color\n3. Save image\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter x and y coordinates: ");
                scanf("%d%d", &x, &y);
                printf("Enter color (0-15): ");
                scanf("%d", &color);
                image[y][x] = color;
                break;
            case 2:
                printf("Enter color (0-15): ");
                scanf("%d", &color);
                for (int i = 0; i < HEIGHT; i++) {
                    for (int j = 0; j < WIDTH; j++) {
                        if (image[i][j] == 0) {
                            image[i][j] = color;
                        }
                    }
                }
                break;
            case 3:
                printf("Enter filename: ");
                char filename[100];
                scanf("%s", filename);
                FILE *fp = fopen(filename, "wb");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                } else {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            fprintf(fp, "%d ", image[i][j]);
                        }
                        fprintf(fp, "\n");
                    }
                    fclose(fp);
                    printf("Image saved successfully.\n");
                }
                break;
            case 4:
                done = true;
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (!done);

    return 0;
}
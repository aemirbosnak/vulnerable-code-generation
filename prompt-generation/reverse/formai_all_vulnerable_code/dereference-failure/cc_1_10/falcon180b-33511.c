//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_colors = 10;
    int *colors = malloc(num_colors * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < num_colors; i++) {
        colors[i] = rand() % 256;
    }

    printf("Color code converter\n\n");

    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Convert RGB to hex\n");
        printf("2. Convert hex to RGB\n");
        printf("3. Generate random color\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int r, g, b;
            printf("Enter RGB values: ");
            scanf("%d %d %d", &r, &g, &b);

            int hex = (r << 16) | (g << 8) | b;
            printf("Hex code: %06X\n", hex);
        } else if (choice == 2) {
            char hex[7];
            printf("Enter hex code: ");
            scanf("%s", hex);

            int r = hex[0] << 4 | hex[1] >> 4;
            int g = hex[2] << 4 | hex[3] >> 4;
            int b = hex[4] << 4 | hex[5] >> 4;

            printf("RGB values: %d %d %d\n", r, g, b);
        } else if (choice == 3) {
            int index = rand() % num_colors;
            int r = colors[index] >> 16;
            int g = (colors[index] >> 8) & 0xFF;
            int b = colors[index] & 0xFF;

            printf("Random color: %d %d %d\n", r, g, b);
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
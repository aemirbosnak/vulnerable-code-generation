//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define PI 3.14159265358979323846

int main() {

    int i, j, k, n, x, y, z, c;
    int x1, y1, z1, x2, y2, z2, x3, y3, z3;
    int r, g, b;
    char filename[20];

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    fseek(fp, 54, SEEK_SET); // skip header
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            fread(&r, 1, 1, fp);
            fread(&g, 1, 1, fp);
            fread(&b, 1, 1, fp);

            x = i * (256 / SIZE);
            y = j * (256 / SIZE);
            z = (int)sqrt(x*x + y*y);
            c = (int)sqrt(x*x + y*y + z*z);

            if (c > 0) {
                n = (int)(255 * c / (c + 1));
                x1 = x * n / 256;
                y1 = y * n / 256;
                z1 = z * n / 256;

                x2 = x1 + (256 - x1) / 2;
                y2 = y1 + (256 - y1) / 2;
                z2 = z1 + (256 - z1) / 2;

                x3 = x2 + (256 - x2) / 2;
                y3 = y2 + (256 - y2) / 2;
                z3 = z2 + (256 - z2) / 2;

                printf("SetPixel(%d, %d, %d, %d, %d, %d);\n", x1, y1, z1, r, g, b);
                printf("SetPixel(%d, %d, %d, %d, %d, %d);\n", x2, y2, z2, r, g, b);
                printf("SetPixel(%d, %d, %d, %d, %d, %d);\n", x3, y3, z3, r, g, b);
            }
        }
    }

    fclose(fp);
    printf("Done.\n");

    return 0;
}
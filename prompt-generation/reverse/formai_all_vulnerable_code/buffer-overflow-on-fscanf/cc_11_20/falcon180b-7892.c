//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

int main() {
    int i, j, n;
    double x, y, dx, dy;
    char filename[50];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (fscanf(fp, "%lf %lf", &x, &y)!= 2) {
                printf("Error: invalid input.\n");
                exit(1);
            }

            dx = (x - 0) / (double) SIZE * (double) SIZE;
            dy = (y - 0) / (double) SIZE * (double) SIZE;

            if (dx < 0) {
                dx = 0;
            } else if (dx > SIZE - 1) {
                dx = SIZE - 1;
            }

            if (dy < 0) {
                dy = 0;
            } else if (dy > SIZE - 1) {
                dy = SIZE - 1;
            }

            n = dy * SIZE + dx;

            if (n >= 0 && n < SIZE * SIZE) {
                printf("%.2lf ", (double) n / (double) SIZE * (double) SIZE);
            } else {
                printf("-1 ");
            }
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}
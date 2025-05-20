//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    int rows, cols, i, j, k, l, count = 0;
    char **matrix;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    fseek(fp, 0L, SEEK_END);
    rows = ftell(fp) / 3;
    rewind(fp);

    fread(&cols, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);

    matrix = (char **) malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (char *) malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            fread(&ch, sizeof(char), 1, fp);
            matrix[i][j] = ch;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                for (k = 0; k < 8; k++) {
                    printf("  ");
                }
            } else {
                for (k = 0; k < 8; k++) {
                    if ((matrix[i][j] & (1 << k))!= 0) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    fclose(fp);

    return 0;
}
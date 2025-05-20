//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 120
#define HEIGHT 50

void print_matrix(char matrix[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int count = 0;
    char matrix[HEIGHT][WIDTH] = {0};

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (count >= HEIGHT * WIDTH) {
            break;
        }
        if (isprint(ch)) {
            matrix[count / WIDTH][count % WIDTH] = ch;
            count++;
        }
    }

    fclose(fp);

    print_matrix(matrix);

    return 0;
}
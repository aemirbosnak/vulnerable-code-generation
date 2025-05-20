//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 50
#define CHAR_SET_SIZE 96

char char_set[CHAR_SET_SIZE] = ".,:;=+*#@%^&!<>-?/~`[]{}()|\\";

void print_char(int x, int y, char c) {
    if (x >= 0 && y >= 0 && x < MAX_WIDTH && y < MAX_HEIGHT) {
        printf("%c", c);
    }
}

void print_row(int y, int *data) {
    int x = 0;
    while (x < MAX_WIDTH) {
        int index = data[y * MAX_WIDTH + x] % CHAR_SET_SIZE;
        print_char(x, y, char_set[index]);
        x++;
    }
}

void print_image(int *data) {
    int y = 0;
    while (y < MAX_HEIGHT) {
        print_row(y, data);
        printf("\n");
        y++;
    }
}

int main() {
    FILE *fp;
    char filename[100];
    int width, height, i, j;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // skip header
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    int *data = (int *)malloc(width * height * sizeof(int));
    if (data == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int value;
            fread(&value, sizeof(int), 1, fp);
            data[i * width + j] = value;
        }
    }

    fclose(fp);

    print_image(data);

    free(data);
    return 0;
}
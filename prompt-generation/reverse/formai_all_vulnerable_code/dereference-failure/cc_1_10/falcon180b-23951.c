//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

void print_art(char art[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *buffer = malloc(filesize);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    int count = 0;
    char art[HEIGHT][WIDTH] = {0};

    for (int i = 0; i < filesize; i++) {
        if (buffer[i]!= 0) {
            art[count / WIDTH][count % WIDTH] = buffer[i];
            count++;
        }
    }

    print_art(art);

    free(buffer);
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ascii_art(char *image_path, char *output_file) {
    FILE *fp = fopen(output_file, "w");
    if (fp == NULL) {
        printf("Error opening output file!\n");
        return;
    }

    FILE *fp2 = fopen(image_path, "r");
    if (fp2 == NULL) {
        printf("Error opening input file!\n");
        fclose(fp);
        return;
    }

    char buffer[10000];
    int width, height, i, j, k;
    int red, green, blue;

    fscanf(fp2, "%d %d", &width, &height);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(fp2, "%d %d %d", &red, &green, &blue);
            sprintf(buffer, "\x1B[38;5;%dm\x1B[48;5;%dm\x1B[38;5;%dm\x1B[0m", red, green, blue);
            fputs(buffer, fp);
        }
        fputc('\n', fp);
    }

    fclose(fp2);
    fclose(fp);
}

int main() {
    char image_path[100];
    char output_file[100];

    printf("Enter the path of the image file: ");
    fgets(image_path, sizeof(image_path), stdin);
    image_path[strcspn(image_path, "\n")] = 0;

    printf("Enter the name of the output file: ");
    fgets(output_file, sizeof(output_file), stdin);
    output_file[strcspn(output_file, "\n")] = 0;

    ascii_art(image_path, output_file);

    return 0;
}
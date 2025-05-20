//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25

char *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(filesize);
    if (!data) {
        fprintf(stderr, "Error: Could not allocate memory for image data.\n");
        exit(1);
    }

    if (fread(data, 1, filesize, fp)!= filesize) {
        fprintf(stderr, "Error: Could not read image data.\n");
        exit(1);
    }

    fclose(fp);
    return data;
}

void print_ascii_art(const char *data, int x, int y) {
    for (int i = 0; i < strlen(data); i++) {
        char c = toupper(data[i]);
        if (c >= 'A' && c <= 'Z') {
            printf("%c", c);
        } else {
            printf(" ");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <image_file> <output_file>\n", argv[0]);
        exit(1);
    }

    char *data = load_image(argv[1]);
    FILE *fp = fopen(argv[2], "w");
    if (!fp) {
        fprintf(stderr, "Error: Could not open output file.\n");
        exit(1);
    }

    int x = 0, y = 0;
    for (int i = 0; i < strlen(data); i += 3) {
        char r = data[i];
        char g = data[i + 1];
        char b = data[i + 2];

        int avg = (r + g + b) / 3;
        if (avg < 128) {
            fprintf(fp, " ");
        } else {
            fprintf(fp, "#");
        }

        x++;
        if (x == WIDTH) {
            x = 0;
            y++;
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    free(data);
    return 0;
}
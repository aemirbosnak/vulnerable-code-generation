//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 10
#define FILENAME "image.bin"
#define ASCII_CHARS " .:!*oe%$#@"

typedef struct {
    unsigned char r, g, b;
} pixel;

void die(const char *msg) {
    fprintf(stderr, "%s: %s\n", __FUNCTION__, msg);
    exit(1);
}

void check_file_size(FILE *fp) {
    long size;
    if (fseek(fp, 0, SEEK_END) || (size = ftell(fp)) < 0) {
        die("Error: Could not determine file size\n");
    }
    if (size != (WIDTH * HEIGHT)) {
        die("Error: Incorrect file size\n");
    }
    if (fseek(fp, 0, SEEK_SET) || fsetpos(fp, NULL)) {
        die("Error: Failed to reset file position\n");
    }
}

pixel read_pixel(FILE *fp) {
    pixel p;
    int ret;

    ret = fread(&p, sizeof(pixel), 1, fp);
    if (ret != 1) {
        die("Error: Failed to read pixel\n");
    }

    return p;
}

void print_ascii_row(const unsigned char *row, int len) {
    int i;

    for (i = 0; i < len; ++i) {
        printf("%c", ASCII_CHARS[row[i]]);
    }
    printf("\n");
}

void convert_image(const char *filename) {
    FILE *fp;
    pixel p;
    unsigned char row[WIDTH];
    int i;

    if ((fp = fopen(filename, "rb")) == NULL) {
        die("Error: Could not open file\n");
    }
    check_file_size(fp);

    for (i = 0; i < HEIGHT; ++i) {
        fread(row, WIDTH, 1, fp);
        print_ascii_row(row, WIDTH);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.bin>\n", argv[0]);
        exit(1);
    }

    convert_image(argv[1]);

    return EXIT_SUCCESS;
}
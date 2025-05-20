//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_CHARACTERS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (!data) {
        printf("Error: could not allocate memory for image data.\n");
        exit(1);
    }

    int bytes_read = fread(data, 1, filesize, fp);
    if (bytes_read!= filesize) {
        printf("Error: could not read entire image file.\n");
        exit(1);
    }

    fclose(fp);

    return (Image) {
       .width = 0,
       .height = 0,
       .data = data
    };
}

void print_ascii_art(const Image *image) {
    int width = image->width;
    int height = image->height;
    unsigned char *data = image->data;

    printf("PLAINFORMAT\n");
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int value = data[(y * width + x) * 3];

            switch (value) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("o");
                    break;
                case 3:
                    printf("O");
                    break;
                case 4:
                    printf("@");
                    break;
                case 5:
                    printf("#");
                    break;
                case 6:
                    printf("$");
                    break;
                case 7:
                    printf("%");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Image image = load_image("romeo_and_juliet.png");

    if (image.width > MAX_WIDTH || image.height > MAX_HEIGHT) {
        printf("Error: image is too large to display.\n");
        exit(1);
    }

    print_ascii_art(&image);

    free(image.data);
    return 0;
}
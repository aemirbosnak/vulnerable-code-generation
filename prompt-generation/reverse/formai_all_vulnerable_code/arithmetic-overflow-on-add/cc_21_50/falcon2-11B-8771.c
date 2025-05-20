//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/time.h>

#define PIXEL_SIZE 4

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

int main(int argc, char *argv[]) {
    Image img;
    int f, x1, y1, x2, y2, w, h;
    char buf[BUFSIZ], *filename;

    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    f = open(filename, O_RDONLY);
    if (f < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    img.width = img.height = 0;
    img.data = NULL;

    read(f, &img.width, sizeof(img.width));
    read(f, &img.height, sizeof(img.height));
    read(f, &img.data, img.width * img.height * PIXEL_SIZE);

    close(f);

    printf("Image: %dx%d\n", img.width, img.height);

    f = open(filename, O_RDONLY);
    if (f < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    memcpy(img.data, mmap(NULL, img.width * img.height * PIXEL_SIZE, PROT_READ, MAP_SHARED, f, 0), img.width * img.height * PIXEL_SIZE);

    close(f);

    f = open(filename, O_RDONLY);
    if (f < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(f, &x1, sizeof(x1));
    read(f, &y1, sizeof(y1));
    read(f, &x2, sizeof(x2));
    read(f, &y2, sizeof(y2));

    if (x1 >= img.width || y1 >= img.height || x2 >= img.width || y2 >= img.height) {
        printf("Invalid cropping rectangle\n");
        exit(EXIT_FAILURE);
    }

    w = x2 - x1 + 1;
    h = y2 - y1 + 1;

    if (w <= 0 || h <= 0) {
        printf("Invalid cropping rectangle\n");
        exit(EXIT_FAILURE);
    }

    memcpy(img.data + (img.width - w) * img.height * PIXEL_SIZE, img.data + img.width * img.height * PIXEL_SIZE - (w * h) * PIXEL_SIZE, (img.width - w) * img.height * PIXEL_SIZE);

    printf("Crop: %dx%d\n", w, h);

    f = open(filename, O_RDONLY);
    if (f < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(f, &w, sizeof(w));
    read(f, &h, sizeof(h));

    if (w <= 0 || h <= 0) {
        printf("Invalid resizing dimensions\n");
        exit(EXIT_FAILURE);
    }

    img.width = w;
    img.height = h;

    if (w > img.width || h > img.height) {
        printf("Invalid resizing dimensions\n");
        exit(EXIT_FAILURE);
    }

    memset(img.data, 0, img.width * img.height * PIXEL_SIZE);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            for (int i = 0; i < PIXEL_SIZE; i++) {
                img.data[y * img.width * PIXEL_SIZE + x * PIXEL_SIZE + i] = img.data[y * img.width * PIXEL_SIZE + x * PIXEL_SIZE + i] / 4;
            }
        }
    }

    printf("Resize: %dx%d\n", w, h);

    f = open(filename, O_RDONLY);
    if (f < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(f, &img.width, sizeof(img.width));
    write(f, &img.height, sizeof(img.height));

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            for (int i = 0; i < PIXEL_SIZE; i++) {
                write(f, &img.data[y * img.width * PIXEL_SIZE + x * PIXEL_SIZE + i], sizeof(img.data[y * img.width * PIXEL_SIZE + x * PIXEL_SIZE + i]));
            }
        }
    }

    close(f);

    return 0;
}
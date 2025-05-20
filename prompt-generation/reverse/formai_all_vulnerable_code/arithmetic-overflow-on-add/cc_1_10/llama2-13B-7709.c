//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <X11/Xlib.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 24

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    struct stat stat_buf;
    if (fstat(fd, &stat_buf) == -1) {
        perror("Error stat'ing file");
        close(fd);
        return NULL;
    }

    image_t *img = malloc(sizeof(image_t));
    img->data = mmap(NULL, stat_buf.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img->data == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return NULL;
    }

    img->width = stat_buf.st_size / BPP / WIDTH;
    img->height = stat_buf.st_size / BPP / HEIGHT;

    return img;
}

void save_image(const char *filename, image_t *img) {
    int fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    if (mmap(NULL, img->width * BPP * HEIGHT, PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0) == MAP_FAILED) {
        perror("Error mmapping file");
        close(fd);
        return;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char pixel = img->data[y * WIDTH * BPP + x * BPP];
            write(fd, &pixel, 1);
        }
    }

    munmap(img->data, img->width * BPP * HEIGHT);
    close(fd);
}

void draw_line(image_t *img, int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            img->data[y * img->width * BPP + x * BPP] = 255;
        }
    }
}

void draw_rectangle(image_t *img, int x, int y, int width, int height) {
    for (int x1 = x; x1 <= x + width; x1++) {
        for (int y1 = y; y1 <= y + height; y1++) {
            draw_line(img, x1, y1, x1 + width, y1 + height);
        }
    }
}

void draw_circle(image_t *img, int x, int y, int radius) {
    int fx = x - radius;
    int fy = y - radius;
    int sx = x + radius;
    int sy = y + radius;
    int x1, y1;

    for (x1 = fx; x1 <= sx; x1++) {
        for (y1 = fy; y1 <= sy; y1++) {
            if (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) <= radius) {
                img->data[y1 * img->width * BPP + x1 * BPP] = 255;
            }
        }
    }
}

void main() {
    image_t *img = load_image("image.bmp");
    if (img == NULL) {
        printf("Error loading image\n");
        return;
    }

    draw_rectangle(img, 100, 100, 200, 100);
    draw_circle(img, 250, 250, 50);

    save_image("output.bmp", img);

    munmap(img->data, img->width * BPP * HEIGHT);
}
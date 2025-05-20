//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32
#define IMAGE_SIZE (WIDTH * HEIGHT * BPP / 8)

typedef struct {
    unsigned char *data;
    int width, height, bpp;
} image_t;

image_t *load_image(const char *file_name) {
    image_t *image = malloc(sizeof(image_t));
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    image->width = file_stat.st_size / (WIDTH * BPP / 8);
    image->height = file_stat.st_size / (HEIGHT * BPP / 8);
    image->bpp = BPP;

    image->data = mmap(NULL, IMAGE_SIZE, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (image->data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return NULL;
    }

    close(fd);
    return image;
}

void save_image(const char *file_name, image_t *image) {
    int fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if (fd == -1) {
        perror("open");
        return;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        perror("fstat");
        close(fd);
        return;
    }

    if (file_stat.st_size != 0) {
        unlink(file_name);
    }

    write(fd, image->data, IMAGE_SIZE);
    close(fd);
}

void draw_line(image_t *image, int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steep = abs(dy) > abs(dx);
    int x = x1;
    int y = y1;

    if (steep) {
        dy = -dy;
    }

    for (int i = 0; i < dx; i++) {
        image->data[(y * image->width + x) * image->bpp / 8] = color;
        x++;
    }

    for (int i = 0; i < dy; i++) {
        image->data[(y * image->width + x) * image->bpp / 8] = color;
        y++;
    }
}

void draw_rectangle(image_t *image, int x, int y, int width, int height, int color) {
    draw_line(image, x, y, x + width, y, color);
    draw_line(image, x, y + height, x + width, y + height, color);
    draw_line(image, x, y, x, y + height, color);
    draw_line(image, x + width, y, x + width, y + height, color);
}

void draw_circle(image_t *image, int x, int y, int radius, int color) {
    int fx = x - radius;
    int fy = y - radius;
    int dx = x + radius;
    int dy = y + radius;
    int x1 = fx < 0 ? 0 : fx > dx ? dx : fx;
    int y1 = fy < 0 ? 0 : fy > dy ? dy : fy;
    int x2 = x1 + 1;
    int y2 = y1 + 1;

    draw_line(image, x1, y1, x2, y2, color);
    draw_line(image, x2, y1, x1, y2, color);
    draw_line(image, x1, y2, x2, y1, color);
    draw_line(image, x2, y2, x1, y1, color);
}

int main() {
    image_t *image = load_image("example.bmp");
    if (image == NULL) {
        perror("load_image");
        return 1;
    }

    draw_rectangle(image, 100, 100, 200, 100, 0xFF0000);
    draw_circle(image, 250, 250, 50, 0x00FF00);

    save_image("output.bmp", image);

    return 0;
}
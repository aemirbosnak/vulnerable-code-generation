//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define IMAGE_SIZE 1024
#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    struct stat stat_info;
    fstat(fd, &stat_info);
    char *image_data = mmap(NULL, stat_info.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    close(fd);
    image_t *image = (image_t *)calloc(1, sizeof(image_t));
    image->data = image_data;
    image->width = stat_info.st_size / WINDOW_WIDTH;
    image->height = stat_info.st_size / WINDOW_HEIGHT;
    return image;
}

void edit_image(image_t *image, int x, int y, int width, int height) {
    char *data = image->data;
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            if (i >= image->height || j >= image->width) {
                data[j * WINDOW_WIDTH + i] = 0;
            } else if (j < image->width && i < image->height) {
                data[j * WINDOW_WIDTH + i] = 'A' + (rand() % 26);
            }
        }
    }
}

void save_image(image_t *image, const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR, 0644);
    munmap(image->data, image->width * image->height * WINDOW_WIDTH);
    char *new_data = mmap(NULL, image->width * image->height * WINDOW_WIDTH, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    memcpy(new_data, image->data, image->width * image->height * WINDOW_WIDTH);
    close(fd);
    image->data = new_data;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <image_file> <edit_x> <edit_y> <edit_width> <edit_height>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    int width = atoi(argv[4]);
    int height = atoi(argv[5]);

    edit_image(image, x, y, width, height);

    save_image(image, argv[1]);

    return 0;
}
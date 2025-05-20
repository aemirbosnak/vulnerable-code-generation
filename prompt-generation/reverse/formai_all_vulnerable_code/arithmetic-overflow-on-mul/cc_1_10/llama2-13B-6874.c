//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32
#define IMAGE_PATH "image.ppm"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    struct stat stat_info;
    fstat(fd, &stat_info);

    image_t *image = (image_t *)calloc(1, sizeof(image_t));
    image->width = stat_info.st_size / WIDTH * BPP;
    image->height = stat_info.st_size / HEIGHT;

    unsigned char *data = (unsigned char *)mmap(NULL, stat_info.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        perror("Error mmapping file");
        return NULL;
    }

    image->data = data;
    close(fd);

    return image;
}

void save_image(image_t *image, const char *path) {
    int fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    struct stat stat_info;
    fstat(fd, &stat_info);

    unsigned char *data = image->data;
    int bytes_written = write(fd, data, image->width * BPP * image->height);
    if (bytes_written != image->width * BPP * image->height) {
        perror("Error writing to file");
        close(fd);
        return;
    }

    close(fd);
}

void edit_image(image_t *image) {
    int x = 0, y = 0;
    char command = 0;

    while (1) {
        printf("Current position: (%d, %d)\n", x, y);

        command = getchar();

        switch (command) {
            case 'a':
                x -= 10;
                break;
            case 'A':
                x += 10;
                break;
            case 'd':
                y -= 10;
                break;
            case 'D':
                y += 10;
                break;
            case 'w':
                x += 10;
                break;
            case 'W':
                y += 10;
                break;
            case 'q':
                return;
            case 'Q':
                break;
            default:
                printf("Invalid command\n");
        }

        image->data[y * image->width * BPP + x * BPP] = (image->data[y * image->width * BPP + x * BPP] & 0x00ff0000) |
                                                          (image->data[y * image->width * BPP + x * BPP] & 0x0000ff00) |
                                                          (image->data[y * image->width * BPP + x * BPP] & 0x000000ff) << 16;
    }
}

int main() {
    image_t *image = load_image(IMAGE_PATH);
    if (image == NULL) {
        perror("Error loading image");
        return 1;
    }

    edit_image(image);

    save_image(image, "output.ppm");

    return 0;
}
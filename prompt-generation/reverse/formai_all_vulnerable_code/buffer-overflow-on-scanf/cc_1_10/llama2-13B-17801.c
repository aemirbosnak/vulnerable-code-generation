//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 32

typedef struct {
    unsigned char *data;
    int width, height;
} image_t;

image_t *load_image(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return NULL;
    }

    struct stat sb;
    fstat(fd, &sb);

    image_t *img = malloc(sizeof(image_t));
    img->data = mmap(NULL, sb.st_size, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img->data == MAP_FAILED) {
        perror("Failed to mmap");
        close(fd);
        return NULL;
    }

    img->width = WIDTH;
    img->height = HEIGHT;

    return img;
}

void edit_image(image_t *img, int x, int y, int color) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        printf("Invalid coordinates\n");
        return;
    }

    // Calculate the pixel index
    int index = (y * img->width + x) * BPP;

    // Set the pixel color
    img->data[index] = color;

    // Update the modified pixel
    img->data[index + 1] = (color & 0x000000FF) >> 0;
    img->data[index + 2] = (color & 0x0000FF00) >> 8;
    img->data[index + 3] = (color & 0x00FF0000) >> 16;
}

void save_image(image_t *img, const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        return;
    }

    struct stat sb;
    fstat(fd, &sb);

    // Calculate the size of the image data
    size_t data_size = img->width * img->height * BPP;

    // Mmap the image data
    img->data = mmap(NULL, data_size, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    if (img->data == MAP_FAILED) {
        perror("Failed to mmap");
        close(fd);
        return;
    }

    // Close the file descriptor
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <image_file> <new_color>\n", argv[0]);
        return 1;
    }

    image_t *img = load_image(argv[1]);
    if (img == NULL) {
        printf("Failed to load image\n");
        return 2;
    }

    int x, y;
    int color = atoi(argv[2]);

    printf("Edit image...\n");

    while (1) {
        printf("Enter coordinates (x, y): ");
        scanf("%d%d", &x, &y);

        edit_image(img, x, y, color);

        printf("Modified pixel: (%d, %d) = %08x\n", x, y, img->data[y * img->width + x] << 24);

        // Exit on EOF
        if (getchar() == EOF) {
            break;
        }
    }

    save_image(img, argv[1]);

    return 0;
}
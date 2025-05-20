//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 240
#define MAX_PIXEL_VALUE 255

/* grayscale ASCII characters */
static char ascii_characters[] = {'@','#','B','%','&','W','M','$','k','d','h','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','|','(',')','1','{','}','[',']','?','-','_','+',':',';',',','.',' '};

/* map a pixel value (0-255) to ASCII character based on brightness */
static char map_pixel_to_ascii(uint8_t pixel_value) {
    int character_index = (((float)pixel_value / MAX_PIXEL_VALUE) * (sizeof(ascii_characters) / sizeof(char))) - 1;
    return ascii_characters[character_index];
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: image_to_ascii_converter <input_image>\n");
        return 1;
    }

    char *input_image_filename = argv[1];
    struct stat input_image_stat;

    if (stat(input_image_filename, &input_image_stat) == -1) {
        printf("Could not open input image file: %s\n", strerror(errno));
        return 1;
    }

    uint8_t *image_data = mmap(NULL, input_image_stat.st_size, PROT_READ, MAP_PRIVATE, open(input_image_filename, O_RDONLY), 0);
    if (image_data == MAP_FAILED) {
        printf("Could not map input image to memory: %s\n", strerror(errno));
        return 1;
    }

    printf("Original Image:\n");
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int pixel_value = image_data[(y * IMAGE_WIDTH) + x];
            printf("%c", map_pixel_to_ascii(pixel_value));
        }
        printf("\n");
    }
    printf("\n");

    pid_t pid = fork();

    if (pid == -1) {
        printf("Could not fork process: %s\n", strerror(errno));
        return 1;
    }

    if (pid == 0) { /* child process */
        printf("Inverting Image...\n");
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            for (int x = 0; x < IMAGE_WIDTH; x++) {
                int pixel_value = image_data[(y * IMAGE_WIDTH) + x];
                image_data[(y * IMAGE_WIDTH) + x] = MAX_PIXEL_VALUE - pixel_value;
            }
        }
        sleep(3);
        exit(0);
    } else { /* parent process */
        printf("Original Image:\n");
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            for (int x = 0; x < IMAGE_WIDTH; x++) {
                int pixel_value = image_data[(y * IMAGE_WIDTH) + x];
                printf("%c", map_pixel_to_ascii(pixel_value));
            }
            printf("\n");
        }
        printf("\n");

        int status;
        wait(&status);

        printf("Inverted Image:\n");
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            for (int x = 0; x < IMAGE_WIDTH; x++) {
                int pixel_value = image_data[(y * IMAGE_WIDTH) + x];
                printf("%c", map_pixel_to_ascii(pixel_value));
            }
            printf("\n");
        }
        printf("\n");

        if (munmap(image_data, input_image_stat.st_size) == -1) {
            printf("Could not unmap image data: %s\n", strerror(errno));
            return 1;
        }

        return 0;
    }
}
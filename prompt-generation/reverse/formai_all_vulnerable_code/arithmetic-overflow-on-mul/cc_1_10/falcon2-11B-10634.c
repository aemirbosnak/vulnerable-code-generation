//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PIXEL_SIZE 3

typedef struct {
    int x;
    int y;
    char color;
} Pixel;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }

    int fd_input = open(argv[1], O_RDONLY);
    int fd_output = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd_input == -1 || fd_output == -1) {
        perror("Error opening file");
        return 1;
    }

    int image_width = 0;
    int image_height = 0;
    int pixel_size = 0;
    char color_mode = 0;

    fseek(fd_input, 0, SEEK_END);
    image_width = ftell(fd_input);
    fseek(fd_input, 0, SEEK_SET);
    image_height = ftell(fd_input);
    fseek(fd_input, 0, SEEK_END);
    pixel_size = ftell(fd_input);
    fseek(fd_input, 0, SEEK_SET);
    color_mode = getc(fd_input);

    Pixel *image = (Pixel *) malloc(image_width * image_height * PIXEL_SIZE);

    for (int i = 0; i < image_width * image_height * PIXEL_SIZE; i++) {
        fread(&image[i], PIXEL_SIZE, 1, fd_input);
    }

    fclose(fd_input);

    fwrite(&image_width, sizeof(int), 1, fd_output);
    fwrite(&image_height, sizeof(int), 1, fd_output);
    fwrite(&pixel_size, sizeof(int), 1, fd_output);
    fwrite(&color_mode, sizeof(char), 1, fd_output);

    for (int i = 0; i < image_width * image_height; i++) {
        fwrite(&image[i], PIXEL_SIZE, 1, fd_output);
    }

    fclose(fd_output);

    free(image);

    return 0;
}
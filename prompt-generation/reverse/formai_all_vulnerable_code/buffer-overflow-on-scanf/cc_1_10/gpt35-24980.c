//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_COMMAND_LENGTH 10
#define MAX_PIXEL_VALUE 255
#define MAX_COLOR_CHANNELS 3

typedef struct {
    int width;
    int height;
    int max_pixel_value;
    int (*pixels)[MAX_COLOR_CHANNELS];
} Image;

void read_image(char filename[], Image *img) {
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Failed to open file %s", filename);
        exit(1);
    }

    char format[3];
    fscanf(input_file, "%s\n", format);
    if (strcmp(format, "P3") != 0) {
        printf("Invalid file format. Expected P3");
        exit(1);
    }

    fscanf(input_file, "%d %d\n", &img->width, &img->height);
    fscanf(input_file, "%d\n", &img->max_pixel_value);
    if (img->max_pixel_value != MAX_PIXEL_VALUE) {
        printf("Invalid max pixel value. Expected %d", MAX_PIXEL_VALUE);
        exit(1);
    }

    img->pixels = malloc(img->height * img->width * sizeof(int));
    for (int i = 0; i < img->height * img->width; i++) {
        fscanf(input_file, "%d %d %d", &img->pixels[i][0], &img->pixels[i][1], &img->pixels[i][2]);
    }

    fclose(input_file);
}

void write_image(char filename[], Image *img) {
    FILE *output_file = fopen(filename, "w");
    if (output_file == NULL) {
        printf("Failed to open file %s", filename);
        exit(1);
    }

    fprintf(output_file, "P3\n");
    fprintf(output_file, "%d %d\n", img->width, img->height);
    fprintf(output_file, "%d\n", img->max_pixel_value);
    for (int i = 0; i < img->height * img->width; i++) {
        fprintf(output_file, "%d %d %d\n", img->pixels[i][0], img->pixels[i][1], img->pixels[i][2]);
    }

    fclose(output_file);
}

void negate_image(Image *img) {
    for (int i = 0; i < img->height * img->width; i++) {
        for (int j = 0; j < MAX_COLOR_CHANNELS; j++) {
            img->pixels[i][j] = MAX_PIXEL_VALUE - img->pixels[i][j];
        }
    }
}

void grayscale_image(Image *img) {
    for (int i = 0; i < img->height * img->width; i++) {
        int average = (img->pixels[i][0] + img->pixels[i][1] + img->pixels[i][2]) / 3;
        img->pixels[i][0] = average;
        img->pixels[i][1] = average;
        img->pixels[i][2] = average;
    }
}

int validate_command(char command[]) {
    if (strcmp(command, "negate") == 0 || strcmp(command, "grayscale") == 0) {
        return 1;
    }
    return 0;
}

void apply_command(char command[], Image *img) {
    if (strcmp(command, "negate") == 0) {
        negate_image(img);
    } else if (strcmp(command, "grayscale") == 0) {
        grayscale_image(img);
    }
}

int main() {
    char input_filename[MAX_FILENAME_LENGTH], output_filename[MAX_FILENAME_LENGTH];

    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    Image img;
    read_image(input_filename, &img);

    char command[MAX_COMMAND_LENGTH];
    printf("Enter command (negate or grayscale): ");
    scanf("%s", command);
    while (!validate_command(command)) {
        printf("Invalid command. Enter command (negate or grayscale): ");
        scanf("%s", command);
    }

    apply_command(command, &img);
    write_image(output_filename, &img);

    printf("Image successfully processed and saved as %s", output_filename);

    return 0;
}
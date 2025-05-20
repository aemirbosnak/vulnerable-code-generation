//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
    char input_file[100];
    char output_file[100];
    FILE *in_file, *out_file;
    int width, height, i, j, k, x, y, pixel, gray_level;
    unsigned char *image_data;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the name of the input image file: ");
    scanf("%s", input_file);

    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(in_file, 0, SEEK_END);
    size_t file_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    image_data = (unsigned char *) malloc(file_size);
    if (image_data == NULL) {
        printf("Error: Could not allocate memory for image data.\n");
        exit(1);
    }

    fread(image_data, file_size, 1, in_file);
    fclose(in_file);

    width = *(int *) image_data;
    height = *(int *) (image_data + 4);

    printf("Enter the name of the output ASCII art file: ");
    scanf("%s", output_file);

    out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    start_time = time(NULL);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = *(int *) (image_data + 8 + i * width + j * 3);
            gray_level = (pixel >> 16) & 0xff;

            if (gray_level < 128) {
                fprintf(out_file, " ");
            } else {
                fprintf(out_file, "*");
            }
        }

        fprintf(out_file, "\n");
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("ASCII art generated successfully.\n");
    printf("Elapsed time: %.2lf seconds.\n", elapsed_time);

    fclose(out_file);
    free(image_data);

    return 0;
}
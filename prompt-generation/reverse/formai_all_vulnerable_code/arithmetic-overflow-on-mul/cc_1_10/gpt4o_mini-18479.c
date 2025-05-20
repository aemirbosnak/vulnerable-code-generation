//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <jpeglib.h>

#define ASCII_CHARS "@%#*+=-:. " // Characters from dark to light
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    unsigned char *image_buffer;
    int width;
    int height;
    int start_row;
    int end_row;
    char *ascii_art;
} ThreadData;

void *convert_to_ascii(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char *ascii_characters = ASCII_CHARS;
    const int num_chars = strlen(ascii_characters);
    int pixel, ascii_index;

    for (int y = data->start_row; y < data->end_row; y++) {
        for (int x = 0; x < data->width; x++) {
            pixel = data->image_buffer[(y * data->width + x) * 3]; // Grayscale
            ascii_index = (pixel * (num_chars - 1)) / 255; // Map to ASCII
            data->ascii_art[y * data->width + x] = ascii_characters[ascii_index];
        }
    }
    pthread_exit(0);
}

void read_jpeg_file(const char *filename, unsigned char **image_buffer, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening jpeg file %s!\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int row_stride = cinfo.output_width * cinfo.output_components;

    *image_buffer = (unsigned char *)malloc(row_stride * cinfo.output_height);
    unsigned char *buffer_array[row_stride];

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer = buffer_array[cinfo.output_scanline % row_stride];
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        memcpy(*image_buffer + (cinfo.output_scanline - 1) * row_stride, buffer, row_stride);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

void write_ascii_art(const char *filename, const char *ascii_art, int width, int height) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening output file %s!\n", filename);
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fputc(ascii_art[i * width + j], file);
        }
        fputc('\n', file);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image.jpg> <output_ascii.txt>\n", argv[0]);
        exit(1);
    }

    unsigned char *image_buffer;
    int width, height;

    read_jpeg_file(argv[1], &image_buffer, &width, &height);
    char *ascii_art = (char *)malloc(width * height * sizeof(char));

    pthread_t threads[4];
    ThreadData thread_data[4];
    int rows_per_thread = height / 4;

    for (int i = 0; i < 4; i++) {
        thread_data[i].image_buffer = image_buffer;
        thread_data[i].width = width;
        thread_data[i].height = height;
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i == 3) ? height : (i + 1) * rows_per_thread;
        thread_data[i].ascii_art = ascii_art;
        pthread_create(&threads[i], NULL, convert_to_ascii, &thread_data[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    write_ascii_art(argv[2], ascii_art, width, height);
    
    free(image_buffer);
    free(ascii_art);

    printf("ASCII art created successfully in %s\n", argv[2]);
    return 0;
}
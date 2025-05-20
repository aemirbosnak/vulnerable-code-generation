//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <jpeglib.h> // For JPEG images
#include <stdint.h>

#define ASCII_CHARS "@%#*+=-:. " // Characters used for ASCII art
#define MAX_THREADS 4

typedef struct {
    unsigned char *image_buffer;
    int width;
    int height;
    int start_row;
    int end_row;
} ThreadData;

void *convert_to_ascii(void *arg);
void load_image(const char *filename, unsigned char **image_buffer, int *width, int *height);
void save_ascii(const char *filename, const char *ascii_art, int width, int height);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }

    unsigned char *image_buffer = NULL;
    int width, height;
    load_image(argv[1], &image_buffer, &width, &height);

    if (image_buffer == NULL) {
        fprintf(stderr, "Failed to load image.\n");
        return 1;
    }

    char *ascii_art = malloc((width + 1) * height); // +1 for null terminator
    ascii_art[0] = '\0'; // Initialize ASCII art string

    // Creating threads
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    int rows_per_thread = height / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].image_buffer = image_buffer;
        thread_data[i].width = width;
        thread_data[i].height = height;
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i == MAX_THREADS - 1) ? height : (i + 1) * rows_per_thread;

        pthread_create(&threads[i], NULL, convert_to_ascii, &thread_data[i]);
    }

    // Joining threads and collecting ASCII art
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        strncat(ascii_art, (const char *)thread_data[i].image_buffer + thread_data[i].start_row * width, (thread_data[i].end_row - thread_data[i].start_row) * width);
    }

    save_ascii(argv[2], ascii_art, width, height);
    free(image_buffer);
    free(ascii_art);
    return 0;
}

void *convert_to_ascii(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    unsigned char *image_buffer = data->image_buffer;
    int width = data->width;
    int height = data->height;

    char *ascii_chunk = malloc((width + 1) * (data->end_row - data->start_row) + 1);
    ascii_chunk[0] = '\0'; // Initialize ASCII chunk string

    for (int y = data->start_row; y < data->end_row; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * 3; // Assuming RGB
            unsigned char r = image_buffer[pixel_index];
            unsigned char g = image_buffer[pixel_index + 1];
            unsigned char b = image_buffer[pixel_index + 2];
            int gray = (r + g + b) / 3; // Convert to grayscale
            char ascii_char = ASCII_CHARS[gray * (strlen(ASCII_CHARS) - 1) / 255];
            ascii_chunk[y * width + x] = ascii_char;
        }
        ascii_chunk[(y - data->start_row + 1) * width] = '\0'; // Null-terminate each row
    }

    strncpy((char *)data->image_buffer + data->start_row * width, ascii_chunk, (data->end_row - data->start_row) * width);
    free(ascii_chunk);
    pthread_exit(NULL);
}

void load_image(const char *filename, unsigned char **image_buffer, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    *image_buffer = (unsigned char *)malloc((*width) * (*height) * 3); // RGB

    unsigned char *row_pointer[1];
    while (cinfo.output_scanline < cinfo.output_height) {
        row_pointer[0] = (*image_buffer) + (cinfo.output_scanline) * (*width) * 3;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(file);
}

void save_ascii(const char *filename, const char *ascii_art, int width, int height) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    // Save the ASCII art
    for (int i = 0; i < height; i++) {
        fwrite(ascii_art + i * width, sizeof(char), width, file);
        fputc('\n', file);
    }
    fclose(file);
}
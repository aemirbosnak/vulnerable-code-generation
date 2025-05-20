//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <jpeglib.h>

#define THREAD_COUNT 4

typedef struct {
    uint8_t *image;
    int width;
    int height;
    int start_row;
    int end_row;
    float brightness;
    float contrast;
} thread_data_t;

void *flip_image(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int row, col;

    for (row = data->start_row; row < data->end_row; row++) {
        for (col = 0; col < data->width; col++) {
            int idx = (row * data->width + col) * 3;
            int flipped_idx = (row * data->width + (data->width - 1 - col)) * 3;

            uint8_t temp[3];
            memcpy(temp, &data->image[idx], 3);
            memcpy(&data->image[idx], &data->image[flipped_idx], 3);
            memcpy(&data->image[flipped_idx], temp, 3);
        }
    }
    
    return NULL;
}

void *adjust_brightness_contrast(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int row, col;

    for (row = data->start_row; row < data->end_row; row++) {
        for (col = 0; col < data->width; col++) {
            int idx = (row * data->width + col) * 3;
            for (int i = 0; i < 3; i++) {
                int value = (int)(data->image[idx + i] * data->contrast + data->brightness);
                data->image[idx + i] = value < 0 ? 0 : (value > 255 ? 255 : value);
            }
        }
    }
    
    return NULL;
}

void process_image(uint8_t *image, int width, int height, float brightness, float contrast) {
    pthread_t threads[THREAD_COUNT];
    thread_data_t thread_data[THREAD_COUNT];
    int rows_per_thread = height / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].image = image;
        thread_data[i].width = width;
        thread_data[i].height = height;
        thread_data[i].brightness = brightness;
        thread_data[i].contrast = contrast;
        thread_data[i].start_row = i * rows_per_thread;
        thread_data[i].end_row = (i == THREAD_COUNT - 1) ? height : (i + 1) * rows_per_thread;

        pthread_create(&threads[i], NULL, flip_image, (void *)&thread_data[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, adjust_brightness_contrast, (void *)&thread_data[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <input_image.jpg> <output_image.jpg> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float brightness = atof(argv[3]);
    float contrast = atof(argv[4]);

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE * infile;

    if ((infile = fopen(input_file, "rb")) == NULL) {
        fprintf(stderr, "cannot open %s\n", input_file);
        return 1;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    uint8_t *image = (uint8_t *)malloc(width * height * 3);

    while (cinfo.output_scanline < cinfo.output_height) {
        uint8_t *row_pointer[1];
        row_pointer[0] = image + (cinfo.output_scanline) * width * 3;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    process_image(image, width, height, brightness, contrast);

    struct jpeg_compress_struct cinfo_out;
    struct jpeg_error_mgr jerr_out;
    FILE * outfile;

    if ((outfile = fopen(output_file, "wb")) == NULL) {
        fprintf(stderr, "cannot open %s\n", output_file);
        return 1;
    }

    cinfo_out.err = jpeg_std_error(&jerr_out);
    jpeg_create_compress(&cinfo_out);
    jpeg_stdio_dest(&cinfo_out, outfile);

    cinfo_out.image_width = width;
    cinfo_out.image_height = height;
    cinfo_out.input_components = 3;
    cinfo_out.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo_out);
    jpeg_start_compress(&cinfo_out, TRUE);

    while (cinfo_out.next_scanline < cinfo_out.image_height) {
        uint8_t *row_pointer[1];
        row_pointer[0] = image + (cinfo_out.next_scanline) * width * 3;
        jpeg_write_scanlines(&cinfo_out, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo_out);
    fclose(outfile);

    free(image);
    return 0;
}
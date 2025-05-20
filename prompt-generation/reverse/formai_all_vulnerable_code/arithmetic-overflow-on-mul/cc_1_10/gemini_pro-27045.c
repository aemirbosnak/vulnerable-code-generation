//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    unsigned char *data;
    size_t size;
    int width;
    int height;
} image_t;

typedef struct {
    image_t *image;
    char *message;
    int start_bit;
    int end_bit;
} thread_data_t;

void *hide_message(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    image_t *image = data->image;
    char *message = data->message;
    int start_bit = data->start_bit;
    int end_bit = data->end_bit;

    for (int i = start_bit; i < end_bit; i++) {
        if (*message == '\0') {
            break;
        }

        int bit = (*message >> (7 - (i % 8))) & 1;
        image->data[i / 8] = (image->data[i / 8] & 0xFE) | bit;
        message++;
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image file> <message> <output file>\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    size_t image_size = ftell(image_file);
    rewind(image_file);

    unsigned char *image_data = malloc(image_size);
    if (image_data == NULL) {
        perror("malloc");
        return 1;
    }

    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    image_t image;
    image.data = image_data;
    image.size = image_size;
    image.width = 0;
    image.height = 0;

    // Read BMP header
    if (image_data[0] != 'B' || image_data[1] != 'M') {
        fprintf(stderr, "Invalid BMP file\n");
        return 1;
    }

    image.width = *(int *)&image_data[18];
    image.height = *(int *)&image_data[22];

    // Calculate number of threads
    int num_threads = 8;
    int bits_per_thread = (image.width * image.height) / num_threads;

    // Create threads
    pthread_t threads[num_threads];
    thread_data_t thread_data[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].image = &image;
        thread_data[i].message = argv[2];
        thread_data[i].start_bit = i * bits_per_thread;
        thread_data[i].end_bit = (i + 1) * bits_per_thread;

        pthread_create(&threads[i], NULL, hide_message, &thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write BMP header
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        perror("fopen");
        return 1;
    }

    fwrite(image_data, 1, image_size, output_file);
    fclose(output_file);

    return 0;
}
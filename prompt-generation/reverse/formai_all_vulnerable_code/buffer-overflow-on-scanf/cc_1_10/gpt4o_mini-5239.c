//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define ASCII_CHARS "@%#*+=-:. "
#define MAX_PLAYERS 5
#define MAX_IMAGE_SIZE 1024

typedef struct {
    char *filename;
    int player_id;
} PlayerData;

void *convert_image_to_ascii(void *data) {
    PlayerData *playerData = (PlayerData *)data;
    const char *filename = playerData->filename;
    int player_id = playerData->player_id;

    int width, height;
    unsigned char *image_buffer;

    // Read JPEG file
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Player %d: Cannot open file %s\n", player_id, filename);
        return NULL;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, input_file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    width = cinfo.output_width;
    height = cinfo.output_height;
    int row_stride = width * cinfo.output_components;
    image_buffer = (unsigned char *)malloc(row_stride * height);

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = image_buffer + (cinfo.output_scanline) * row_stride;
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(input_file);

    // Convert to ASCII
    printf("Player %d: Converting %s to ASCII Art...\n", player_id, filename);
    for (int y = 0; y < height; y += (height / 20)) {  // Scale down for ASCII art
        for (int x = 0; x < width; x += (width / 40)) {
            int pixel_index = (y * width + x) * cinfo.output_components;
            unsigned char r = image_buffer[pixel_index];
            unsigned char g = image_buffer[pixel_index + 1];
            unsigned char b = image_buffer[pixel_index + 2];

            // Calculate luminance
            float gray = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            int ascii_index = (gray * (strlen(ASCII_CHARS) - 1)) / 255;
            printf("%c", ASCII_CHARS[ascii_index]);
        }
        printf("\n");
    }

    free(image_buffer);
    return NULL;
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    PlayerData players[MAX_PLAYERS];
    int player_count = 0;

    while (player_count < MAX_PLAYERS) {
        char filename[MAX_IMAGE_SIZE];
        printf("Player %d, enter the filename of the JPEG image to convert (or 'exit' to quit): ", player_count + 1);
        scanf("%s", filename);

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        players[player_count].filename = strdup(filename);
        players[player_count].player_id = player_count + 1;

        if (pthread_create(&threads[player_count], NULL, convert_image_to_ascii, (void *)&players[player_count]) != 0) {
            fprintf(stderr, "Error creating thread for Player %d\n", player_count + 1);
            free(players[player_count].filename);
            break;
        }
        player_count++;
    }

    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
        free(players[i].filename);
    }

    printf("All players finished converting images to ASCII art.\n");
    return 0;
}
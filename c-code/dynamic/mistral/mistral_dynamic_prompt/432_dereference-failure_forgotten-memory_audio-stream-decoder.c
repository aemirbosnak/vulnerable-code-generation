#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode_audio(char *data, size_t size) {
    unsigned char *frame, *ptr;
    size_t frame_size = 1024;
    frame = malloc(frame_size);

    for (int i = 0; i < size; ++i) {
        frame[i % frame_size] = data[i];
    }

    ptr = frame;

    // Simulate actual decoding
    for (int i = 0; i < frame_size; ++i) {
        printf("%c", *ptr++);
    }

    free(frame);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <audio_file_path>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 2;
    }

    fseek(fp, -1, SEEK_END);
    size_t file_size = ftell(fp) + 1;
    char *data = malloc(file_size);
    fseek(fp, 0, SEEK_SET);
    fread(data, 1, file_size, fp);
    fclose(fp);

    decode_audio(data, file_size);

    free(data);
    return 0;
}

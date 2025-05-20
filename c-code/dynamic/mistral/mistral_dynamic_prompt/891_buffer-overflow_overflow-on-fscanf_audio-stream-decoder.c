#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    int count = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        // Assuming the audio stream data is in the format: frame_size frame_data
        char frame_size_str[10];
        strncpy(frame_size_str, buffer, 9);
        int frame_size = atoi(frame_size_str);

        // Insecure buffer read, intentionally causing a buffer overflow
        char frame_data[frame_size];
        fread(frame_data, 1, frame_size, file);

        count++;
    }

    fclose(file);
    printf("Decoded %d frames\n", count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: audio_decoder <input_file>\n");
        return 1;
    }

    decode_audio(argv[1]);
    return 0;
}

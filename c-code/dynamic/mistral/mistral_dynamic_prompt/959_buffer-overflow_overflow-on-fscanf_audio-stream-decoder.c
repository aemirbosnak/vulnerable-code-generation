#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_input(char* buffer) {
    char cmd[256];

    if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
        printf("Error reading command\n");
        exit(1);
    }

    if (sscanf(cmd, "%s", buffer) != 1) {
        printf("Invalid command format\n");
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    char input[BUFFER_SIZE];
    char* audio_data;
    size_t audio_size = 0;
    int chunk_size = 1024;
    FILE* audio_file;

    if (argc != 2) {
        printf("Usage: decoder <input_file>\n");
        exit(1);
    }

    audio_file = fopen(argv[1], "rb");
    if (audio_file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    printf("Decoding audio file %s...\n", argv[1]);

    while ((fread(input, chunk_size, 1, audio_file)) == 1) {
        // INTENDED BUFFER OVERFLOW POINT
        handle_input(input + audio_size);
        audio_size += chunk_size;
    }

    fclose(audio_file);

    audio_data = (char*)malloc(audio_size);
    memmove(audio_data, input, audio_size);

    // SAVE AUDIO DATA TO A FILE OR DO SOMETHING ELSE WITH IT
    // ...

    printf("Audio decoding complete.\n");

    return 0;
}

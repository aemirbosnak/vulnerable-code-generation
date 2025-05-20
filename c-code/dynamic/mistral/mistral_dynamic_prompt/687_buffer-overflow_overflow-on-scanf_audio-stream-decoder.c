#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void play_audio_stream(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    printf("Playing audio file: %s\n", filename);

    while (1) {
        size_t bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        size_t len = strlen(buffer);

        if (fgetc(file) == EOF) break; // Check for EOF after each read

        printf("Decoding: %s\n", buffer);

        // INTENTIONALLY UNSAFE: overflow vulnerability on user input
        char input[10];
        scanf("%s", input);

        // Dummy decoding logic
        for (size_t i = 0; i < bytes_read; ++i) {
            if (buffer[i] == '0') {
                printf(" Play   ");
            } else if (buffer[i] == '1') {
                printf(" Pause ");
            }
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    play_audio_stream(argv[1]);
    return 0;
}

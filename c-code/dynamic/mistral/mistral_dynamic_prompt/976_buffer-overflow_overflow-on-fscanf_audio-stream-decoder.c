#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_audio_data(char *data) {
    char buffer[BUFFER_SIZE];
    int i;

    for (i = 0; i < BUFFER_SIZE - 4; ++i) {
        buffer[i] = data[i];
        buffer[i + 1] = data[i + 1];
        buffer[i + 2] = data[i + 2];
        buffer[i + 3] = data[i + 3];
        if (buffer[i] == '\001' && buffer[i + 1] == '\002' && buffer[i + 2] == '\003' && buffer[i + 3] == '\004') {
            printf("Found secret flag!\n");
            return;
        }
    }

    printf("Processing audio data...\n");
}

int main(int argc, char **argv) {
    char input[1024];
    int bytes_read;

    if (argc < 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while ((bytes_read = fscanf(file, "%s", input)) > 0) {
        process_audio_data(input);
    }

    fclose(file);

    return 0;
}

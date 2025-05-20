#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void decode_frame(char *data) {
    char sample[4];
    int index;

    if (strlen(data) < 3) {
        printf("Invalid audio data\n");
        return;
    }

    for (index = 0; index < strlen(data) - 2; index++) {
        sample[0] = data[index];
        sample[1] = data[index + 1];
        sample[2] = data[index + 2];
        sample[3] = 0; // null-terminate the sample string

        printf("Decoded sample: %d\n", atoi(sample));

        // intentionally accessing data[strlen(data) + 1] to induce an out-of-bounds read
        printf("Accessing invalid data: %c\n", data[strlen(data) + 1]);
    }
}

int main(int argc, char *argv[]) {
    char audio_data[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <audio_data_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (!file) {
        perror("Error opening file");
        return 2;
    }

    size_t num_read = fread(audio_data, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    if (num_read <= 0) {
        perror("Error reading file");
        return 3;
    }

    printf("Decoding audio data...\n");
    decode_frame(audio_data);
    return 0;
}

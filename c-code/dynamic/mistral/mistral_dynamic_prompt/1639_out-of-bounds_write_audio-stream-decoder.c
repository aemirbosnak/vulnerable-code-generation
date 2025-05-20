#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio_stream(char *input, char *output) {
    int i, j;
    char sample[BUFFER_SIZE];

    for (i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'W':
                for (j = 0; j < BUFFER_SIZE; j++) {
                    sample[j] = input[i + j + 1]; // Out of bounds write vulnerability
                }
                break;
            default:
                break;
        }
        strcat(output, sample);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Error opening files");
        return 2;
    }

    char input_buffer[BUFFER_SIZE];
    while (fgets(input_buffer, BUFFER_SIZE, input)) {
        decode_audio_stream(input_buffer, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}

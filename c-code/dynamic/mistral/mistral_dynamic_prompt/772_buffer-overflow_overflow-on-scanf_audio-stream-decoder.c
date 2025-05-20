#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char header[4];
    unsigned int sample_rate;
    unsigned int channels;
    unsigned int bits_per_sample;
    unsigned int data_size;
} WaveHeader;

void parse_wave(FILE *fp, WaveHeader *header) {
    fread(header, sizeof(WaveHeader), 1, fp);
    if (strncmp(header->header, "RIFF", 4) != 0) {
        fprintf(stderr, "Invalid wave file format.\n");
        exit(1);
    }
}

int main(int argc, char **argv) {
    FILE *input_file;
    WaveHeader header;
    unsigned char *data;
    size_t data_size, i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <wave_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening file");
        return 1;
    }

    parse_wave(input_file, &header);

    data_size = header.data_size;
    data = malloc(data_size);
    if (!data) {
        perror("Error allocating memory for data");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, sizeof(WaveHeader), SEEK_SET);
    fread(data, data_size, 1, input_file);

    for (i = 0; i < data_size; ++i) {
        putchar(data[i]);
    }

    free(data);
    fclose(input_file);

    return 0;
}

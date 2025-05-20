#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 18

typedef struct {
    char id[4];
    char version[4];
    char flags[4];
    char channels[2];
    char sample_rate[4];
    char bit_depth[4];
    char data_size[8];
    char extension[4];
} Header;

int main(int argc, char *argv[]) {
    FILE *file;
    Header header;
    char *data;
    int data_size;
    int i;

    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fread(&header, sizeof(Header), 1, file);

    data_size = atoi((char *)header.data_size);
    data = (char *)malloc(data_size);
    fread(data, data_size, 1, file);

    for (i = 0; i < data_size; i++) {
        data[i + HEADER_SIZE] *= 2; // Out of bounds write vulnerability
    }

    fclose(file);

    free(data);
    return 0;
}

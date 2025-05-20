//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_NAME 256

typedef struct {
    char filename[MAX_FILE_NAME];
    int size;
    int start_block;
} FileHeader;

typedef struct {
    char data[BLOCK_SIZE];
    int next_block;
} BlockHeader;

void write_file_header(FILE *fp, char *filename, int size, int start_block) {
    FileHeader header;
    strcpy(header.filename, filename);
    header.size = size;
    header.start_block = start_block;
    fwrite(&header, sizeof(header), 1, fp);
}

void write_block_header(FILE *fp, int next_block) {
    BlockHeader header;
    header.next_block = next_block;
    fwrite(&header, sizeof(header), 1, fp);
}

void read_file_header(FILE *fp, FileHeader *header) {
    fread(header, sizeof(header), 1, fp);
}

void read_block_header(FILE *fp, BlockHeader *header) {
    fread(header, sizeof(header), 1, fp);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char filename[MAX_FILE_NAME];
    int size, start_block = 0;

    while (fscanf(input, "%s %d", filename, &size)!= EOF) {
        write_file_header(output, filename, size, start_block);
        start_block += (size / BLOCK_SIZE) + ((size % BLOCK_SIZE)? 1 : 0);
    }

    rewind(input);

    char data[BLOCK_SIZE];
    int next_block = start_block;

    while (fread(data, sizeof(data), 1, input) == 1) {
        write_block_header(output, next_block);
        fwrite(data, sizeof(data), 1, output);
        next_block++;
    }

    fclose(input);
    fclose(output);

    return 0;
}
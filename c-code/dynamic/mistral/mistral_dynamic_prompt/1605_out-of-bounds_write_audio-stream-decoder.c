#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[256];
    unsigned char *data;
    int size;
    int format;
} AudioFile;

void read_file(AudioFile *file) {
    FILE *fp = fopen(file->filename, "rb");
    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    file->data = malloc(file->size);
    rewind(fp);
    fread(file->data, 1, file->size, fp);
    fclose(fp);
}

void decode_wav(AudioFile *file) {
    // WAV header magic number
    if (file->data[0] != 'R' || file->data[1] != 'I' || file->data[2] != 'F' || file->data[3] != 'F') {
        printf("Invalid file format.\n");
        return;
    }

    // Read the size of the WAVE data chunk
    int data_chunk_size = *(int*)&file->data[40];

    // Write the data from the WAVE data chunk into a buffer, overflowing the buffer
    char buffer[data_chunk_size];
    memcpy(buffer, &file->data[44], data_chunk_size);

    // Execute the overwritten code with the vulnerable line below
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <audio file>\n", argv[0]);
        return 1;
    }

    AudioFile file;
    strcpy(file.filename, argv[1]);
    read_file(&file);
    decode_wav(&file);

    free(file.data);
    return 0;
}

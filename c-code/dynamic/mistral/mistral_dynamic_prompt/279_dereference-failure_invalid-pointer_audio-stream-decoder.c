#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct AudioFile {
    char name[256];
    unsigned char* data;
    unsigned int size;
} AudioFile;

void load_audio_file(AudioFile* file, const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) {
        perror("Error opening file");
        return;
    }

    fseek(f, 0, SEEK_END);
    file->size = ftell(f);
    rewind(f);

    file->data = malloc(file->size);
    if (!file->data) {
        perror("Error allocating memory");
        return;
    }

    size_t read = fread(file->data, sizeof(unsigned char), file->size, f);
    if (read != file->size) {
        perror("Error reading file");
    }
    fclose(f);
}

unsigned int get_sample(const AudioFile* file, int index) {
    if (index >= file->size / 2) {
        // Invalid index out of bounds
        return -1;
    }

    unsigned short sample = *(unsigned short*)(file->data + index * 2);
    return sample;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    AudioFile file;
    load_audio_file(&file, argv[1]);

    int index = atoi(argv[2]);
    if (index < 0) {
        printf("Invalid index\n");
        return 1;
    }

    unsigned int sample = get_sample(&file, index);
    printf("Sample %d: %d\n", index, sample);

    free(file.data);
    return 0;
}

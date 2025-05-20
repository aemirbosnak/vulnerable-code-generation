#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[32];
    unsigned int size;
    char data[BUFFER_SIZE];
} AudioFile;

void decode(AudioFile *file) {
    FILE *fp = fopen(file->name, "r");
    fscanf(fp, "%s %u", file->data, &file->size);
    fclose(fp);

    printf("Decoded audio file:\n");
    printf("%s\n", file->data);
    printf("Size: %u bytes\n", file->size);
}

int main(int argc, char **argv) {
    AudioFile file;

    if (argc != 2) {
        printf("Usage: %s <audio_file_name>\n", argv[0]);
        return 1;
    }

    strcpy(file.name, argv[1]);
    decode(&file);

    return 0;
}

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char* data;
    size_t size;
} AudioData;

void decode(AudioData* audio) {
    unsigned char* buffer = (unsigned char*) malloc(BUFFER_SIZE);
    unsigned char* bufferEnd = buffer + BUFFER_SIZE;

    size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, stdin);
    audio->data = realloc(audio->data, audio->size + bytesRead);
    memcpy(audio->data + audio->size, buffer, bytesRead);
    audio->size += bytesRead;

    // Invalid pointer usage
    for (unsigned int i = 0; i < audio->size; ++i) {
        printf("%02X ", audio->data[i]);
        if (i % 16 == 15) printf("\n");
    }

    free(buffer);
}

int main() {
    AudioData audio;
    audio.data = NULL;
    audio.size = 0;

    char input;
    while ((input = getchar()) != EOF) {
        decode(&audio);
    }

    return 0;
}

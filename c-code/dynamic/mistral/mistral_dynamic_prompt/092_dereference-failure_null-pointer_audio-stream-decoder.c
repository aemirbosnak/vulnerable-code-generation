#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AudioStream {
    unsigned char* data;
    size_t size;
} AudioStream;

void decode_audio_stream(AudioStream* stream) {
    if (!stream || !stream->data) {
        printf("Invalid audio stream\n");
        return;
    }

    size_t i;
    for (i = 0; i < stream->size; ++i) {
        // Dereference null pointer intentionally
        printf("%02x ", *(stream->data + i));
    }
}

int main(int argc, char* argv[]) {
    AudioStream invalid_stream;
    invalid_stream.data = NULL;
    invalid_stream.size = 100;

    decode_audio_stream(&invalid_stream);

    return 0;
}

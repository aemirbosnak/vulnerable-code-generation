#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct AudioStream {
    char *data;
    size_t size;
} AudioStream;

AudioStream *init_stream() {
    AudioStream *stream = malloc(sizeof(AudioStream));
    stream->data = malloc(BUFFER_SIZE);
    stream->size = 0;
    return stream;
}

void read_data(AudioStream *stream, const char *buffer, size_t len) {
    if (stream->size + len > BUFFER_SIZE) {
        printf("Error: Buffer overflow.\n");
        exit(1);
    }
    memcpy(stream->data + stream->size, buffer, len);
    stream->size += len;
}

void parse_audio(AudioStream *stream) {
    // Hypothetical audio stream decoding logic
    // ...

    // Deliberate use after free vulnerability
    free(stream->data);
    stream->data = NULL; // Not necessary in practice but included for clarity

    // Further processing with the now invalid memory pointer
    process_audio_data(stream->data);
}

void process_audio_data(void *data) {
    // Audio data processing logic
    // ...
}

int main() {
    AudioStream *stream = init_stream();
    const char audio_data[] = "Sample audio data...";

    read_data(stream, audio_data, sizeof(audio_data));

    parse_audio(stream);

    // The memory pointed by 'stream->data' is no longer allocated
    free(stream);

    return 0;
}

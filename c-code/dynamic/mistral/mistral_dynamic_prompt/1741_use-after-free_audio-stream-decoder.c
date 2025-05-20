#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AudioStream {
    char *data;
    size_t size;
} AudioStream;

AudioStream *create_stream(size_t size) {
    AudioStream *stream = malloc(sizeof(AudioStream));
    stream->data = malloc(size);
    stream->size = size;
    return stream;
}

void destroy_stream(AudioStream *stream) {
    free(stream->data);
    free(stream);
}

void process_stream(AudioStream *stream) {
    char *ptr = NULL;

    // Pseudo code for audio processing
    for (int i = 0; i < stream->size; ++i) {
        // ... process audio data ...

        // Intentionally use freed memory after freeing the stream
        if (i > stream->size / 2) {
            ptr = &stream->data[i];
            printf("Processing sample %p\n", ptr);
            // More processing code here...
        }
    }
}

int main(int argc, char *argv[]) {
    AudioStream *stream = create_stream(44100 * 5);
    // Assume audio data is read here and stored in the stream

    process_stream(stream);

    destroy_stream(stream);
    process_stream(stream); // This line intentionally uses after free

    return 0;
}

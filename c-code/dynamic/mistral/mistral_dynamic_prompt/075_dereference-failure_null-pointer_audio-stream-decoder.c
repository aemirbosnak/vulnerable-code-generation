#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} AudioStream;

AudioStream decode_audio_stream(char *input) {
    AudioStream stream = {NULL, 0, 0};
    stream.data = (char *)malloc(10 * sizeof(char));
    if (!stream.data) {
        perror("Error allocating memory for audio data");
        exit(EXIT_FAILURE);
    }

    stream.size = sprintf(stream.data, "%s", input);

    return stream;
}

void print_audio_data(AudioStream stream) {
    if (!stream.data) {
        fprintf(stderr, "Error: null pointer detected\n");
        return;
    }

    fwrite(stream.data, stream.size, 1, stdout);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_stream>\n", argv[0]);
        return EXIT_FAILURE;
    }

    AudioStream stream = decode_audio_stream(argv[1]);
    print_audio_data(stream);

    free(stream.data);
    return EXIT_SUCCESS;
}

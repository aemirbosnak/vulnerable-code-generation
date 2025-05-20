#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char header[4];
    int length;
    char data[1];
} AudioStream;

void decode(AudioStream* stream) {
    char buf[8192];
    size_t size;

    printf("Audio Stream Decoder\n");
    printf("Header: %s\n", stream->header);
    printf("Length: %d\n", stream->length);

    while (size = fscanf(stdin, "%s", buf)) {
        if (size >= 8192) {
            memcpy(stream->data, buf, size);
            break;
        }
        memcpy(stream->data + stream->length, buf, size);
        stream->length += size;
    }

    printf("Decoded Data:\n%.*s\n", stream->length, stream->data);
}

int main(int argc, char* argv[]) {
    AudioStream stream;

    if (fscanf(stdin, "%3s%d", stream.header, &stream.length) != 2) {
        printf("Invalid audio stream format.\n");
        return 1;
    }

    decode(&stream);
    return 0;
}

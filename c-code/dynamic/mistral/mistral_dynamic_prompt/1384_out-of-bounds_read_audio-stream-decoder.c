#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    unsigned short int bitrate;
    char format[5];
    unsigned int channels;
    unsigned int sample_rate;
    unsigned int size;
    char data[1];
} AudioStream;

void decode_stream(AudioStream* stream) {
    FILE* file = fopen(stream->name, "rb");
    if (file) {
        fread(stream, sizeof(AudioStream), 1, file);
        fseek(file, stream->size, SEEK_SET);
        printf("Decoding audio stream:\n");
        printf("Name: %s\n", stream->name);
        printf("Bitrate: %hu\n", stream->bitrate);
        printf("Format: %s\n", stream->format);
        printf("Channels: %u\n", stream->channels);
        printf("Sample Rate: %u\n", stream->sample_rate);
        printf("Size: %u\n", stream->size);

        char buffer[1024];
        while (fread(buffer, 1, 1024, file))
            printf("%s", buffer);

        fclose(file);
    } else
        printf("Error opening file: %s\n", stream->name);
}

int main(int argc, char* argv[]) {
    if (argc != 2)
        printf("Usage: %s <audio_stream_file>\n", argv[0]);
    else
        decode_stream((AudioStream*)argv[1]);

    return 0;
}

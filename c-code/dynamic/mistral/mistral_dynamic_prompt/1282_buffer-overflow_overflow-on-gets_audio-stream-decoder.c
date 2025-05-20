#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char header[4];
    char channels[2];
    char sample_rate[4];
    char format[2];
    char data[4096];
} AudioStream;

void decode_audio_stream(AudioStream* stream) {
    printf("Header: %s\n", stream->header);
    printf("Channels: %s\n", stream->channels);
    printf("Sample Rate: %s\n", stream->sample_rate);
    printf("Format: %s\n", stream->format);

    int i;
    for (i = 0; i < 4096; i++) {
        printf("%d ", (int)stream->data[i]);
    }
}

int main(int argc, char* argv[]) {
    AudioStream audio_data;

    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fread(&audio_data, sizeof(AudioStream), 1, file);
    fclose(file);

    decode_audio_stream(&audio_data);

    char input[1024];
    printf("\nEnter more data (up to 4096 bytes):\n");
    gets(input);
    strcpy(audio_data.data, input);
    decode_audio_stream(&audio_data);

    return 0;
}

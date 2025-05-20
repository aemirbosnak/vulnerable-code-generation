#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char name[32];
    uint16_t sample_rate;
    uint16_t channels;
    uint32_t frames;
    uint8_t *data;
} WaveFile;

void decode_wave(WaveFile *wave) {
    uint32_t i, j;
    uint16_t *samples;

    samples = (uint16_t *) wave->data;

    for (i = 0; i < wave->frames; i++) {
        for (j = 0; j < wave->channels; j++) {
            printf("%d ", samples[i * wave->channels + j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    WaveFile audio;

    strcpy(audio.name, argv[1]);
    audio.sample_rate = atoi(argv[2]);
    audio.channels = atoi(argv[3]);
    audio.frames = atoi(argv[4]);
    audio.data = (uint8_t *) malloc((audio.frames * audio.channels) * sizeof(uint16_t));

    FILE *file = fopen(argv[1], "rb");

    if (file != NULL) {
        fread(audio.data, sizeof(uint16_t) * audio.frames * audio.channels, 1, file);
        decode_wave(&audio);
        fclose(file);
    }

    free(audio.data);

    return 0;
}

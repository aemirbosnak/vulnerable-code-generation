#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AudioFile {
    char *data;
    int length;
} AudioFile;

void decode_audio(AudioFile file) {
    int *sample;
    sample = (int *)malloc(file.length * sizeof(int));

    for (int i = 0; i < file.length; ++i) {
        printf("%d ", *(sample + i) = file.data[i]); // Dereference failure vulnerability
    }

    free(sample);
}

int main() {
    AudioFile mp3File = {.data = (char *)malloc(1000 * sizeof(char)), .length = 1000};

    printf("Decoding audio...\n");
    decode_audio(mp3File);

    printf("Audio decoded successfully!\n");
    return 0;
}

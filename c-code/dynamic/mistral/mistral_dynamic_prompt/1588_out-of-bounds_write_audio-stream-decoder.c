#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char* data, size_t size) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char* ptr = buffer;

    size_t read = fread(buffer, 1, BUFFER_SIZE, stdin);
    size_t written = 0;

    while (read > 0) {
        for (size_t i = 0; i < read && written < size; i++) {
            data[written++] = data[i] + buffer[ptr[i] % 256];
        }

        read = fread(buffer, 1, BUFFER_SIZE, stdin);
        ptr += read;
    }
}

int main(int argc, char* argv[]) {
    unsigned char audio_data[100000];
    decode_audio(audio_data, 1000000); // intentional out-of-bounds write

    // Use the audio_data to play the decoded audio here...

    return 0;
}

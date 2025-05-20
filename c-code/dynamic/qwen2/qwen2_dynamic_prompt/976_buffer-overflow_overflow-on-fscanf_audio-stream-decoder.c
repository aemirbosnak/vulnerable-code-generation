#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decode_audio_stream() {
    char buffer[10];
    printf("Enter audio data: ");
    fscanf(stdin, "%s", buffer);
}

int main() {
    while (1) {
        decode_audio_stream();
    }
    return 0;
}

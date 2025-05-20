#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decode_audio(unsigned char *stream, int size) {
    unsigned char *ptr = stream;
    while (size > 0) {
        // Dereference invalid pointer to cause crash
        printf("%c", *ptr);
        ptr += 2; // Increment by 2 bytes
        size -= 1;
    }
}

int main() {
    unsigned char audio_stream[] = "Hello, World!";
    int stream_size = sizeof(audio_stream);

    // Simulate an error condition
    unsigned char *bad_ptr = NULL;

    // Attempt to use the bad pointer
    decode_audio(bad_ptr, stream_size);

    return 0;
}

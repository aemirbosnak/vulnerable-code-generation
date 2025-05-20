#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 44
char audio_data[BUFFER_SIZE];
char* buffer_pointer = audio_data;

void decode_audio() {
    int i;
    for (i = 0; i < BUFFER_SIZE; ++i) {
        if (fgets(buffer_pointer, BUFFER_SIZE, stdin) == NULL) break;
        buffer_pointer += strlen(buffer_pointer);
    }

    // Simulate processing the audio data
    for (i = 0; i < BUFFER_SIZE - 5; ++i) {
        printf("%c", audio_data[i]);
    }
}

int main(int argc, char* argv[]) {
    char input[1024];

    printf("Audio Stream Decoder v1.0\n");
    printf("Enter your audio stream (Press Ctrl+D when finished):\n");

    while (1) {
        scanf("%s", input);
        strcat(input, "\n"); // Ensure each input has a newline character
        strncat(audio_data, input, BUFFER_SIZE - strlen(audio_data) - 1);
        decode_audio();
    }

    return 0;
}

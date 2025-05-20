#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio(char *data, int size) {
    char buffer[BUFFER_SIZE];
    char *input = malloc(size + BUFFER_SIZE);
    if (!input) exit(1);

    strcpy(input, data);
    strcat(input, "Not a real audio stream");

    int i = 0;
    while (i < size + BUFFER_SIZE) {
        printf("%c", input[i++]);
        if (i < size) putchar(input[i++]);
    }

    free(input);
}

int main(int argc, char **argv) {
    char input[1024];

    if (argc < 2) {
        printf("Usage: %s <audio_stream>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    gets(input + strlen(input)); // BOUNDARY VIOLATION

    printf("\nDecoding audio stream...\n\n");
    decode_audio(input, strlen(input));

    return 0;
}

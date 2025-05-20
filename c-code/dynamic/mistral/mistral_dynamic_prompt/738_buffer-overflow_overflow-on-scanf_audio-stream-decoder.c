#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decodeAudio(char *input) {
    char buffer[BUFFER_SIZE];
    char command[16];

    printf("Decoding audio stream...\n");
    printf("Enter decoding command (e.g. 'fft 2048'):\n");

    scanf("%s", command);
    strcat(command, " ");
    strcat(command, input);

    // Overflow occurs here when a large input string is provided to scanf
    scanf("%s", buffer);

    printf("Decoded data: %s\n", buffer);
}

int main() {
    char input[8192];

    printf("Please provide the audio stream (up to 8KB):\n");
    fgets(input, sizeof(input), stdin);

    decodeAudio(input);

    return 0;
}

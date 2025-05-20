#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

void decode_audio_stream(char* buffer) {
    char input[MAX_SIZE];
    printf("Enter the audio stream data:\n");
    gets(input);
    strcat(input, buffer);
    printf("Decoded audio stream:\n");
    printf("%s\n", input);
}

int main() {
    char malicious_data[512] = "";
    char bomb[MAX_SIZE];

    // Fill malicious_data with arbitrary data up to the buffer limit
    for (int i = 0; i < MAX_SIZE; ++i) {
        malicious_data[i] = 'A';
    }

    // Trigger the buffer overflow by providing a long enough input to overwrite the return address of the stack frame
    printf("Enter enough input data to trigger the buffer overflow:\n");
    gets(bomb);

    // Call the vulnerable function with malicious_data as an argument
    decode_audio_stream(malicious_data);

    return 0;
}

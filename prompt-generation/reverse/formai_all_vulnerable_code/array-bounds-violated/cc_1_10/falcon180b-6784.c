//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000
#define MAX_CODE 4096

int freq[256] = { 0 }; // frequency table
int code[256] = { 0 }; // code table
int next_code = 0; // next available code
char output[MAX_LENGTH]; // output buffer
int output_index = 0; // current position in output buffer

void build_freq(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        freq[text[i]]++;
    }
}

void build_code(void) {
    int i;
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            code[i] = next_code++;
        }
    }
}

void encode(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        output[output_index++] = code[text[i]];
    }
    output[output_index++] = '\0';
}

void decode(char *text) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        printf("%c", freq[text[i]] > 0? freq[text[i]] : '?');
    }
    printf("\n");
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int choice;

    printf("Enter text to compress:\n");
    fgets(input, MAX_LENGTH, stdin);

    build_freq(input);
    build_code();

    printf("Compressed text:\n");
    encode(input);
    printf("%s\n", output);

    printf("Enter 1 to decode, 0 to exit:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Decoded text:\n");
        decode(output);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_char(int code) {
    if (code >= 0 && code <= 25) {
        return 'a' + code;
    }
    if (code >= 26 && code <= 51) {
        return 'A' + (code - 26);
    }
    if (code >= 52 && code <= 61) {
        return '0' + (code - 52);
    }
    if (code == 62) {
        return '~';
    }
    if (code == 63) {
        return '`';
    }
    return 0;
}

int get_code(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    if (c >= 'A' && c <= 'Z') {
        return 26 + (c - 'A');
    }
    if (c >= '0' && c <= '9') {
        return 52 + (c - '0');
    }
    if (c == '~') {
        return 62;
    }
    if (c == '`') {
        return 63;
    }
    return -1;
}

int compress(char *input, char *output) {
    int input_len = strlen(input);
    int idx, bits_left, code, i, j;
    unsigned char byte = 0;

    if (input_len <= 0) {
        return 0;
    }

    idx = 0;
    bits_left = 8;

    for (i = 0; i < input_len; i++) {
        code = get_code(input[i]);
        if (code < 0) {
            continue;
        }
        if (bits_left <= 6) {
            byte |= code >> (6 - bits_left);
            output[idx++] = byte;
            bits_left = 8;
            byte = 0;
        }
        bits_left -= 6;
        byte |= code << bits_left;
    }

    if (bits_left < 8) {
        output[idx++] = byte;
    }

    for (j = idx; j < input_len + 1; j++) {
        output[j] = '\0';
    }

    return strlen(output);
}

int decompress(char *input, char *output) {
    int input_len = strlen(input);
    int idx, bits_left, code, i, j;
    unsigned char byte;

    if (input_len <= 0) {
        return 0;
    }

    idx = 0;
    bits_left = 0;

    for (i = 0; i < input_len; i++) {
        byte = input[i];
        code = (byte >> bits_left) & 0x3F;
        bits_left += 6;
        if (bits_left >= 8) {
            bits_left -= 8;
            code |= (byte << (6 - bits_left)) & 0x3F;
        }
        output[idx++] = get_char(code);
    }

    for (j = idx; j < input_len + 1; j++) {
        output[j] = '\0';
    }

    return strlen(output);
}

int main() {
    char input[101], output[101], decompressed[101];
    printf("Please enter a string to compress (max 100 characters): ");
    scanf("%s", input);
    if (compress(input, output) > 0) {
        printf("Compressed version: %s\n", output);
        if (decompress(output, decompressed) > 0) {
            printf("Decompressed version: %s\n", decompressed);
        }
    }
    return 0;
}
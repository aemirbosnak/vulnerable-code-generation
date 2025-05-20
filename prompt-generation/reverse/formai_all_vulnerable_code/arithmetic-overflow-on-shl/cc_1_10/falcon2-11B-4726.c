//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

// Function to hash the input string using the MD5 algorithm
void hash_string(char* input_string, unsigned char* output_buffer, int output_buffer_size) {
    // Convert input string to bytes
    int string_length = strlen(input_string);
    unsigned char* input_bytes = (unsigned char*)malloc(string_length);
    memcpy(input_bytes, input_string, string_length);

    // Initialize MD5 context
    unsigned int md5_context[4] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476};
    unsigned char digest[16];

    // Compute MD5 hash
    md5_context[0] = 0;
    md5_context[1] = 0;
    md5_context[2] = 0;
    md5_context[3] = 0;
    md5_context[0] = input_bytes[0];
    md5_context[1] = input_bytes[1];
    md5_context[2] = input_bytes[2];
    md5_context[3] = input_bytes[3];
    for (int i = 4; i < string_length; i += 4) {
        md5_context[0] += input_bytes[i] << 24;
        md5_context[1] += input_bytes[i] << 16;
        md5_context[2] += input_bytes[i] << 8;
        md5_context[3] += input_bytes[i];
    }
    for (int i = 0; i < 4; i++) {
        md5_context[i] = md5_context[i] & 0xffffffff;
        for (int j = 0; j < 4; j++) {
            md5_context[i] += md5_context[j];
            md5_context[i] = md5_context[i] << 1;
            if (md5_context[i] & 0x10000000) {
                md5_context[i] = md5_context[i] ^ 0x9908b0df;
            }
        }
    }

    // Append padding if necessary
    if (string_length % 64!= 0) {
        int padding_length = 64 - (string_length % 64);
        memset(input_bytes + string_length, padding_length, sizeof(char));
    }

    // Compute final hash
    md5_context[0] += input_bytes[string_length];
    md5_context[1] += input_bytes[string_length] << 8;
    md5_context[2] += input_bytes[string_length] << 16;
    md5_context[3] += input_bytes[string_length] << 24;
    for (int i = 0; i < 16; i++) {
        digest[i] = (md5_context[0] & 0xff) + (md5_context[1] & 0xff) + (md5_context[2] & 0xff) + (md5_context[3] & 0xff);
        md5_context[0] += 0x67452301;
        md5_context[1] += 0xEFCDAB89;
        md5_context[2] += 0x98BADCFE;
        md5_context[3] += 0x10325476;
    }

    // Store hash in output buffer
    for (int i = 0; i < 16; i++) {
        output_buffer[i] = digest[i];
    }
}

// Function to convert bytes to hexadecimal string
char* bytes_to_hex(unsigned char* input_bytes, int input_bytes_length) {
    char* hex_string = (char*)malloc(2 * input_bytes_length * 2 + 1);
    int index = 0;
    for (int i = 0; i < input_bytes_length; i++) {
        sprintf(&hex_string[index], "%02x", input_bytes[i]);
        index += 2;
    }
    hex_string[index] = '\0';
    return hex_string;
}

// Function to convert hexadecimal string to bytes
unsigned char* hex_to_bytes(char* input_hex, int input_hex_length) {
    unsigned char* output_bytes = (unsigned char*)malloc(input_hex_length * 2 / 4);
    int index = 0;
    for (int i = 0; i < input_hex_length; i += 2) {
        unsigned char byte = 0;
        int value = atoi(input_hex + i);
        if (value >= 10) {
            byte = (value - 10) * 16;
        }
        else {
            byte = value;
        }
        output_bytes[index] = byte;
        index++;
    }
    return output_bytes;
}

// Main function
int main() {
    // Input string
    char input_string[] = "Hello, world!";

    // Output buffer for hash
    unsigned char output_buffer[BUFFER_SIZE];
    int output_buffer_size = BUFFER_SIZE;

    // Hash input string
    hash_string(input_string, output_buffer, output_buffer_size);

    // Convert hash to hexadecimal string
    char* hex_string = bytes_to_hex(output_buffer, output_buffer_size);

    // Print hexadecimal string
    printf("MD5 hash of %s: %s\n", input_string, hex_string);

    // Convert hexadecimal string back to bytes
    unsigned char* input_bytes = hex_to_bytes(hex_string, strlen(hex_string));

    // Print input bytes
    printf("Input bytes: %s\n", bytes_to_hex(input_bytes, strlen(input_bytes)));

    // Free memory
    free(hex_string);
    free(input_bytes);

    return 0;
}
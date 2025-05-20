//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100

int main(int argc, char *argv[]) {
    char *key = NULL;
    char *input_file = NULL;
    char *output_file = NULL;
    FILE *in_file = NULL;
    FILE *out_file = NULL;
    char buffer[1024];
    int key_len = 0;
    int i, j;

    // Check if correct number of arguments are provided
    if (argc!= 5) {
        printf("Usage: %s <input_file> <output_file> <encryption_key> <decryption_key>\n", argv[0]);
        return 1;
    }

    // Get input file name
    input_file = argv[1];

    // Get output file name
    output_file = argv[2];

    // Get encryption key
    key = argv[3];
    key_len = strlen(key);

    // Check if key is valid
    if (key_len == 0 || key_len > MAX_KEY_LEN) {
        printf("Invalid encryption key!\n");
        return 1;
    }

    // Open input file
    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Open output file
    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error opening output file!\n");
        fclose(in_file);
        return 1;
    }

    // Read input file
    while (fread(buffer, 1, sizeof(buffer), in_file) > 0) {
        // Encrypt buffer
        for (i = 0; i < sizeof(buffer); i++) {
            buffer[i] ^= key[i % key_len];
        }

        // Write encrypted buffer to output file
        fwrite(buffer, 1, sizeof(buffer), out_file);
    }

    // Close input and output files
    fclose(in_file);
    fclose(out_file);

    printf("File encrypted successfully!\n");

    return 0;
}
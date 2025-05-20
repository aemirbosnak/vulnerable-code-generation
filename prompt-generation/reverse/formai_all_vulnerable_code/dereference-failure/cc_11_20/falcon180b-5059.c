//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_FILENAME_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char operation = argv[1][0];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char key[MAX_KEY_SIZE];

    FILE *fp_in, *fp_out;
    int file_size;
    char *buffer;

    // Read input file
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    fseek(fp_in, 0, SEEK_END);
    file_size = ftell(fp_in);
    fseek(fp_in, 0, SEEK_SET);

    buffer = (char *)malloc(file_size);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(fp_in);
        return 1;
    }

    fread(buffer, file_size, 1, fp_in);
    fclose(fp_in);

    // Perform encryption or decryption
    for (int i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key[i] = tolower(key[i]);
        }
    }

    for (int i = 0; i < file_size; i++) {
        if (isalpha(buffer[i])) {
            if (operation == 'e') {
                buffer[i] = ((buffer[i] - 97 + 1) * (key[i % strlen(key)] - 97 + 1)) % 26 + 97;
            } else if (operation == 'd') {
                buffer[i] = ((buffer[i] - 97 - 1) / (key[i % strlen(key)] - 97 + 1)) % 26 + 97;
            }
        }
    }

    // Write output file
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error: Could not open output file.\n");
        free(buffer);
        return 1;
    }

    fwrite(buffer, file_size, 1, fp_out);
    fclose(fp_out);

    free(buffer);

    printf("Success!\n");

    return 0;
}
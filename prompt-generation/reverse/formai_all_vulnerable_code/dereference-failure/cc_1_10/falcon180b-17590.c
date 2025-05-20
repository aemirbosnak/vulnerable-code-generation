//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define KEY_SIZE 16

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char *key = argv[2];
    int key_len = strlen(key);
    if (key_len!= KEY_SIZE) {
        printf("Error: key must be exactly %d bytes.\n", KEY_SIZE);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char input_buffer[MAX_SIZE];
    char output_buffer[MAX_SIZE + KEY_SIZE];
    int input_len, output_len;

    while ((input_len = fread(input_buffer, 1, MAX_SIZE, input_file)) > 0) {
        for (int i = 0; i < input_len; i++) {
            output_buffer[i] = input_buffer[i] ^ key[i % key_len];
        }
        output_len = input_len;
        fwrite(output_buffer, 1, output_len, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}
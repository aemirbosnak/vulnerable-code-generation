//FormAI DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char file_name[100], key[50];
    char *buffer;
    int file_size, i, j, key_len;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    printf("Enter encryption key: ");
    scanf("%s", key);
    key_len = strlen(key);

    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Error: Could not open output file\n");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file); // get size of file
    fseek(input_file, 0, SEEK_SET);

    buffer = (char *) malloc(file_size + 1);
    if (!buffer) {
        printf("Error: Could not allocate memory\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fread(buffer, 1, file_size, input_file);

    // perform encryption
    for (i = 0, j = 0; i < file_size; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        buffer[i] = buffer[i] ^ key[j];
    }

    fwrite(buffer, 1, file_size, output_file);

    free(buffer);
    fclose(input_file);
    fclose(output_file);

    printf("File has been encrypted successfully\n");
    return 0;
}
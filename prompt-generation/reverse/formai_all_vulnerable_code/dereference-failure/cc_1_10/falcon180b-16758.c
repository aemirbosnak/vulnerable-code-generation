//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <key> <file>\n", argv[0]);
        return 1;
    }

    char key[MAX_KEY_LENGTH + 1] = {0};
    strncpy(key, argv[1], MAX_KEY_LENGTH);

    char file_content[MAX_FILE_LENGTH + 1] = {0};
    FILE *file = fopen(argv[2], "rb");
    if (!file) {
        printf("Error: File not found\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    if (fread(file_content, 1, file_size, file)!= file_size) {
        printf("Error: Failed to read file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    int key_index = 0;
    for (int i = 0; i < strlen(file_content); i++) {
        char c = file_content[i];
        c = (c + key[key_index % MAX_KEY_LENGTH]) % 256;
        file_content[i] = c;
        key_index++;
    }

    FILE *output_file = fopen("encrypted.txt", "wb");
    if (!output_file) {
        printf("Error: Failed to create output file\n");
        return 1;
    }

    fwrite(file_content, 1, strlen(file_content), output_file);
    fclose(output_file);

    printf("File encrypted successfully\n");
    return 0;
}
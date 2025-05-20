//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: happy
// Happy File Encryptor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_FILE_SIZE 1000000

void encrypt(char *key, char *file_name) {
    FILE *input_file, *output_file;
    char ch;
    int i, j, key_index;

    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return;
    }

    output_file = fopen("encrypted_file", "w");
    if (output_file == NULL) {
        printf("Error creating file\n");
        return;
    }

    key_index = 0;
    while ((ch = fgetc(input_file)) != EOF) {
        ch = ch + key[key_index];
        fputc(ch, output_file);
        key_index++;
        if (key_index == strlen(key)) {
            key_index = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char key[MAX_KEY_LENGTH];
    printf("Enter key: ");
    scanf("%s", key);

    encrypt(key, argv[1]);

    return 0;
}
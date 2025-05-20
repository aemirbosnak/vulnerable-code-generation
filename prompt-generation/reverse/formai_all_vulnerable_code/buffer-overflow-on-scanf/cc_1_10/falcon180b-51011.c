//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100
#define MAX_ENCRYPTED_FILE_NAME_LENGTH (MAX_FILE_NAME_LENGTH + 1)

int main() {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    char encrypted_file_name[MAX_ENCRYPTED_FILE_NAME_LENGTH];
    FILE *input_file;
    FILE *output_file;
    int i, j, file_size;
    char buffer[1024];

    printf("Enter the file name: ");
    scanf("%s", file_name);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".enc");

    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen(encrypted_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fseek(input_file, 0L, SEEK_END);
    file_size = ftell(input_file);
    rewind(input_file);

    while ((i = fread(buffer, 1, 1024, input_file)) > 0) {
        for (j = 0; j < i; j++) {
            buffer[j] ^= key[j % strlen(key)];
        }
        fwrite(buffer, 1, i, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}
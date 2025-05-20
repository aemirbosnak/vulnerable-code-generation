//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_ENCRYPTED_FILE_NAME_LENGTH (MAX_FILE_NAME_LENGTH + 10)

typedef struct {
    char *file_name;
    char *encrypted_file_name;
    FILE *file_ptr;
    FILE *encrypted_file_ptr;
} File;

void generate_encrypted_file_name(char *file_name, char *encrypted_file_name) {
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".encrypted");
}

int main() {
    FILE *file_ptr;
    char file_name[MAX_FILE_NAME_LENGTH];
    char encrypted_file_name[MAX_ENCRYPTED_FILE_NAME_LENGTH];
    char input_buffer[1024];
    char encrypted_buffer[1024];
    int bytes_read, bytes_written;
    File file;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_name);

    generate_encrypted_file_name(file_name, encrypted_file_name);

    file.file_name = strdup(file_name);
    file.encrypted_file_name = strdup(encrypted_file_name);
    file.file_ptr = fopen(file_name, "rb");
    file.encrypted_file_ptr = fopen(encrypted_file_name, "wb");

    if (file.file_ptr == NULL || file.encrypted_file_ptr == NULL) {
        printf("Error opening file(s).\n");
        exit(1);
    }

    while ((bytes_read = fread(input_buffer, 1, sizeof(input_buffer), file.file_ptr)) > 0) {
        int i;
        for (i = 0; i < bytes_read; i++) {
            encrypted_buffer[i] = input_buffer[i] ^ 0xAA;
        }
        bytes_written = fwrite(encrypted_buffer, 1, bytes_read, file.encrypted_file_ptr);
        if (bytes_written!= bytes_read) {
            printf("Error writing to file.\n");
            exit(1);
        }
    }

    fclose(file.file_ptr);
    fclose(file.encrypted_file_ptr);

    printf("File encrypted successfully!\n");

    return 0;
}
//FormAI DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_BUFFER_SIZE 1024

// function to encrypt file contents
void encrypt(char* filename, char* key) {
    FILE *file;
    char buffer[MAX_BUFFER_SIZE];
    int i = 0, j = 0, k = 0;
    int key_length = strlen(key);
    int buffer_length, bytes_read;
    
    // open the file to read
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    // read file contents into buffer
    buffer_length = fread(buffer, 1, sizeof(buffer), file);

    // encrypt file contents with key
    for (i = 0; i < buffer_length; i++) {
        j = (j + 1) % key_length;
        k = (k + key[j]) % 256;

        int temp = buffer[i];
        buffer[i] = buffer[k];
        buffer[k] = temp ^ buffer[k];
    }

    // close the file
    fclose(file);

    // open the file to write
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    // write encrypted contents to file
    fwrite(buffer, 1, buffer_length, file);

    // close the file
    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    char key[MAX_BUFFER_SIZE];

    // get filename from user
    printf("Enter filename to encrypt: ");
    scanf("%s", filename);

    // get key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // encrypt file contents
    encrypt(filename, key);

    printf("File contents encrypted successfully.\n");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_FILENAME_SIZE 256

int main() {
    char filename[MAX_FILENAME_SIZE];
    char key[MAX_KEY_SIZE];
    FILE *file;
    char *buffer;
    int length;

    // Get filename from user
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);

    // Get key from user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open file for reading
    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Get file length
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    rewind(file);

    // Allocate memory for buffer
    buffer = malloc(length);

    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read file into buffer
    fread(buffer, length, 1, file);
    fclose(file);

    // Encrypt buffer using key
    for (int i = 0; i < length; i++) {
        if (isalpha(buffer[i])) {
            if (isupper(buffer[i])) {
                buffer[i] = 'A' + ((buffer[i] - 'A' + key[i % strlen(key)]) % 26);
            } else {
                buffer[i] = 'a' + ((buffer[i] - 'a' + key[i % strlen(key)]) % 26);
            }
        } else {
            buffer[i] = buffer[i];
        }
    }

    // Write encrypted buffer to new file
    strcat(filename, ".enc");
    file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: File not found.\n");
        free(buffer);
        return 1;
    }

    fwrite(buffer, length, 1, file);
    fclose(file);
    free(buffer);

    printf("File encrypted successfully!\n");

    return 0;
}
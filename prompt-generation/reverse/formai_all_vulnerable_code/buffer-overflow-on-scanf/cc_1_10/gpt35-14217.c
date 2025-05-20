//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 255 // maximum length of file name
#define MAX_KEY_LEN 255 // maximum length of encryption key

int encryptFile(char *filename, char *key);
char *readFile(char *filename);
int writeFile(char *filename, char *data);

int main(int argc, char *argv[]) {
    char filename[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter encryption key: ");
    scanf("%s", key);

    if (encryptFile(filename, key) == 0) {
        printf("File encrypted successfully!\n");
    } else {
        printf("Error encrypting file!\n");
    }

    return 0;
}

/**
 * Encrypts the contents of a file using a provided encryption key.
 *
 * @param filename The name of the file to encrypt.
 * @param key The encryption key to use.
 *
 * @return Returns 0 on success, 1 on failure.
 */
int encryptFile(char *filename, char *key) {
    char *data = readFile(filename);
    if (data == NULL) {
        return 1;
    }

    int len = strlen(data);
    for (int i = 0, j = 0; i < len; i++, j++) {
        if (key[j] == '\0') {
            j = 0;
        }

        data[i] = data[i] ^ key[j];
    }

    if (writeFile(filename, data) == 1) {
        return 1;
    }

    free(data);

    return 0;
}

/**
 * Reads the contents of a file into memory.
 *
 * @param filename The name of the file to read.
 *
 * @return Returns a pointer to the contents of the file, or NULL on failure.
 */
char *readFile(char *filename) {
    FILE *file;
    char *data;
    int size;

    file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    data = malloc(size * sizeof(char));
    fread(data, sizeof(char), size, file);

    fclose(file);

    return data;
}

/**
 * Writes data to a file.
 *
 * @param filename The name of the file to write to.
 * @param data The data to write to the file.
 *
 * @return Returns 0 on success, 1 on failure.
 */
int writeFile(char *filename, char *data) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        return 1;
    }

    fwrite(data, sizeof(char), strlen(data), file);

    fclose(file);

    return 0;
}
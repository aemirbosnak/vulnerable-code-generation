//FormAI DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILEDATA_LENGTH 65536

void encrypt(char* data, int length, char* key) {
    int key_length = strlen(key);
    for(int i = 0; i < length; i++) {
        data[i] = data[i] ^ key[i % key_length];
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name to encrypt: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char filedata[MAX_FILEDATA_LENGTH];
    int filedata_length = 0;
    char line[256];
    while(fgets(line, sizeof(line), file)) {
        int line_length = strlen(line);
        if(filedata_length + line_length > MAX_FILEDATA_LENGTH) {
            printf("Error: File is too large.\n");
            return 1;
        }
        strcpy(&filedata[filedata_length], line);
        filedata_length += line_length;
    }
    fclose(file);

    char key[MAX_FILENAME_LENGTH];
    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(filedata, filedata_length, key);

    char encrypted_filename[MAX_FILENAME_LENGTH];
    snprintf(encrypted_filename, sizeof(encrypted_filename), "%s.enc", filename);

    FILE* encrypted_file = fopen(encrypted_filename, "w");
    if(encrypted_file == NULL) {
        printf("Error: Could not create encrypted file.\n");
        return 1;
    }
    fputs(filedata, encrypted_file);
    fclose(encrypted_file);

    printf("File successfully encrypted as %s.\n", encrypted_filename);

    return 0;
}
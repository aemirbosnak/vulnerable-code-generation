//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    char fileName[MAX_FILE_NAME_LEN];
} FileEncryptor;

void generateKey(char *key) {
    // Generate a random key
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encryptFile(FileEncryptor *encryptor) {
    FILE *file;
    char ch;
    int keyIndex = 0;
    FILE *outputFile;

    // Open the input file
    file = fopen(encryptor->fileName, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", encryptor->fileName);
        exit(1);
    }

    // Create the output file
    outputFile = fopen("encrypted.txt", "w");
    if (outputFile == NULL) {
        printf("Error creating output file: encrypted.txt\n");
        exit(1);
    }

    // Encrypt the file and write to output file
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = (ch - 'a' + encryptor->key[keyIndex] - 'a') % 26 + 'a';
            keyIndex = (keyIndex + 1) % strlen(encryptor->key);
        }
        fprintf(outputFile, "%c", ch);
    }

    // Close the input and output files
    fclose(file);
    fclose(outputFile);
}

int main() {
    // Get the file name and key from the user
    char fileName[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Generate a random key if none provided
    if (strlen(key) == 0) {
        generateKey(key);
        printf("Generated key: %s\n", key);
    }

    // Encrypt the file
    FileEncryptor encryptor;
    strcpy(encryptor.fileName, fileName);
    strcpy(encryptor.key, key);
    encryptFile(&encryptor);

    return 0;
}
//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_KEY_LENGTH 16

void encryptFile(char *fileName, char *key);
int validateKey(char *key);

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", fileName);

    printf("Enter the encryption key (must be 8 characters long): ");
    scanf("%s", key);

    if (validateKey(key)) {
        encryptFile(fileName, key);
        printf("Encrypted successfully!");
    } else {
        printf("Invalid encryption key, please enter an 8-character long key.");
    }

    return 0;
}

void encryptFile(char *fileName, char *key) {
    FILE *file, *encryptedFile;
    char c;
    int i = 0;
    int keyIndex = 0;

    file = fopen(fileName, "r");
    encryptedFile = fopen(strcat(fileName, ".enc"), "w");

    while ((c = fgetc(file)) != EOF) {
        fputc(c ^ key[keyIndex], encryptedFile);
        
        keyIndex++;
        if (keyIndex == strlen(key)) {
            keyIndex = 0;
        }
    }

    fclose(file);
    fclose(encryptedFile);
}

int validateKey(char *key) {
    if (strlen(key) != 8) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        if (key[i] < 'A' || key[i] > 'Z') {
            return 0;
        }
    }

    return 1;
}
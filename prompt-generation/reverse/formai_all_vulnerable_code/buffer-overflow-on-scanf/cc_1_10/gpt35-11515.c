//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char *filename, char *key) {
    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize);
    fread(buffer, fileSize, 1, file);
    fclose(file);

    for (int i = 0; i < fileSize; i++) {
        buffer[i] = buffer[i] + key[i % strlen(key)];
    }

    file = fopen(filename, "wb");
    fwrite(buffer, fileSize, 1, file);
    fclose(file);
    free(buffer);

    printf("File encrypted successfully!\n");
}

void decryptFile(char *filename, char *key) {
    FILE *file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize);
    fread(buffer, fileSize, 1, file);
    fclose(file);

    for (int i = 0; i < fileSize; i++) {
        buffer[i] = buffer[i] - key[i % strlen(key)];
    }

    file = fopen(filename, "wb");
    fwrite(buffer, fileSize, 1, file);
    fclose(file);
    free(buffer);

    printf("File decrypted successfully!\n");
}

int main() {
    char choice;
    char filename[100];
    char key[100];

    printf("Welcome to the C File Encryptor!\n");

    do {
        printf("\nEnter E to encrypt a file, D to decrypt a file, or Q to quit: ");
        choice = getchar();
        fflush(stdin);

        switch (choice) {
            case 'E':
            case 'e':
                printf("\nEnter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encryptFile(filename, key);
                break;
            case 'D':
            case 'd':
                printf("\nEnter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decryptFile(filename, key);
                break;
            case 'Q':
            case 'q':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }

        fflush(stdin);
    } while (choice != 'Q' && choice != 'q');

    return 0;
}
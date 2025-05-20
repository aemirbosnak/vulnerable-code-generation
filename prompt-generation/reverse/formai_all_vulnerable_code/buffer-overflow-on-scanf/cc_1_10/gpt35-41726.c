//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENCRYPTED_FILE "encrypted.txt"
#define DECRYPTED_FILE "decrypted.txt"
#define KEY_FILE "key.txt"

void encrypt(char *filename, char *key) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file '%s' for reading.\n", filename);
        return;
    }

    // Generate random permutation of characters for encryption
    char permutation[256];
    memcpy(permutation, key, strlen(key));
    srand(time(NULL));
    for (int i = 0; i < 256; i++) {
        int j = rand() % 256;
        char temp = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = temp;
    }

    FILE *encrypted_file = fopen(ENCRYPTED_FILE, "w");
    FILE *key_file = fopen(KEY_FILE, "w");
    if (!encrypted_file || !key_file) {
        printf("Could not open files for writing.\n");
        return;
    }
    fprintf(key_file, "%s", permutation);

    // Encrypt file by writing out the encrypted version of each character
    int c;
    while ((c = fgetc(file)) != EOF) {
        fputc(permutation[c], encrypted_file);
    }

    fclose(file);
    fclose(encrypted_file);
    fclose(key_file);
}

void decrypt(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file '%s' for reading.\n", filename);
        return;
    }

    FILE *key_file = fopen(KEY_FILE, "r");
    if (!key_file) {
        printf("Could not open key file for reading.\n");
        return;
    }

    char permutation[256];
    fscanf(key_file, "%s", permutation);
    fclose(key_file);

    FILE *decrypted_file = fopen(DECRYPTED_FILE, "w");
    int c;
    while ((c = fgetc(file)) != EOF) {
        for (int i = 0; i < 256; i++) {
            if (permutation[i] == c) {
                fputc(i, decrypted_file);
                break;
            }
        }
    }

    fclose(file);
    fclose(decrypted_file);
}

int main() {
    char filename[100];
    printf("Enter the name of the file to encrypt:");
    scanf("%s", filename);

    char key[256];
    printf("Enter the encryption key:");
    scanf("%s", key);

    encrypt(filename, key);
    printf("Encrypted file saved as '%s'\n", ENCRYPTED_FILE);
    printf("Encryption key saved as '%s'\n", KEY_FILE);

    printf("Enter the name of the file to decrypt:");
    scanf("%s", filename);

    decrypt(filename);
    printf("Decrypted file saved as '%s'\n", DECRYPTED_FILE);

    return 0;
}
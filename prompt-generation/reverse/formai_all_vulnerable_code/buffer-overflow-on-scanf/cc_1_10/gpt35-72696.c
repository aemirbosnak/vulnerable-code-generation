//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') continue;
        message[i] = ((message[i] - 'a' + key) % 26) + 'a';
    }
}

void decrypt(char message[], int key) {
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') continue;
        int x = message[i] - 'a' - key;
        if (x < 0) x += 26;
        message[i] = x + 'a';
    }
}

int main() {
    printf("Welcome to the Medieval File Encryptor!\n");

    // File input
    char filename[50];
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    FILE *fptr = fopen(filename, "r");
    if (!fptr) {
        printf("Error opening file. Exiting...\n");
        return 1;
    }

    // Read contents of file
    char message[1000];
    fscanf(fptr, "%[^\n]", message);
    fclose(fptr);

    // Encryption
    int key;
    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encryption complete!\n");

    // File output
    char outputFilename[50];
    printf("Enter the output filename: ");
    scanf("%s", outputFilename);
    fptr = fopen(outputFilename, "w");
    if (!fptr) {
        printf("Error creating file. Exiting...\n");
        return 1;
    }
    fprintf(fptr, "%s", message);
    fclose(fptr);
    printf("Encryption saved!\n");

    // Decryption
    char choice;
    printf("Would you like to decrypt the file? (y/n): ");
    getchar(); // clear input buffer
    scanf("%c", &choice);
    if (choice == 'y') {
        fptr = fopen(outputFilename, "r");
        if (!fptr) {
            printf("Error opening file. Exiting...\n");
            return 1;
        }
        fscanf(fptr, "%[^\n]", message);
        fclose(fptr);
        decrypt(message, key);
        printf("Decryption complete!\n");
        printf("The decrypted message is:\n%s\n", message);
    }

    return 0;
}
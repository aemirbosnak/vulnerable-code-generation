//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt file using Caesar cipher
void encryptFile(FILE *fp, int key){
    int c;
    // Temporary file to store encrypted data
    FILE *tmp = fopen("temp.txt", "w");

    while ((c = fgetc(fp)) != EOF) {
        // Encrypting uppercase letters
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + key) % 26 + 'A';
        }
        // Encrypting lowercase letters
        else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') + key) % 26 + 'a';
        }
        // Writing encrypted data to temporary file
        fputc(c, tmp);
    }

    // Rewinding file pointer
    rewind(fp);

    // Copying encrypted data to original file
    while ((c = fgetc(tmp)) != EOF) {
        fputc(c, fp);
    }

    // Closing and deleting temporary file
    fclose(tmp);
    remove("temp.txt");

    printf("File encrypted successfully!\n");
}

// Function to decrypt file using Caesar cipher
void decryptFile(FILE *fp, int key){
    int c;
    // Temporary file to store decrypted data
    FILE *tmp = fopen("temp.txt", "w");

    while ((c = fgetc(fp)) != EOF) {
        // Decrypting uppercase letters
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') - key + 26) % 26 + 'A';
        }
        // Decrypting lowercase letters
        else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') - key + 26) % 26 + 'a';
        }
        // Writing decrypted data to temporary file
        fputc(c, tmp);
    }

    // Rewinding file pointer
    rewind(fp);

    // Copying decrypted data to original file
    while ((c = fgetc(tmp)) != EOF) {
        fputc(c, fp);
    }

    // Closing and deleting temporary file
    fclose(tmp);
    remove("temp.txt");

    printf("File decrypted successfully!\n");
}

int main(){
    // Opening file to encrypt/decrypt
    FILE *fp;
    char fileName[100], ans[3];
    int key;

    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%s", fileName);

    // Checking if file exists
    if ((fp = fopen(fileName, "r+")) == NULL) {
        printf("Error: File does not exist.\n");
        exit(1);
    }

    printf("Do you want to encrypt or decrypt the file? (E/D) ");
    scanf("%s", ans);

    // Encrypting file
    if(strcmp(ans, "E") == 0 || strcmp(ans, "e") == 0){
        printf("Enter the encryption key: ");
        scanf("%d", &key);
        encryptFile(fp, key);
    }
    // Decrypting file
    else if(strcmp(ans, "D") == 0 || strcmp(ans, "d") == 0){
        printf("Enter the decryption key: ");
        scanf("%d", &key);
        decryptFile(fp, key);
    }
    // Invalid input
    else{
        printf("Invalid input. Please enter E or D.\n");
    }

    // Closing file
    fclose(fp);

    return 0;
}
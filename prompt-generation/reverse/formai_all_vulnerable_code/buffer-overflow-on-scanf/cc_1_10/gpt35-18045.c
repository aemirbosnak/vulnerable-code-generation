//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_KEY_LENGTH 100

void encryptFile(char *filename, char *key);
void decryptFile(char *filename, char *key);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;
    
    printf("Enter the name of the file to encrypt: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove the trailing newline
    
    printf("\nEnter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Remove the trailing newline
    
    printf("\nChoose an option:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encryptFile(filename, key);
            break;
        case 2:
            decryptFile(filename, key);
            break;
        default:
            printf("Invalid choice");
            return 1;
    }
    
    return 0;
}

void encryptFile(char *filename, char *key) {
    FILE *fp;
    char newFilename[MAX_FILENAME_LENGTH + 4];
    char c;
    int i = 0, keyLen = strlen(key);
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file");
        return;
    }
    
    // Create the new encrypted filename
    strcpy(newFilename, filename);
    strcat(newFilename, ".enc");
    
    FILE *fpEnc = fopen(newFilename, "w");
    if(fpEnc == NULL) {
        printf("Error creating encrypted file");
        return;
    }
    
    // Encrypt the file
    while((c = fgetc(fp)) != EOF) {
        fputc(c ^ key[i % keyLen], fpEnc); // XOR each character with a character from the key
        i++;
    }
    
    printf("File successfully encrypted as %s\n", newFilename);
    fclose(fp);
    fclose(fpEnc);
}

void decryptFile(char *filename, char *key) {
    FILE *fp;
    char newFilename[MAX_FILENAME_LENGTH - 4];
    char c;
    int i = 0, keyLen = strlen(key);
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file");
        return;
    }
    
    // Create the new decrypted filename
    strncpy(newFilename, filename, strlen(filename) - 4);
    newFilename[strlen(filename) - 4] = '\0';
    
    FILE *fpDec = fopen(newFilename, "w");
    if(fpDec == NULL) {
        printf("Error creating decrypted file");
        return;
    }
    
    // Decrypt the file
    while((c = fgetc(fp)) != EOF) {
        fputc(c ^ key[i % keyLen], fpDec); // XOR each character with a character from the key
        i++;
    }
    
    printf("File successfully decrypted as %s\n", newFilename);
    fclose(fp);
    fclose(fpDec);
}
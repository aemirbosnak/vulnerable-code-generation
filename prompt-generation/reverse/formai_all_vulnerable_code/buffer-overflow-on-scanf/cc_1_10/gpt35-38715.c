//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(char* fileName) {
    FILE* fp;
    int ch;
    fp = fopen(fileName, "rb+");
    while(1) {
        ch = fgetc(fp);
        if(ch == EOF) break;
        ch += 25;
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
    }
    fclose(fp);
}

// Function to decrypt the file
void decryptFile(char* fileName) {
    FILE* fp;
    int ch;
    fp = fopen(fileName, "rb+");
    while(1) {
        ch = fgetc(fp);
        if(ch == EOF) break;
        ch -= 25;
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;
    char fileName[100];
    printf("Welcome to File Encryptor/Decryptor\n\n");
    while(1) {
        printf("Choose an option\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the file name to encrypt: ");
                scanf("%s", fileName);
                strcat(fileName, ".txt");
                encryptFile(fileName);
                printf("File encrypted successfully\n\n");
                break;
            case 2:
                printf("Enter the file name to decrypt: ");
                scanf("%s", fileName);
                strcat(fileName, ".txt");
                decryptFile(fileName);
                printf("File decrypted successfully\n\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n\n");
        }
    }
    return 0;
}
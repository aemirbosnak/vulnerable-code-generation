//FormAI DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define KEY_LENGTH 16

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i = 0;
    
    while(i < message_len) {
        for(int j = 0; j < key_len && i < message_len; j++) {
            message[i] ^= key[j];
            i++;
        }
    }
}

void decrypt(char *message, char *key) {
    encrypt(message, key);
}

void save_encrypted_message(char *encrypted_message, char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fputs(encrypted_message, fp);
    fclose(fp);
}

void read_message_from_file(char *message, char *filename) {
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    while((ch = fgetc(fp)) != EOF) {
        message[i] = ch;
        i++;
    }
    message[i] = '\0';
    fclose(fp);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char key[KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int option;
    
    printf("Welcome to the File Encryptor!\n");
    printf("Please select an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Option: ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Enter the name of the file to encrypt: ");
            scanf("%s", filename);
            read_message_from_file(message, filename);
            printf("Enter the encryption key (16 characters): ");
            scanf("%s", key);
            encrypt(message, key);
            strcpy(encrypted_message, message);
            save_encrypted_message(encrypted_message, strcat(filename, ".enc"));
            printf("File encrypted successfully!\n");
            break;
        case 2:
            printf("Enter the name of the file to decrypt: ");
            scanf("%s", filename);
            read_message_from_file(message, filename);
            printf("Enter the decryption key (16 characters): ");
            scanf("%s", key);
            decrypt(message, key);
            strcpy(encrypted_message, message);
            save_encrypted_message(encrypted_message, strstr(filename, ".enc"));
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid option\n");
            exit(1);
            break;
    }
    
    return 0;
}
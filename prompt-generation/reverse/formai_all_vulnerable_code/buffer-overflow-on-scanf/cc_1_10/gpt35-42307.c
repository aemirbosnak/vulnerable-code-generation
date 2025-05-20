//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void encrypt(char *filename, char *key) {
    char newname[100], command[200], password[100];
    strcpy(newname, "encrypted_");
    strcat(newname, filename);
    printf("Enter the password: ");
    scanf("%s", password);
    sprintf(command, "echo '%s' | openssl aes-256-cbc -salt -in %s -out %s -k %s",
            password, filename, newname, key);
    system(command);
    printf("File encrypted successfully.\n");
}

void decrypt(char *filename, char *key) {
    char newname[100], command[200], password[100];
    strcpy(newname, "decrypted_");
    strcat(newname, filename);
    printf("Enter the password: ");
    scanf("%s", password);
    sprintf(command, "echo '%s' | openssl aes-256-cbc -d -salt -in %s -out %s -k %s",
            password, filename, newname, key);
    system(command);
    printf("File decrypted successfully.\n");
}

int main() {
    int choice;
    char filename[100], key[100];
    srand(time(NULL));
    printf("Welcome to the Cryptic File backup system\n\n");
    printf("Enter the file name: ");
    scanf("%s", filename);
    printf("Enter the key (16 characters): ");
    scanf("%s", key);
    while (strlen(key) != 16) {
        printf("Invalid key. Please enter a 16 character key: ");
        scanf("%s", key);
    }
    printf("\nPlease choose an option:\n\n1. Encrypt file\n2. Decrypt file\n\n");
    printf("Enter your selection: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            encrypt(filename, key);
            break;
        case 2:
            decrypt(filename, key);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    return 0;
}
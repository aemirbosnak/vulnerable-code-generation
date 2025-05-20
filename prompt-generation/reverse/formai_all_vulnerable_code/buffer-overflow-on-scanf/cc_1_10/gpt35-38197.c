//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

void encrypt(char* file_path, char* key){
    FILE* file = fopen(file_path, "r");
    if(file == NULL){
        printf("Error: File not found!\n");
        exit(1);
    }

    char encrypted_name[MAX_INPUT_SIZE];
    strcpy(encrypted_name, file_path);
    strcat(encrypted_name, ".enc");
    FILE* encrypted_file = fopen(encrypted_name, "w");

    int key_length = strlen(key);
    int key_index = 0;
    char c = fgetc(file);
    while(c != EOF){
        fputc(c^key[key_index], encrypted_file);
        key_index = (key_index + 1) % key_length;
        c = fgetc(file);
    }

    fclose(file);
    fclose(encrypted_file);

    printf("File Encrypted Successfully!\n");
}

void decrypt(char* file_path, char* key){
    FILE* file = fopen(file_path, "r");
    if(file == NULL){
        printf("Error: File not found!\n");
        exit(1);
    }

    char decrypted_name[MAX_INPUT_SIZE];
    strcpy(decrypted_name, file_path);
    char* file_extension = strrchr(decrypted_name, '.');
    if(file_extension != NULL){
        *file_extension = '\0';
    }
    strcat(decrypted_name, "_decrypted");
    strcat(decrypted_name, file_extension);

    FILE* decrypted_file = fopen(decrypted_name, "w");

    int key_length = strlen(key);
    int key_index = 0;
    char c = fgetc(file);
    while(c != EOF){
        fputc(c^key[key_index], decrypted_file);
        key_index = (key_index + 1) % key_length;
        c = fgetc(file);
    }

    fclose(file);
    fclose(decrypted_file);

    printf("File Decrypted Successfully!\n");
}

int main(){
    printf("Welcome to the file encryptor!\nEnter file path: ");
    char file_path[MAX_INPUT_SIZE];
    fgets(file_path, MAX_INPUT_SIZE, stdin);
    strtok(file_path, "\n");

    printf("Enter encryption/decryption key: ");
    char key[MAX_INPUT_SIZE];
    fgets(key, MAX_INPUT_SIZE, stdin);
    strtok(key, "\n");

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);
    getchar(); //clearing input buffer

    switch(choice){
        case 1:
            encrypt(file_path, key);
            break;
        case 2:
            decrypt(file_path, key);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
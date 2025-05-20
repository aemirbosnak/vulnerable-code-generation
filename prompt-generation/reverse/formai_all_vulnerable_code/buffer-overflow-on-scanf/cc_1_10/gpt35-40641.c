//FormAI DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *file_path, char *key){
    FILE *fp_in, *fp_out;
    char buffer[BUFFER_SIZE];
    int key_length = strlen(key);
    int i = 0;

    fp_in = fopen(file_path, "rb");
    if(fp_in == NULL){
        printf("Error: Unable to open input file!\n");
        return;
    }

    fp_out = fopen(strcat(file_path, ".encrypted"), "wb");
    if(fp_out == NULL){
        printf("Error: Unable to create output file!\n");
        return;
    }

    while(fread(buffer, 1, BUFFER_SIZE, fp_in)){
        for(i=0; i<BUFFER_SIZE; i++){
            buffer[i] = buffer[i] ^ key[(i % key_length)];
        }
        fwrite(buffer, 1, BUFFER_SIZE, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    printf("Encryption successful!\n");
}

void decrypt(char *file_path, char *key){
    FILE *fp_in, *fp_out;
    char buffer[BUFFER_SIZE];
    int key_length = strlen(key);
    int i = 0;

    fp_in = fopen(file_path, "rb");
    if(fp_in == NULL){
        printf("Error: Unable to open input file!\n");
        return;
    }

    // create output filename by removing ".encrypted" extension
    char *output_file_path = malloc(strlen(file_path) - strlen(".encrypted") + 1);
    strncpy(output_file_path, file_path, strlen(file_path) - strlen(".encrypted"));
    output_file_path[strlen(file_path) - strlen(".encrypted")] = '\0';

    fp_out = fopen(output_file_path, "wb");
    if(fp_out == NULL){
        printf("Error: Unable to create output file!\n");
        return;
    }

    while(fread(buffer, 1, BUFFER_SIZE, fp_in)){
        for(i=0; i<BUFFER_SIZE; i++){
            buffer[i] = buffer[i] ^ key[(i % key_length)];
        }
        fwrite(buffer, 1, BUFFER_SIZE, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    printf("Decryption successful!\n");
}

int main(){
    char file_path[100];
    char key[100];
    int choice = 0;

    printf("Welcome to the C File Encryptor!\n");

    while(1){
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt file\n");
        printf("2. Decrypt file\n");
        printf("3. Exit program\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the path of the file to encrypt: ");
                scanf("%s", file_path);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encrypt(file_path, key);
                break;

            case 2:
                printf("Enter the path of the file to decrypt: ");
                scanf("%s", file_path);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decrypt(file_path, key);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again!\n");
        }
    }

    return 0;
}
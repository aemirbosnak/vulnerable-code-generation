//FormAI DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filename, char *key){
    FILE *fileptr;
    char *buffer;
    long filelen;

    // Open the file
    fileptr = fopen(filename, "rb");
    if(fileptr == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    // Get file length
    fseek(fileptr, 0, SEEK_END);
    filelen = ftell(fileptr);
    rewind(fileptr);

    // Allocate memory
    buffer = (char *)malloc(filelen * sizeof(char));
    if(buffer == NULL){
        printf("Error allocating memory!\n");
        fclose(fileptr);
        exit(1);
    }

    // Read file into buffer
    fread(buffer, filelen, 1, fileptr);
    fclose(fileptr);

    // Encrypt buffer using given key
    for(int i=0; i<filelen; i++){
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write encrypted data back to file
    fileptr = fopen(filename, "wb");
    if(fileptr == NULL){
        printf("Error opening file!\n");
        free(buffer);
        exit(1);
    }
    fwrite(buffer, filelen, 1, fileptr);
    fclose(fileptr);
    free(buffer);

    printf("%s has been encrypted successfully.\n", filename);
}

void decrypt(char *filename, char *key){
    encrypt(filename, key);
    printf("%s has been decrypted successfully.\n", filename);
}

int main(){
    char filename[50], key[50];
    int option;

    printf("Welcome to C File Encryptor!\n");
    printf("-----------------------------------------\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("-----------------------------------------\n");

    while(1){
        printf("Enter your choice (1-3): ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encrypt(filename, key);
                break;
            case 2:
                printf("Enter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decrypt(filename, key);
                break;
            case 3:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
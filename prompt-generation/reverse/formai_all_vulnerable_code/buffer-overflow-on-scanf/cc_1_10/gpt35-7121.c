//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 10

void encrypt(char *filename) {
    FILE *fileptr_in, *fileptr_out;
    char *buffer;
    long size;
    
    // open the input file for reading
    fileptr_in = fopen(filename, "rb");
    fseek(fileptr_in, 0, SEEK_END);          // move the file pointer to end of file
    size = ftell(fileptr_in);               // get the size of file
    rewind(fileptr_in);                     // bring the file pointer back to beginning of file
    
    // allocate memory for buffer to hold the contents of file
    buffer = (char*) malloc(sizeof(char) * size);
    fread(buffer, size, 1, fileptr_in);     // read the file contents into buffer
    fclose(fileptr_in);                     // close the input file
    
    // open the output file for writing
    fileptr_out = fopen(filename, "wb");
    
    // encryption algorithm using XOR operation with KEY
    for (int i=0; i<size; i++) {
        buffer[i] ^= KEY;
    }
    
    fwrite(buffer, size, 1, fileptr_out);   // write the encrypted data to output file
    fclose(fileptr_out);                    // close the output file
    
    free(buffer);                           // free the memory allocated for buffer
}

void decrypt(char *filename) {
    FILE *fileptr_in, *fileptr_out;
    char *buffer;
    long size;
    
    // open the input file for reading
    fileptr_in = fopen(filename, "rb");
    fseek(fileptr_in, 0, SEEK_END);          // move the file pointer to end of file
    size = ftell(fileptr_in);               // get the size of file
    rewind(fileptr_in);                     // bring the file pointer back to beginning of file
    
    // allocate memory for buffer to hold the contents of file
    buffer = (char*) malloc(sizeof(char) * size);
    fread(buffer, size, 1, fileptr_in);     // read the file contents into buffer
    fclose(fileptr_in);                     // close the input file
    
    // open the output file for writing
    fileptr_out = fopen(filename, "wb");
    
    // decryption algorithm using XOR operation with KEY
    for (int i=0; i<size; i++) {
        buffer[i] ^= KEY;
    }
    
    fwrite(buffer, size, 1, fileptr_out);   // write the decrypted data to output file
    fclose(fileptr_out);                    // close the output file
    
    free(buffer);                           // free the memory allocated for buffer
}

int main() {
    char filename[100];
    int choice;

    printf("\n1. Encrypt the file");
    printf("\n2. Decrypt the file");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the filename: ");
    scanf("%s", filename);

    switch (choice) {
        case 1:
            encrypt(filename);
            printf("\nFile encrypted successfully!\n");
            break;
        case 2:
            decrypt(filename);
            printf("\nFile decrypted successfully!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}
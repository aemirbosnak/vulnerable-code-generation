//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret_key"
#define KEY_LENGTH 9

// Function to encrypt the file
void encrypt_file(FILE* input_file, FILE* output_file) {
    char buffer[1024];
    int buffer_length;
    int i;

    while ((buffer_length = fread(buffer, sizeof(char), sizeof(buffer), input_file))!= 0) {
        for (i = 0; i < buffer_length; i++) {
            buffer[i] ^= KEY[i % KEY_LENGTH];
        }
        fwrite(buffer, sizeof(char), buffer_length, output_file);
    }
}

// Function to decrypt the file
void decrypt_file(FILE* input_file, FILE* output_file) {
    char buffer[1024];
    int buffer_length;
    int i;

    while ((buffer_length = fread(buffer, sizeof(char), sizeof(buffer), input_file))!= 0) {
        for (i = 0; i < buffer_length; i++) {
            buffer[i] ^= KEY[i % KEY_LENGTH];
        }
        fwrite(buffer, sizeof(char), buffer_length, output_file);
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;
    char filename[100];

    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%s", filename);

    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    output_file = fopen("encrypted.txt", "wb");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    printf("Enter 1 to encrypt, 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt_file(input_file, output_file);
        printf("File encrypted successfully.\n");
    } else if (choice == 2) {
        decrypt_file(input_file, output_file);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
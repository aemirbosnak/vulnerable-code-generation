//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *file_in, FILE *file_out) {
    char ch;
    int key = 5; // Key for encryption
    while ((ch = fgetc(file_in))!= EOF) {
        if (isalpha(ch)) {
            ch = (char) ((int) ch + key - 65);
            if (ch > 90) {
                ch = (char) ((int) ch - 26);
            }
        }
        fputc(ch, file_out);
    }
}

// Function to decrypt the file
void decrypt_file(FILE *file_in, FILE *file_out) {
    char ch;
    int key = 5; // Key for decryption
    while ((ch = fgetc(file_in))!= EOF) {
        if (isalpha(ch)) {
            ch = (char) ((int) ch - key - 65);
            if (ch < 65) {
                ch = (char) ((int) ch + 26);
            }
        }
        fputc(ch, file_out);
    }
}

int main() {
    FILE *file_in, *file_out;
    char filename[100];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", filename);

    // Open the input file
    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create the output file
    strcat(filename, ".enc");
    file_out = fopen(filename, "w");
    if (file_out == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(file_in, file_out);

    // Close the files
    fclose(file_in);
    fclose(file_out);

    printf("File %s has been encrypted successfully.\n", filename);
    return 0;
}
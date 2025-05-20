//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch, i = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = ch ^ key[i];
        fputc(ch, output_file);
        i = (i + 1) % strlen(key);
    }
}

// Function to decrypt a file
void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch, i = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = ch ^ key[i];
        fputc(ch, output_file);
        i = (i + 1) % strlen(key);
    }
}

int main() {
    char key[100];
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open input and output files
    FILE *input_file = fopen("input.txt", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *output_file = fopen("output.txt", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Encrypt the file
    encrypt_file(input_file, output_file, key);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
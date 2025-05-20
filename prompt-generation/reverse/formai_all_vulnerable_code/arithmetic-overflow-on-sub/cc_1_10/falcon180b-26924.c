//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key;
    key = time(0);
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch - 'A' + key) % 26) + 'A';
        }
        fputc(ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

// Function to decrypt the file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key;
    key = time(0);
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch - 'A' - key + 26) % 26) + 'A';
        }
        fputc(ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main() {
    FILE *input_file, *output_file;
    char filename[100], choice;
    printf("Enter the name of the file to be encrypted/decrypted: ");
    scanf("%s", filename);
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    printf("\nEnter your choice:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    scanf("%c", &choice);
    if (choice == '1') {
        output_file = fopen("encrypted_file.txt", "wb");
        encrypt_file(input_file, output_file);
        printf("\nFile encrypted successfully and saved as encrypted_file.txt\n");
    }
    else if (choice == '2') {
        output_file = fopen("decrypted_file.txt", "wb");
        decrypt_file(input_file, output_file);
        printf("\nFile decrypted successfully and saved as decrypted_file.txt\n");
    }
    else {
        printf("Invalid choice\n");
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}
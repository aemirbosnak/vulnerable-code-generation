//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char c;
    int key = time(NULL); // Using current time as encryption key
    while ((c = fgetc(input_file))!= EOF) {
        if (isalpha(c)) {
            c = ((c - 'a' + key) % 26) + 'a'; // Encrypting alphabet characters
        }
        fputc(c, output_file);
    }
}

// Function to decrypt the file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char c;
    int key = time(NULL); // Using current time as decryption key
    while ((c = fgetc(input_file))!= EOF) {
        if (isalpha(c)) {
            c = ((c - 'a' - key + 26) % 26) + 'a'; // Decrypting alphabet characters
        }
        fputc(c, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char file_name[100];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);
    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: File not found\n");
        exit(0);
    }
    output_file = fopen("encrypted.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not create output file\n");
        exit(0);
    }
    encrypt_file(input_file, output_file);
    printf("File encrypted successfully\n");
    fclose(input_file);
    fclose(output_file);
    return 0;
}
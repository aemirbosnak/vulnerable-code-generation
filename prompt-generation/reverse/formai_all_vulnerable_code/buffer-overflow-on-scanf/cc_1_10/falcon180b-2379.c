//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000
#define ENCRYPTION_KEY "secret_key"

void encrypt(char* input, char* output);
void decrypt(char* input, char* output);

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int choice;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input);

    // Get choice of encryption or decryption
    printf("Enter 1 for encryption or 2 for decryption: ");
    scanf("%d", &choice);

    // Read input file
    FILE* fp = fopen(input, "rb");
    if (fp == NULL) {
        printf("Error: input file not found\n");
        return 1;
    }

    // Read input file into buffer
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    char* buffer = (char*) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: insufficient memory\n");
        fclose(fp);
        return 1;
    }
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    // Encrypt or decrypt file
    if (choice == 1) {
        encrypt(buffer, output);
        printf("Output file: %s.enc\n", input);
    } else if (choice == 2) {
        decrypt(buffer, output);
        printf("Output file: %s.dec\n", input);
    } else {
        printf("Invalid choice\n");
        free(buffer);
        return 1;
    }

    // Write output file
    FILE* out_fp = fopen(output, "wb");
    if (out_fp == NULL) {
        printf("Error: output file could not be created\n");
        free(buffer);
        return 1;
    }
    fwrite(output, 1, strlen(output), out_fp);
    fclose(out_fp);

    free(buffer);
    return 0;
}

void encrypt(char* input, char* output) {
    int i, j;
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            output[j] = (char) (tolower(input[i]) + (ENCRYPTION_KEY[j % strlen(ENCRYPTION_KEY)] - 'a'));
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}

void decrypt(char* input, char* output) {
    int i, j;
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            output[j] = (char) ((input[i] - ENCRYPTION_KEY[j % strlen(ENCRYPTION_KEY)] + 'a'));
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';
}
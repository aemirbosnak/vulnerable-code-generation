//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

// Encrypts the given input file and saves the encrypted data to the output file
void encrypt(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return;
    }

    char buffer[MAX_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_SIZE, input)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ (i + 1);
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

// Decrypts the given input file and saves the decrypted data to the output file
void decrypt(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return;
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return;
    }

    char buffer[MAX_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_SIZE, input)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = buffer[i] ^ (i + 1);
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    time_t seed = time(NULL);
    srand(seed);

    int choice;
    printf("Choose operation:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(input_file, output_file);
    } else if (choice == 2) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
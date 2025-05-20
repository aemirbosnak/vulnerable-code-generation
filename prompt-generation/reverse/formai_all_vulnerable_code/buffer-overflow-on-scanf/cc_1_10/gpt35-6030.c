//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PASSWORD_LENGTH 256
#define BUFFER_SIZE 1024

void encrypt_file(char *input_filename, char *output_filename, char *password) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file '%s'.\n", input_filename);
        return;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Unable to open output file '%s'.\n", output_filename);
        return;
    }

    int password_length = strlen(password);
    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

    int index = 0;
    fseek(input_file, 0, SEEK_END);
    long int input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    while (ftell(input_file) != input_file_size) {
        int bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file);
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= password[index % password_length];
            index++;
        }

        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    free(buffer);
}

void decrypt_file(char *input_filename, char *output_filename, char *password) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file '%s'.\n", input_filename);
        return;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Unable to open output file '%s'.\n", output_filename);
        return;
    }

    int password_length = strlen(password);
    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

    int index = 0;
    fseek(input_file, 0, SEEK_END);
    long int input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    while (ftell(input_file) != input_file_size) {
        int bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file);
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= password[index % password_length];
            index++;
        }

        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    free(buffer);
}

int main() {
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the input filename: ");
    scanf("%s", input_filename);

    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    printf("Enter the password: ");
    scanf("%s", password);

    int choice;
    printf("Enter 1 to encrypt the file and 2 to decrypt the file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt_file(input_filename, output_filename, password);
        printf("File encrypted successfully.\n");
    } else if (choice == 2) {
        decrypt_file(input_filename, output_filename, password);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

char key[] = "secretkey"; // Change this to your encryption key

void encrypt(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "r"); // Open input file in read mode
    FILE *output_file = fopen(output_file_name, "w"); // Open output file in write mode

    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return;
    }

    if (output_file == NULL) {
        printf("Error: Could not open output file!\n");
        return;
    }

    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];

    int i = 0;
    int j = 0;
    int input_file_size = 0;

    while ((input_buffer[i] = fgetc(input_file)) != EOF && i < MAX_FILE_SIZE) {
        // Encrypt each character in the file using a simple xor operation with the encryption key
        output_buffer[i] = input_buffer[i] ^ key[j];

        i++;
        j = (j + 1) % strlen(key);
    }

    input_file_size = i;

    // Write the encrypted data to the output file
    fwrite(output_buffer, sizeof(char), input_file_size, output_file);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
}

void decrypt(char *input_file_name, char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "r"); // Open input file in read mode
    FILE *output_file = fopen(output_file_name, "w"); // Open output file in write mode

    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return;
    }

    if (output_file == NULL) {
        printf("Error: Could not open output file!\n");
        return;
    }

    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];

    int i = 0;
    int j = 0;

    // Read the input file into the input buffer
    while ((input_buffer[i] = fgetc(input_file)) != EOF && i < MAX_FILE_SIZE) {
        output_buffer[i] = input_buffer[i] ^ key[j];

        i++;
        j = (j + 1) % strlen(key);
    }

    // Write the decrypted data to the output file
    fwrite(output_buffer, sizeof(char), i, output_file);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File decrypted successfully!\n");
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    int choice;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Encrypt file\n");
        printf("2. Decrypt file\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", input_file_name);

                printf("Enter the name of the output file: ");
                scanf("%s", output_file_name);

                encrypt(input_file_name, output_file_name);
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", input_file_name);

                printf("Enter the name of the output file: ");
                scanf("%s", output_file_name);

                decrypt(input_file_name, output_file_name);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
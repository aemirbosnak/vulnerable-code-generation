//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char *input_file_name, char *output_file_name, char *key) {
    FILE *input_file, *output_file;  // File pointers for input and output file
    char buffer[MAX_SIZE];
    int key_length = strlen(key);  // Getting the key length

    // Opening input file in read mode and output file in write mode
    input_file = fopen(input_file_name, "rb");
    output_file = fopen(output_file_name, "wb");

    while (fgets(buffer, MAX_SIZE, input_file)) {
        int i;
        for (i = 0; i < strlen(buffer); i++) {
            int ascii_val = (int) buffer[i];
            int encrypted_ascii_val = ((ascii_val + key[i % key_length]) % 256);  // Performing XOR operation on ascii value with key value
            fprintf(output_file, "%d ", encrypted_ascii_val);  // Writing encrypted ascii values to output file
        }
    }

    // Closing the files
    fclose(input_file);
    fclose(output_file);

    printf("File is encrypted successfully.\n");
}

void decrypt(char *input_file_name, char *output_file_name, char *key) {
    FILE *input_file, *output_file;  // File pointers for input and output file
    char buffer[MAX_SIZE];
    int key_length = strlen(key);  // Getting the key length

    // Opening input file in read mode and output file in write mode
    input_file = fopen(input_file_name, "rb");
    output_file = fopen(output_file_name, "wb");

    while (fgets(buffer, MAX_SIZE, input_file)) {
        int i;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            int ascii_val = atoi(token);
            int decrypted_ascii_val = ((ascii_val - key[i % key_length] + 256) % 256);  // Performing XOR operation on the ascii value with key value
            fprintf(output_file, "%c", decrypted_ascii_val);  // Writing decrypted characters to output file
            i++;
            token = strtok(NULL, " ");
        }
    }

    // Closing the files
    fclose(input_file);
    fclose(output_file);

    printf("File is decrypted successfully.\n");
}

int main() {
    char input_file_name[50], output_file_name[50], key[50];
    int choice;

    do {
        printf("Enter the operation you want to perform:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the input file name: ");
                scanf("%s", input_file_name);
                printf("Enter the output file name: ");
                scanf("%s", output_file_name);
                printf("Enter the key: ");
                scanf("%s", key);
                encrypt(input_file_name, output_file_name, key);
                break;
            case 2:
                printf("Enter the input file name: ");
                scanf("%s", input_file_name);
                printf("Enter the output file name: ");
                scanf("%s", output_file_name);
                printf("Enter the key: ");
                scanf("%s", key);
                decrypt(input_file_name, output_file_name, key);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while(choice != 3);

    return 0;
}
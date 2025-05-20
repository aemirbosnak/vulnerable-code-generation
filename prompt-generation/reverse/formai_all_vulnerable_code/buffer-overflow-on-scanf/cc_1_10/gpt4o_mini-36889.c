//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *input, char *output, int key);
void decrypt(char *input, char *output, int key);
void readFile(const char *filename, char *buffer, size_t size);
void writeFile(const char *filename, const char *buffer);
void displayBinary(const char *buffer);

int main() {
    int key;
    char input[1024];
    char output[1024];
    char choice;
    
    printf("Simple C Encryption Tool\n");
    printf("=========================\n");
    printf("Please enter encryption key (between 1 to 25): ");
    scanf("%d", &key);

    // Input validation for the key
    if (key < 1 || key > 25) {
        printf("Invalid key! It must be between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a string\n");
        printf("2. Decrypt a string\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        getchar(); // Consume newline from the buffer
        choice = getchar();

        switch (choice) {
            case '1':
                printf("Enter the string to encrypt: ");
                getchar(); // Consume newline from the buffer
                fgets(input, 1024, stdin);
                // Remove new line character from input
                input[strcspn(input, "\n")] = 0;
                encrypt(input, output, key);
                printf("Encrypted string: %s\n", output);
                break;
            case '2':
                printf("Enter the string to decrypt: ");
                getchar(); // Consume newline from the buffer
                fgets(input, 1024, stdin);
                // Remove new line character from input
                input[strcspn(input, "\n")] = 0;
                decrypt(input, output, key);
                printf("Decrypted string: %s\n", output);
                break;
            case '3':
                printf("Exiting the program. Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to encrypt the input string
void encrypt(char *input, char *output, int key) {
    int i;
    
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' + key) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' + key) % 26 + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null terminate the output string
}

// Function to decrypt the input string
void decrypt(char *input, char *output, int key) {
    int i;
    
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' - key + 26) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' - key + 26) % 26 + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null terminate the output string
}

// Function to read a file into a buffer
void readFile(const char *filename, char *buffer, size_t size) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fread(buffer, sizeof(char), size, file);
    fclose(file);
}

// Function to write a buffer to a file
void writeFile(const char *filename, const char *buffer) {
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fprintf(file, "%s", buffer);
    fclose(file);
}

// Function to display binary representation of a string
void displayBinary(const char *buffer) {
    for (size_t i = 0; i < strlen(buffer); i++) {
        printf("%c: ", buffer[i]);
        for (int j = 7; j >= 0; j--) {
            putchar((buffer[i] & (1 << j)) ? '1' : '0');
        }
        printf("\n");
    }
}
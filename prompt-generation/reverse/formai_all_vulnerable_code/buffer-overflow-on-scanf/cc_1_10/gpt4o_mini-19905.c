//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define FILENAME "cryptic_text.txt"

void encrypt(char *data, int shift) {
    for (int i = 0; data[i] != '\0'; ++i) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = ((data[i] - 'a' + shift) % 26) + 'a';
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = ((data[i] - 'A' + shift) % 26) + 'A';
        }
        // Ignore non-alphabetic characters
    }
}

void decrypt(char *data, int shift) {
    encrypt(data, 26 - (shift % 26)); // Decrypt is just encrypt with reverse shift
}

void file_write(const char *file_name, const char *data) {
    FILE *file = fopen(file_name, "w");
    if (!file) {
        perror("File opening failed");
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
}

void file_read(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        perror("File opening failed");
        return;
    }
    char line[MAX_LINE_LENGTH];

    printf("Content of the file:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void display_menu() {
    printf("\nCryptic File Handler Menu:\n");
    printf("1. Encrypt and Save Text\n");
    printf("2. Decrypt and Read Text\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, shift;
    char data[MAX_LINE_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                fgets(data, sizeof(data), stdin);
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Must be between 1 and 25.\n");
                    break;
                }
                encrypt(data, shift);
                file_write(FILENAME, data);
                printf("Data encrypted and saved to %s\n", FILENAME);
                break;

            case 2:
                file_read(FILENAME);
                char file_data[MAX_LINE_LENGTH];
                printf("\nEnter shift value to decrypt: ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Must be between 1 and 25.\n");
                    break;
                }
                
                // Read content with same function for simplicity
                FILE *file = fopen(FILENAME, "r");
                if (file) {
                    while (fgets(file_data, sizeof(file_data), file)) {
                        decrypt(file_data, shift);
                        printf("Decrypted Line: %s", file_data);
                    }
                    fclose(file);
                }
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}
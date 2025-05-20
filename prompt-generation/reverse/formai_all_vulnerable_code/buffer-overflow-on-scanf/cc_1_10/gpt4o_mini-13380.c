//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 256
#define MAX_TEXT_SIZE 1024

void generate_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256; // Generates a random byte
    }
}

void xor_encrypt_decrypt(const char *text, const char *key, char *output, int text_length) {
    for (int i = 0; i < text_length; i++) {
        output[i] = text[i] ^ key[i % MAX_KEY_SIZE];
    }
}

void print_menu() {
    printf("Cryptography Program Menu:\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Generate Key\n");
    printf("4. Exit\n");
}

void read_input(char *text, int size) {
    printf("Enter your text: ");
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline
}

int main() {
    int choice;
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    char output[MAX_TEXT_SIZE];

    while (1) {
        print_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after scanf
        
        switch (choice) {
            case 1: // Encrypt Text
                printf("Encryption Selected.\n");
                read_input(text, MAX_TEXT_SIZE);
                generate_key(key, MAX_KEY_SIZE);
                xor_encrypt_decrypt(text, key, output, strlen(text));
                printf("Encrypted Text: ");
                for (int i = 0; i < strlen(text); i++) {
                    printf("%02X", (unsigned char)output[i]); // Print as hexadecimal
                }
                printf("\nGenerated Key: ");
                for (int i = 0; i < MAX_KEY_SIZE; i++) {
                    printf("%02X", (unsigned char)key[i]); // Print key as hexadecimal
                }
                printf("\n");
                break;

            case 2: // Decrypt Text
                printf("Decryption Selected.\n");
                printf("Enter the encrypted text in hex: ");
                read_input(text, MAX_TEXT_SIZE);
                printf("Enter the key in hex (32 bytes): ");
                read_input(key, MAX_KEY_SIZE);
                
                // Convert hex key back to bytes
                unsigned char byte_key[MAX_KEY_SIZE];
                for (int i = 0; i < MAX_KEY_SIZE; i++) {
                    sscanf(&key[i * 2], "%2hhx", &byte_key[i]);
                }
                
                // Convert hex text back to bytes
                unsigned char byte_text[MAX_TEXT_SIZE];
                for (int i = 0; i < strlen(text) / 2; i++) {
                    sscanf(&text[i * 2], "%2hhx", &byte_text[i]);
                }
                
                xor_encrypt_decrypt((char *)byte_text, (char *)byte_key, output, strlen(text) / 2);
                printf("Decrypted Text: %s\n", output);
                break;

            case 3: // Generate Key
                printf("Generated Key:\n");
                generate_key(key, MAX_KEY_SIZE);
                for (int i = 0; i < MAX_KEY_SIZE; i++) {
                    printf("%02X", (unsigned char)key[i]); // Print as hexadecimal
                }
                printf("\n");
                break;

            case 4: // Exit
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
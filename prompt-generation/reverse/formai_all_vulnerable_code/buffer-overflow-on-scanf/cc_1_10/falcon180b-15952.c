//Falcon-180B DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "secretkey"
#define MAX_LENGTH 1000
#define ALPHABET_LENGTH 26

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
int key_index, is_encrypt, current_index;

void encrypt_message(char* message) {
    int message_length = strlen(message);
    char encrypted_message[MAX_LENGTH];
    strcpy(encrypted_message, "");

    for (int i = 0; i < message_length; i++) {
        char current_char = tolower(message[i]);
        int char_index = current_char - 'a';

        if (isalpha(current_char)) {
            if (is_encrypt) {
                encrypted_message[current_index] = alphabet[(char_index + key_index) % ALPHABET_LENGTH];
            } else {
                encrypted_message[current_index] = alphabet[char_index];
            }
        } else {
            encrypted_message[current_index] = current_char;
        }

        current_index++;
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt_message(char* message) {
    int message_length = strlen(message);
    char decrypted_message[MAX_LENGTH];
    strcpy(decrypted_message, "");

    for (int i = 0; i < message_length; i++) {
        char current_char = message[i];
        int char_index = current_char - 'a';

        if (isalpha(current_char)) {
            if (is_encrypt) {
                decrypted_message[current_index] = alphabet[(char_index - key_index + ALPHABET_LENGTH) % ALPHABET_LENGTH];
            } else {
                decrypted_message[current_index] = alphabet[char_index];
            }
        } else {
            decrypted_message[current_index] = current_char;
        }

        current_index++;
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_LENGTH];
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Encrypt message? (y/n): ");
    char encrypt_choice;
    scanf("%c", &encrypt_choice);

    if (encrypt_choice == 'y' || encrypt_choice == 'Y') {
        is_encrypt = 1;
        encrypt_message(message);
    } else if (encrypt_choice == 'n' || encrypt_choice == 'N') {
        is_encrypt = 0;
        decrypt_message(message);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    return 0;
}
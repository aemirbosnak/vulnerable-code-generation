//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY_LENGTH 16

void generate_key(char *key) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

int main() {
    char message[1000];
    char key[KEY_LENGTH];
    int choice;
    int length;
    printf("Enter your message: ");
    scanf("%s", message);
    printf("Enter the key length (must be 16): ");
    scanf("%d", &length);
    if (length!= KEY_LENGTH) {
        printf("Invalid key length!\n");
        return 1;
    }
    printf("Enter your key: ");
    scanf("%s", key);
    printf("Enter the mode of encryption:\n1. Encryption\n2. Decryption\n");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Encrypted message: ");
        for (int i = 0; i < strlen(message); i++) {
            if (isalpha(message[i])) {
                int j = (int)message[i] - 97;
                int k = (int)key[i % KEY_LENGTH] - 97;
                int encrypted_char = (j + k) % 26 + 97;
                printf("%c", encrypted_char);
            } else {
                printf("%c", message[i]);
            }
        }
    } else if (choice == 2) {
        printf("Decrypted message: ");
        for (int i = 0; i < strlen(message); i++) {
            if (isalpha(message[i])) {
                int j = (int)message[i] - 97;
                int k = (int)key[i % KEY_LENGTH] - 97;
                int decrypted_char = (26 + j - k) % 26 + 97;
                printf("%c", decrypted_char);
            } else {
                printf("%c", message[i]);
            }
        }
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    return 0;
}
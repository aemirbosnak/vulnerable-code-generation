//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 100

void generate_key(char key[MAX_KEY_LENGTH]) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt(char text[MAX_TEXT_LENGTH], char key[MAX_KEY_LENGTH]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = key[j] + 'A' - 'a';
            } else {
                text[i] = key[j] + 'a';
            }
            j = (j + 1) % MAX_KEY_LENGTH;
        }
    }
}

void decrypt(char text[MAX_TEXT_LENGTH], char key[MAX_KEY_LENGTH]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = 'A' + (text[i] - key[j]) % 26;
            } else {
                text[i] = 'a' + (text[i] - key[j]) % 26;
            }
            j = (j + 1) % MAX_KEY_LENGTH;
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    printf("Enter a string to encrypt and decrypt:\n");
    scanf("%s", text);

    generate_key(key);

    printf("Enter 1 to encrypt or 2 to decrypt:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
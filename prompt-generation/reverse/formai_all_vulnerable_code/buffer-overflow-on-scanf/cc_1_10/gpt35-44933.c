//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char str[], int key);
void decrypt(char str[], int key);

int main() {
    char str[100];
    int key, choice;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(str, key);
            printf("Encrypted string: %s\n", str);
            break;
        case 2:
            decrypt(str, key);
            printf("Decrypted string: %s\n", str);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void encrypt(char str[], int key) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + key) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + key) % 26;
        }
        i++;
    }
}

void decrypt(char str[], int key) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' - key + 26) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' - key + 26) % 26;
        }
        i++;
    }
}
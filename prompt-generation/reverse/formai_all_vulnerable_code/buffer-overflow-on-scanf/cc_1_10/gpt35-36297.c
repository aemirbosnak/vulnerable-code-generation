//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, char *key) {
    int i, j, k = 0;
    char *encrypted_text = malloc(strlen(text) * sizeof(char));
    
    for (i = 0, j = 0; i < strlen(text); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        k = toupper(key[j]) - 65;
        if (isalpha(text[i])) {
            encrypted_text[i] = (text[i] - 65 + k) % 26 + 65;
        } else {
            encrypted_text[i] = text[i];
            j--;
        }
    }
    encrypted_text[i] = '\0';
    printf("Encrypted text: %s\n", encrypted_text);
    free(encrypted_text);
}

void decrypt(char *encrypted_text, char *key) {
    int i, j, k = 0;
    char *text = malloc(strlen(encrypted_text) * sizeof(char));
    
    for (i = 0, j = 0; i < strlen(encrypted_text); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        k = toupper(key[j]) - 65;
        if (isalpha(encrypted_text[i])) {
            text[i] = ((encrypted_text[i] - 65 - k) + 26) % 26 + 65;
        } else {
            text[i] = encrypted_text[i];
            j--;
        }
    }
    text[i] = '\0';
    printf("Decrypted text: %s\n", text);
    free(text);
}

int main() {
    char text[100], key[100], choice;
    
    printf("\nEnter text to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                encrypt(text, key);
                break;
            case '2':
                decrypt(text, key);
                break;
            case '3':
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (choice != '3');

    return 0;
}
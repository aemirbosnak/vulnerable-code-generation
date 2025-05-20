//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function to encrypt the input string using Caesar Cipher
void caesar_cipher_encrypt(char *input_string, int key) {
    int i;
    for(i=0; i<strlen(input_string); i++) {
        if(isalpha(input_string[i])) {
            char base = isupper(input_string[i]) ? 'A' : 'a';
            input_string[i] = (input_string[i] - base + key) % 26 + base;
        }
    }
}

//Function to decrypt the input string using Caesar Cipher
void caesar_cipher_decrypt(char *input_string, int key) {
    int i;
    for(i=0; i<strlen(input_string); i++) {
        if(isalpha(input_string[i])) {
            char base = isupper(input_string[i]) ? 'A' : 'a';
            input_string[i] = (input_string[i] - base - key + 26) % 26 + base;
        }
    }
}

//Function to generate a random key of a given length
void generate_key(char *key, int key_length) {
    int i;
    for(i=0; i<key_length; i++) {
        key[i] = rand()%26 + 'A';
    }
    key[key_length] = '\0';
}

//Function to encrypt the input string using a Vigenere Cipher
void vigenere_cipher_encrypt(char *input_string, char *key) {
    int i, j=0;
    int key_length = strlen(key);
    for(i=0; i<strlen(input_string); i++) {
        if(isalpha(input_string[i])) {
            char base = isupper(input_string[i]) ? 'A' : 'a';
            int key_index = j%key_length;
            char key_char = tolower(key[key_index]) - 'a';
            input_string[i] = (input_string[i] - base + key_char) % 26 + base;
            j++;
        }
    }
}

//Function to decrypt the input string using a Vigenere Cipher
void vigenere_cipher_decrypt(char *input_string, char *key) {
    int i, j=0;
    int key_length = strlen(key);
    for(i=0; i<strlen(input_string); i++) {
        if(isalpha(input_string[i])) {
            char base = isupper(input_string[i]) ? 'A' : 'a';
            int key_index = j%key_length;
            char key_char = tolower(key[key_index]) - 'a';
            input_string[i] = (input_string[i] - base - key_char + 26) % 26 + base;
            j++;
        }
    }
}

int main() {
    printf("Enter your message: ");
    char input_string[1000];
    fgets(input_string, 1000, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; //removes newline character from the input string

    int choice;

    printf("Choose encryption method:\n1. Caesar Cipher\n2. Vigenere Cipher\n");
    scanf("%d", &choice);

    if(choice==1) {
        int key;
        printf("Enter encryption key (integer): ");
        scanf("%d", &key);
        caesar_cipher_encrypt(input_string, key);
        printf("Encrypted message: %s\n", input_string);
        caesar_cipher_decrypt(input_string, key);
        printf("Decrypted message: %s\n", input_string);
    }
    else if(choice==2) {
        char key[100];
        printf("Enter encryption key (string): ");
        scanf("%s", key);
        vigenere_cipher_encrypt(input_string, key);
        printf("Encrypted message: %s\n", input_string);
        vigenere_cipher_decrypt(input_string, key);
        printf("Decrypted message: %s\n", input_string);
    }
    else {
        printf("Invalid choice!\n");
        exit(0);
    }

    return 0;
}
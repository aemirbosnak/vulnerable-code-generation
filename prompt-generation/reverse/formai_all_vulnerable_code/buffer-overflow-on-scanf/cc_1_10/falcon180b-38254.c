//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_PLAIN_TEXT_SIZE 1024
#define MAX_CIPHER_TEXT_SIZE (MAX_PLAIN_TEXT_SIZE + 1)

// Define the Caesar cipher function
void caesar_cipher(char *plain_text, int key, char *cipher_text) {
    int i = 0;
    while (plain_text[i]!= '\0') {
        if (isalpha(plain_text[i])) {
            if (isupper(plain_text[i])) {
                cipher_text[i] = (char) ((int) plain_text[i] + key - 65);
            } else {
                cipher_text[i] = (char) ((int) plain_text[i] + key - 97);
            }
        } else {
            cipher_text[i] = plain_text[i];
        }
        i++;
    }
    cipher_text[i] = '\0';
}

// Define the main function
int main() {
    char plain_text[MAX_PLAIN_TEXT_SIZE];
    char cipher_text[MAX_CIPHER_TEXT_SIZE];
    int key;

    // Get the plain text from the user
    printf("Enter the plain text: ");
    fgets(plain_text, MAX_PLAIN_TEXT_SIZE, stdin);

    // Remove the newline character from the plain text
    plain_text[strcspn(plain_text, "\n")] = '\0';

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%d", &key);

    // Apply the Caesar cipher to the plain text
    caesar_cipher(plain_text, key, cipher_text);

    // Print the cipher text
    printf("The cipher text is: %s\n", cipher_text);

    return 0;
}
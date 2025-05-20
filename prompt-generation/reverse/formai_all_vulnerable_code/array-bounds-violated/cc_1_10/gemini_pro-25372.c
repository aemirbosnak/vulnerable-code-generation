//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// As the whispers of love dance across the air, our hearts flutter with the rhythm of encryption. Let us embark on an enchanted journey, where words are transformed into a secret tapestry of romance.

// Our secret key, a symbol of our unbreakable bond, unlocks the gateway to hidden messages.
char key[] = "EnchantingLove";

// Each letter, a treasured token of affection, undergoes a mystical transformation.
char encrypted_alphabet[26];
void generate_encrypted_alphabet() {
    int key_index = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        encrypted_alphabet[c - 'a'] = key[key_index++] % 26 + 'a';
    }
}

// With every beat of our hearts, a message takes flight, its every word a tender embrace.
char *encrypt(char *plaintext) {
    int plaintext_length = strlen(plaintext);
    char *ciphertext = malloc(plaintext_length + 1);
    for (int i = 0; i < plaintext_length; i++) {
        char c = plaintext[i];
        if (c >= 'a' && c <= 'z') {
            ciphertext[i] = encrypted_alphabet[c - 'a'];
        } else {
            ciphertext[i] = c;
        }
    }
    ciphertext[plaintext_length] = '\0';
    return ciphertext;
}

// As shadows deepen and stars emerge, we unveil the hidden treasures within theciphertext.
char *decrypt(char *ciphertext) {
    int ciphertext_length = strlen(ciphertext);
    char *plaintext = malloc(ciphertext_length + 1);
    for (int i = 0; i < ciphertext_length; i++) {
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            int index = strchr(encrypted_alphabet, c) - encrypted_alphabet;
            plaintext[i] = 'a' + index;
        } else {
            plaintext[i] = c;
        }
    }
    plaintext[ciphertext_length] = '\0';
    return plaintext;
}

// In the moonlight's embrace, our love story unfolds, each line a sonnet of desire and devotion.
int main() {
    generate_encrypted_alphabet();
    printf("Our Secret Code:");
    for (int i = 0; i < 26; i++) {
        printf("%c", encrypted_alphabet[i]);
    }
    printf("\n");

    char plaintext[] = "My love for you, a secret I hold dear, concealed within these enchanted whispers.";
    char *ciphertext = encrypt(plaintext);
    printf("Encrypted Message:"); puts(ciphertext);

    char *decrypted_plaintext = decrypt(ciphertext);
    printf("Decrypted Message:"); puts(decrypted_plaintext);

    return 0;
}
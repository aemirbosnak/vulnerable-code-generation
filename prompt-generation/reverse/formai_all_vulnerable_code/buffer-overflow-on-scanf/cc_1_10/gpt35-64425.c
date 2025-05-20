//FormAI DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {

    // Welcome message
    printf("Welcome to the Modern Encryption Code Puzzle!\n\n");

    // Ask for message input
    char message[100];
    printf("Please enter a secret message to encrypt: ");
    fgets(message, 100, stdin);

    // Key generation
    int key[100];
    for(int i=0; i<strlen(message); i++) {
        key[i] = (i*3)%26; // generate a key sequence based on message length
    }

    // Encryption
    char encrypted_message[100];
    for(int i=0; i<strlen(message); i++) {
        if (message[i] == ' ') { // ignore spaces
            encrypted_message[i] = ' ';
            continue;
        }
        int ascii_num = (int)message[i];
        ascii_num -= 65; // shift to match A=0
        int key_index = i%strlen(message);
        ascii_num += key[key_index];
        ascii_num %= 26;
        ascii_num += 65; // shift back to match A=65
        encrypted_message[i] = (char)ascii_num;
    }

    // Display encrypted message
    printf("Your encrypted message is: %s\n\n", encrypted_message);

    // Ask for decryption
    printf("Would you like to decrypt your message? (y/n): ");
    char answer;
    scanf("%c", &answer);
    getchar();

    if (answer == 'y') {

        // Decryption
        char decrypted_message[100];
        for(int i=0; i<strlen(encrypted_message); i++) {
            if (encrypted_message[i] == ' ') { // ignore spaces
                decrypted_message[i] = ' ';
                continue;
            }
            int ascii_num = (int)encrypted_message[i];
            ascii_num -= 65; // shift to match A=0
            int key_index = i%strlen(message);
            ascii_num -= key[key_index];
            if (ascii_num < 0) { // wrap around if needed
                ascii_num += 26;
            }
            ascii_num += 65; // shift back to match A=65
            decrypted_message[i] = (char)ascii_num;
        }

        // Display decrypted message
        printf("\nYour decrypted message is: %s\n", decrypted_message);
    }

    // Goodbye message
    printf("\nThank you for trying the Modern Encryption Code Puzzle!\n");

    return 0;
}
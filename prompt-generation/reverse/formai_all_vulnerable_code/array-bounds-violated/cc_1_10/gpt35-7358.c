//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * This is my top secret cryptography program that guarantees to keep your messages safe from prying eyes.
 * Just don't forget the secret key or you'll be lost in a maze of encrypted gibberish.
 */

int main(void) {
    char message[1000], key[1000];
    int choice, messageLength, keyLength, i, j;

    printf("Welcome to my top secret cryptography program!\n");
    printf("\nEnter your message: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEnter your secret key: ");
    fgets(key, sizeof(key), stdin);

    messageLength = strlen(message);
    keyLength = strlen(key);

    // Remove the new line character from the strings
    if (message[messageLength - 1] == '\n')
        message[messageLength - 1] = '\0';

    if (key[keyLength - 1] == '\n')
        key[keyLength - 1] = '\0';

    printf("\nWhat do you want to do with your message?\n");
    printf("(1) Encrypt\n");
    printf("(2) Decrypt\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);

    // Encryption process
    if (choice == 1) {
        for (i = 0; i < messageLength; i++) {
            message[i] += key[i % keyLength];
        }

        printf("\nYour encrypted message is: ");
        for (i = 0; i < messageLength; i++) {
            printf("%c", message[i]);
        }
        printf("\n");
    } 
    // Decryption process
    else if (choice == 2) {
        for (i = 0; i < messageLength; i++) {
            message[i] -= key[i % keyLength];
        }

        printf("\nYour decrypted message is: ");
        for (i = 0; i < messageLength; i++) {
            printf("%c", message[i]);
        }
        printf("\n");
    } 
    // Invalid choice
    else {
        printf("\nInvalid choice. Please try again.\n");
        return 1;
    }

    printf("\nThank you for using my top secret cryptography program!\n");
    return 0;
}
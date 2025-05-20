//FormAI DATASET v1.0 Category: modern Encryption ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 20 // key length

int main()
{
    char message[100]; // message to encrypt
    char encrypted[100]; // encrypted message
    char decrypted[100]; // decrypted message
    int key[KEY], i, j; // key array

    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message); // read entire string until newline

    // generate random key
    srand(time(NULL)); // seed with current time
    for (i = 0; i < KEY; i++) {
        key[i] = rand() % 26 + 1; // generate random number between 1 and 26
    }

    // encrypt message
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = ((message[i] - 'A' + key[j]) % 26) + 'A'; // modulo 26 to wrap around alphabet
            j = (j + 1) % KEY; // increment key index, wrap around if necessary
        } else {
            encrypted[i] = message[i]; // leave non-alphabet characters unchanged
        }
    }
    encrypted[i] = '\0'; // terminate string with null character

    // output encrypted message and key
    printf("Encrypted message: %s\n", encrypted);
    printf("Key: ");
    for (i = 0; i < KEY; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    // decrypt message
    for (i = 0, j = 0; i < strlen(encrypted); i++) {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A' - key[j] + 26) % 26) + 'A'; // add 26 to handle negative numbers
            j = (j + 1) % KEY; // increment key index, wrap around if necessary
        } else {
            decrypted[i] = encrypted[i]; // leave non-alphabet characters unchanged
        }
    }
    decrypted[i] = '\0'; // terminate string with null character

    // output decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
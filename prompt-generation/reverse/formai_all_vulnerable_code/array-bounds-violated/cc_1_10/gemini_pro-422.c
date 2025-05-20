//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: innovative
// Let's get this Enigma rolling!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret key for encoding and decoding
char key[] = "SECRET";

// The heart of the Enigma - the rotor
char rotor[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// A helper function to rotate the rotor
void rotateRotor() {
    char temp = rotor[0];
    for (int i = 0; i < 25; i++) {
        rotor[i] = rotor[i + 1];
    }
    rotor[25] = temp;
}

// The encoding function - transform a character using our key and rotor
char encode(char c) {
    int shift = key[c - 'A'];
    int index = (c - 'A' + shift + 26) % 26;
    return rotor[index];
}

// The decoding function - reverse the encoding process
char decode(char c) {
    int shift = key[c - 'A'];
    int index = (c - 'A' - shift + 26) % 26;
    return rotor[index];
}

// Let's put it to the test with a message
char message[] = "HELLOWORLD";

int main() {
    printf("Original message: %s\n", message);

    // Encryption time!
    char encrypted[strlen(message) + 1];
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = encode(message[i]);
    }
    encrypted[strlen(message)] = '\0';

    printf("Encrypted message: %s\n", encrypted);

    // Now let's crack the code
    char decrypted[strlen(encrypted) + 1];
    for (int i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = decode(encrypted[i]);
    }
    decrypted[strlen(encrypted)] = '\0';

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
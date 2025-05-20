//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generating random numbers for keys
    srand(time(NULL));
    int pubKey = rand() % 100 + 1;
    int privKey = rand() % 100 + 1;

    printf("Welcome to Public-Key Algorithm Implementation\n\n");

    printf("Your public key is %d\n", pubKey);
    printf("Your private key is %d\n\n", privKey);

    printf("Please enter a message to encrypt: ");
    char plainText[100];
    fgets(plainText, 100, stdin);

    // Encoding the message
    int encodedText[100];
    for (int i = 0; i < 100; i++) {
        if (plainText[i] == '\n') break;
        encodedText[i] = ((int) plainText[i] * pubKey) % 127;
    }

    printf("Your encoded message is: ");
    for (int i = 0; i < 100; i++) {
        if (encodedText[i] == 0) break;
        printf("%d ", encodedText[i]);
    }
    printf("\n\n");

    printf("Would you like to decrypt your message? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y') 
    {
        // Decoding the message
        char decodedText[100];
        for (int i = 0; i < 100; i++) {
            if (encodedText[i] == 0) break;
            decodedText[i] = (encodedText[i] * privKey) % 127;
        }

        printf("Your decoded message is: %s\n", decodedText);
    } 
    else 
    {
        printf("Okay, have a nice day!\n");
    }

    return 0;
}
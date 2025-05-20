//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to encrypt the message
void encrypt(char *message, int key) {
    int i, j;
    char encrypted_message[100];
    char temp_message[100];

    //Copy the message to a temporary string
    strcpy(temp_message, message);

    //Encrypt the message
    for (i = 0, j = 0; temp_message[i]!= '\0'; i++, j++) {
        if (isalpha(temp_message[i])) {
            encrypted_message[j] = toupper(temp_message[i] + key);
        } else {
            encrypted_message[j] = temp_message[i];
        }
    }
    encrypted_message[j] = '\0';

    //Print the encrypted message
    printf("Encrypted Message: %s\n", encrypted_message);
}

//Function to decrypt the message
void decrypt(char *message, int key) {
    int i, j;
    char decrypted_message[100];
    char temp_message[100];

    //Copy the message to a temporary string
    strcpy(temp_message, message);

    //Decrypt the message
    for (i = 0, j = 0; temp_message[i]!= '\0'; i++, j++) {
        if (isalpha(temp_message[i])) {
            decrypted_message[j] = temp_message[i] - key;
        } else {
            decrypted_message[j] = temp_message[i];
        }
    }
    decrypted_message[j] = '\0';

    //Print the decrypted message
    printf("Decrypted Message: %s\n", decrypted_message);
}

//Main function
int main() {
    char message[100];
    int key;

    //Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    //Get the key from the user
    printf("Enter the key: ");
    scanf("%d", &key);

    //Encrypt the message
    encrypt(message, key);

    //Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}
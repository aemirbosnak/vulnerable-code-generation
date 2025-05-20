//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
char* encrypt(char* message, int key) {
    char ch;
    int i;

    // Iterate through each character of the message
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
    }

    return message;
}

// Function to decrypt the message using Caesar cipher
char* decrypt(char* message, int key){
    char ch;
    int i;

    // Iterate through each character of the message
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
    }

    return message;
}

int main() {
    char message[50];
    int key, choice;

    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    printf("Select your choice:\n 1. Encrypt the message\n 2. Decrypt the message\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Encrypted message: %s", encrypt(message, key));
            break;
        case 2:
            printf("Decrypted message: %s", decrypt(message, key));
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}
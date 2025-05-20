//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 256

void generate_key(char *key) {
    int i;
    for(i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[SIZE] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[SIZE];

    for(i = 0; message[i]!= '\0'; i++) {
        encrypted_message[i] = message[i];
        if(isalpha(message[i])) {
            j = 0;
            while(key[j]!= '\0') {
                if(tolower(message[i]) == tolower(key[j])) {
                    encrypted_message[i] = key[j];
                    break;
                }
                j++;
            }
        }
    }

    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int i, j;
    char decrypted_message[SIZE];

    for(i = 0; message[i]!= '\0'; i++) {
        decrypted_message[i] = message[i];
        if(isalpha(message[i])) {
            j = 0;
            while(key[j]!= '\0') {
                if(tolower(message[i]) == tolower(key[j])) {
                    decrypted_message[i] = 'a' + (j % 26);
                    break;
                }
                j++;
            }
        }
    }

    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    srand(time(NULL));
    char message[SIZE];
    char key[SIZE];

    printf("Enter a message to be encrypted: ");
    scanf("%s", message);

    generate_key(key);
    encrypt(message, key);

    printf("Do you want to decrypt the message? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        decrypt(message, key);
    }

    return 0;
}
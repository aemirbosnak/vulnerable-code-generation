//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encrypt(char *message, int key) {
    int i;
    char encrypted[strlen(message) + 1];
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = message[i] + key;
            if(encrypted[i] > 'z') {
                encrypted[i] = encrypted[i] - 26;
            }
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = message[i] + key;
            if(encrypted[i] > 'Z') {
                encrypted[i] = encrypted[i] - 26;
            }
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[strlen(message)] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *message, int key) {
    int i;
    char decrypted[strlen(message) + 1];
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = message[i] - key;
            if(decrypted[i] < 'a') {
                decrypted[i] = decrypted[i] + 26;
            }
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = message[i] - key;
            if(decrypted[i] < 'A') {
                decrypted[i] = decrypted[i] + 26;
            }
        } else {
            decrypted[i] = message[i];
        }
    }
    decrypted[strlen(message)] = '\0';
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[1000];
    int choice, key;
    printf("Enter message to be encrypted: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            encrypt(message, key);
            break;
        case 2:
            decrypt(message, key);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}
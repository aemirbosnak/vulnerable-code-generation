//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_LEN 100
#define KEY_LEN 16

void encrypt(char* msg, char* key) {
    int i, j, k;
    char encrypted_msg[MAX_MSG_LEN];
    memset(encrypted_msg, 0, MAX_MSG_LEN);

    for(i=0,j=0; i<strlen(msg); i++,j++) {
        if(j == KEY_LEN) {
            j = 0;
        }
        encrypted_msg[i] = msg[i] ^ key[j];
    }

    printf("Encrypted message: %s\n", encrypted_msg);
}

void decrypt(char* encrypted_msg, char* key) {
    int i, j, k;
    char decrypted_msg[MAX_MSG_LEN];
    memset(decrypted_msg, 0, MAX_MSG_LEN);

    for(i=0,j=0; i<strlen(encrypted_msg); i++,j++) {
        if(j == KEY_LEN) {
            j = 0;
        }
        decrypted_msg[i] = encrypted_msg[i] ^ key[j];
    }

    printf("Decrypted message: %s\n", decrypted_msg);
}

int main() {
    char msg[MAX_MSG_LEN];
    char key[KEY_LEN];
    char choice;

    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", msg);

    srand(time(NULL));
    for(int i=0; i<KEY_LEN; i++) {
        key[i] = rand()%26 + 'A';
    }

    do {
        printf("\nChoose encryption or decryption:\n");
        printf("E - Encrypt\n");
        printf("D - Decrypt\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'E':
            case 'e':
                encrypt(msg, key);
                break;
            case 'D':
            case 'd':
                decrypt(msg, key);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'Q' && choice!= 'q');

    return 0;
}
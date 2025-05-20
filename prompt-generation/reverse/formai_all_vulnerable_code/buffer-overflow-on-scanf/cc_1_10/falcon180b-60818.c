//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char plaintext[100], ciphertext[100];
int key = 0;

void caesar_cipher(int mode) {
    int i, j;
    char ch;

    for(i = 0; plaintext[i]!= '\0'; i++) {
        ch = plaintext[i];

        if(isalpha(ch)) {
            if(mode == 1) {
                ch = toupper(ch);
            }

            if(isupper(ch)) {
                ch = (ch - 65 + key) % 26 + 65;
            } else {
                ch = (ch - 97 + key) % 26 + 97;
            }

            ciphertext[i] = ch;
        } else {
            ciphertext[i] = ch;
        }
    }

    ciphertext[i] = '\0';
}

void encrypt() {
    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    caesar_cipher(1);

    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt() {
    printf("Enter ciphertext: ");
    scanf("%s", ciphertext);

    caesar_cipher(0);

    printf("Plaintext: %s\n", plaintext);
}

int main() {
    int choice;

    do {
        printf("\n1. Encrypt\n2. Decrypt\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                encrypt();
                break;

            case 2:
                decrypt();
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}
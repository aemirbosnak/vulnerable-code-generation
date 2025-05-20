//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RC4 encryption function
void encrypt(char* plaintext, char* key) {
    int i, j, n, k;
    char S[256], T[256];
    int sbox[256];

    // initialize S and T
    for (i = 0; i < 256; i++) {
        S[i] = i;
        T[i] = i;
    }

    // generate S and T from key
    for (i = 0; i < 256; i++) {
        j = i;
        n = 0;
        k = S[j];
        while (j!= 0) {
            n = n + 1;
            k = k ^ S[j];
            j = (j + 1) & 255;
        }
        S[j] = k;
    }
    for (i = 0; i < 256; i++) {
        j = i;
        n = 0;
        k = T[j];
        while (j!= 0) {
            n = n + 1;
            k = k ^ T[j];
            j = (j + 1) & 255;
        }
        T[j] = k;
    }

    // encrypt plaintext using S and T
    for (i = 0; i < strlen(plaintext); i++) {
        j = (S[i] + T[i]) % 256;
        S[i] = S[j];
        T[i] = T[j];
        j = T[i];
        while (j!= i) {
            n = n + 1;
            j = (j + 1) % 256;
        }
        T[i] = S[j];
    }

    // convert S and T to hexadecimal and print encrypted text
    printf("Encrypted text: ");
    for (i = 0; i < strlen(plaintext); i++) {
        sprintf(T, "%02X", T[i]);
        printf("%c", T[i]);
    }
    printf("\n");
}

// main function
int main() {
    char plaintext[100];
    char key[100];

    // get plaintext and key from user
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter key: ");
    scanf("%s", key);

    // encrypt plaintext using RC4
    encrypt(plaintext, key);

    return 0;
}
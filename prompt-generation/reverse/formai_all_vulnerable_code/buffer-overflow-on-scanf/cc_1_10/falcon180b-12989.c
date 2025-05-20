//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

char plaintext[100];
char ciphertext[100];
char decryptedtext[100];

void *encrypt(void *param) {
    int i, j, k;
    char key[10];
    strcpy(key, "secretkey");
    for (i = 0, j = 0; plaintext[i]!= '\0'; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        ciphertext[i] = plaintext[i] ^ key[j];
    }
    ciphertext[i] = '\0';
    printf("Encrypted Text: %s\n", ciphertext);
}

void *decrypt(void *param) {
    int i, j, k;
    char key[10];
    strcpy(key, "secretkey");
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        decryptedtext[i] = ciphertext[i] ^ key[j];
    }
    decryptedtext[i] = '\0';
    printf("Decrypted Text: %s\n", decryptedtext);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    printf("Enter Plaintext: ");
    scanf("%s", plaintext);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, encrypt, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, decrypt, NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
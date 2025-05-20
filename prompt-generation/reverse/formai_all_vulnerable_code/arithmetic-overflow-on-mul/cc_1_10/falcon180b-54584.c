//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define PRIME 101
#define BASE 57

void generate_keys(int *public_key, int *private_key) {
    int i, j, found = 0;
    for (i = 2; i < MAX; i++) {
        for (j = 2; j < MAX; j++) {
            if ((i * j) % PRIME == 1) {
                *public_key = i;
                *private_key = j;
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
}

int encrypt(int message, int public_key) {
    return (message * public_key) % MAX;
}

int decrypt(int cipher, int private_key) {
    return (cipher * private_key) % MAX;
}

int main() {
    int public_key, private_key, message, cipher, choice;

    generate_keys(&public_key, &private_key);

    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Encrypt message\n");
        printf("2. Decrypt cipher\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter message to encrypt: ");
                scanf("%d", &message);
                cipher = encrypt(message, public_key);
                printf("Encrypted message: %d\n", cipher);
                break;
            case 2:
                printf("Enter cipher to decrypt: ");
                scanf("%d", &cipher);
                message = decrypt(cipher, private_key);
                printf("Decrypted message: %d\n", message);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
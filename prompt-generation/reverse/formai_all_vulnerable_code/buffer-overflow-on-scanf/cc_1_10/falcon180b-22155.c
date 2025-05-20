//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LEN 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LEN; i++) {
        key[i] = (char) (rand() % 26 + 'a');
    }
    key[MAX_KEY_LEN] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i])? 'A' : 'a';
            message[i] = (char) (((message[i] - base + key[j]) % 26) + base);
            j = (j + 1) % MAX_KEY_LEN;
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i])? 'A' : 'a';
            message[i] = (char) (((message[i] - base - key[j]) % 26) + base);
            j = (j + 1) % MAX_KEY_LEN;
        }
    }
}

int main() {
    char message[1000];
    char key[MAX_KEY_LEN + 1];
    int choice;

    srand(time(NULL));
    generate_key(key);

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Encrypted message: ");
    encrypt(message, key);
    puts(message);

    printf("Enter a choice:\n1. Decrypt the message\n2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        decrypt(message, key);
        puts("Decrypted message: ");
        puts(message);
    }

    return 0;
}
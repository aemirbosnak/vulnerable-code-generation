//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_keys(char* public_key, char* private_key) {
    int p = 13, q = 17;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 7;
    int d = 23;

    // convert integers to strings
    sprintf(public_key, "%d,%d", n, e);
    sprintf(private_key, "%d,%d", n, d);
}

void encrypt(char* message, char* public_key, char* encrypted_message) {
    // extract n and e from public key
    char* token;
    int n, e;

    // get first token
    token = strtok(public_key, ",");
    n = atoi(token);

    // get second token
    token = strtok(NULL, ",");
    e = atoi(token);

    // encrypt message using public key
    for (int i = 0; i < strlen(message); i++) {
        int c = (int) message[i];
        int m = 1;

        // perform modular exponentiation
        for (int j = 0; j < e; j++) {
            m = (m * c) % n;
        }

        // add encrypted character to encrypted message string
        sprintf(encrypted_message, "%s%d_", encrypted_message, m);
    }
}

void decrypt(char* encrypted_message, char* private_key, char* decrypted_message) {
    // extract n and d from private key
    char* token;
    int n, d;

    // get first token
    token = strtok(private_key, ",");
    n = atoi(token);

    // get second token
    token = strtok(NULL, ",");
    d = atoi(token);

    // decrypt message using private key
    char* token2;
    int c;
    char* tmp = strtok_r(encrypted_message, "_", &token2);
    while (tmp != NULL) {
        c = atoi(tmp);
        int m = 1;

        // perform modular exponentiation
        for (int j = 0; j < d; j++) {
            m = (m * c) % n;
        }

        // add decrypted character to decrypted message string
        sprintf(decrypted_message, "%s%c", decrypted_message, (char) m);

        tmp = strtok_r(NULL, "_", &token2);
    }
}

int main() {
    char public_key[50] = "";
    char private_key[50] = "";
    char message[100] = "";
    char encrypted_message[100] = "";
    char decrypted_message[100] = "";

    // generate public and private keys
    generate_keys(public_key, private_key);

    // get message from user
    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);

    // encrypt message
    encrypt(message, public_key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    // decrypt message
    decrypt(encrypted_message, private_key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}
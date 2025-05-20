//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 256

typedef struct {
    unsigned char pubKey[64];
    unsigned char privKey[64];
} keyPair;

void generateKeys(keyPair *keys) {
    unsigned char randBytes[32];
    unsigned char modBytes[32];

    if (keys == NULL)
        return;

    srand(time(NULL));

    for (int i = 0; i < 32; i++) {
        randBytes[i] = rand() % 256;
    }

    for (int i = 0; i < 32; i++) {
        modBytes[i] = randBytes[i] % MOD;
    }

    keys->pubKey[0] = modBytes[0];
    keys->pubKey[1] = modBytes[1];
    keys->pubKey[2] = modBytes[2];
    keys->pubKey[3] = modBytes[3];
    keys->pubKey[4] = modBytes[4];
    keys->pubKey[5] = modBytes[5];
    keys->pubKey[6] = modBytes[6];
    keys->pubKey[7] = modBytes[7];
    keys->pubKey[8] = modBytes[8];
    keys->pubKey[9] = modBytes[9];
    keys->pubKey[10] = modBytes[10];
    keys->pubKey[11] = modBytes[11];
    keys->pubKey[12] = modBytes[12];
    keys->pubKey[13] = modBytes[13];
    keys->pubKey[14] = modBytes[14];
    keys->pubKey[15] = modBytes[15];
    keys->pubKey[16] = modBytes[16];
    keys->pubKey[17] = modBytes[17];
    keys->pubKey[18] = modBytes[18];
    keys->pubKey[19] = modBytes[19];
    keys->pubKey[20] = modBytes[20];
    keys->pubKey[21] = modBytes[21];
    keys->pubKey[22] = modBytes[22];
    keys->pubKey[23] = modBytes[23];
    keys->pubKey[24] = modBytes[24];
    keys->pubKey[25] = modBytes[25];
    keys->pubKey[26] = modBytes[26];
    keys->pubKey[27] = modBytes[27];
    keys->pubKey[28] = modBytes[28];
    keys->pubKey[29] = modBytes[29];
    keys->pubKey[30] = modBytes[30];
    keys->pubKey[31] = modBytes[31];

    for (int i = 0; i < 32; i++) {
        keys->privKey[i] = randBytes[i] % MOD;
    }
}

void encrypt(char *message, keyPair *keys) {
    unsigned char cipherText[strlen(message) + 1];
    unsigned char exponent[32];
    unsigned char modMult[32];
    unsigned char result[32];

    for (int i = 0; i < 32; i++) {
        exponent[i] = keys->pubKey[i];
    }

    for (int i = 0; i < strlen(message); i++) {
        cipherText[i] = message[i] - 'A' + 1;
    }

    for (int i = 0; i < 32; i++) {
        modMult[i] = cipherText[i] * exponent[i];
    }

    for (int i = 0; i < 32; i++) {
        result[i] = modMult[i] % MOD;
    }

    printf("Cipher Text: %s\n", result);
}

void decrypt(char *cipherText, keyPair *keys) {
    unsigned char plainText[strlen(cipherText) + 1];
    unsigned char exponent[32];
    unsigned char modMult[32];
    unsigned char result[32];

    for (int i = 0; i < 32; i++) {
        exponent[i] = keys->privKey[i];
    }

    for (int i = 0; i < strlen(cipherText); i++) {
        plainText[i] = cipherText[i] - 'A' + 1;
    }

    for (int i = 0; i < 32; i++) {
        modMult[i] = plainText[i] * exponent[i];
    }

    for (int i = 0; i < 32; i++) {
        result[i] = modMult[i] % MOD;
    }

    printf("Plain Text: %s\n", result);
}

int main() {
    keyPair keys;
    generateKeys(&keys);

    char message[] = "HELLO WORLD";
    encrypt(message, &keys);

    char cipherText[] = "GJNSNZAM";
    decrypt(cipherText, &keys);

    return 0;
}
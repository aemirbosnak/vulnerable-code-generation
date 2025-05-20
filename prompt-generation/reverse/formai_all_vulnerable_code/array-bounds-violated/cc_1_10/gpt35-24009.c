//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCKSIZE 128
#define KEYSIZE 64
#define ENCRYPT_ROUNDS 16
#define DECRYPT_ROUNDS 16

unsigned char S[BLOCKSIZE], K[KEYSIZE], C[BLOCKSIZE], P[BLOCKSIZE], T[BLOCKSIZE];
unsigned char SK[KEYSIZE], SC[BLOCKSIZE], SP[BLOCKSIZE], ST[BLOCKSIZE];
unsigned char temp[BLOCKSIZE], temp2[BLOCKSIZE], temp3[BLOCKSIZE], temp4[BLOCKSIZE];

unsigned int L[BLOCKSIZE/32];

void encrypt() {
    int i, j;

    for (i = 0; i < BLOCKSIZE; i++) {
        S[i] ^= P[i];
    }

    for (j = 0; j < ENCRYPT_ROUNDS; j++) {
        for (i = 0; i < BLOCKSIZE; i++) {
            S[i] ^= K[i % KEYSIZE];
        }

        for (i = 0; i < BLOCKSIZE; i++) {
            temp[i] = S[i];
        }

        for (i = 0; i < BLOCKSIZE/32; i++) {
            L[i] = *(unsigned int *)(temp+i*4);
        }

        for (i = 0; i < BLOCKSIZE/32; i++) {
            temp3[i*4] = (L[i] >> 24) & 0xff;
            temp3[i*4+1] = (L[i] >> 16) & 0xff;
            temp3[i*4+2] = (L[i] >> 8) & 0xff;
            temp3[i*4+3] = L[i] & 0xff;
        }

        for (i = 0; i < BLOCKSIZE; i++) {
            temp2[i] = temp3[i];
        }

        for (i = 0; i < BLOCKSIZE/2; i++) {
            temp4[i*2] = temp2[i];
            temp4[i*2+1] = temp2[i+BLOCKSIZE/2];
        }

        for (i = 0; i < BLOCKSIZE; i++) {
            S[i] = temp4[i];
        }
    }

    for (i = 0; i < BLOCKSIZE; i++) {
        C[i] = S[i];
    }
}

void decrypt() {
    int i, j;

    for (i = 0; i < BLOCKSIZE; i++) {
        S[i] = C[i];
    }

    for (j = 0; j < DECRYPT_ROUNDS; j++) {
        for (i = 0; i < BLOCKSIZE/2; i++) {
            temp2[i] = S[i];
            temp2[i+BLOCKSIZE/2] = S[i+BLOCKSIZE/2];   
        }

        for (i = 0; i < BLOCKSIZE; i++) {
            temp4[(i/2) + (i%2)*(BLOCKSIZE/2)] = temp2[i];
        }

        for (i = 0; i < BLOCKSIZE/32; i++) {
            *(unsigned int *)(temp3+i*4) = L[i];
        }

        for (i = 0; i < BLOCKSIZE; i++) {
            S[i] = temp3[i];
        }

        for (i = 0; i < BLOCKSIZE; i++) {
            S[i] ^= K[i % KEYSIZE];
        }
    }

    for (i = 0; i < BLOCKSIZE; i++) {
        P[i] = S[i] ^ temp[i];
    }
}

int main(int argc, char *argv[]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < BLOCKSIZE; i++) {
        S[i] = i;
        K[i] = rand()%256;
        P[i] = rand()%256;
    }
    printf("Key: ");
    for (i = 0; i < KEYSIZE; i++) {
        printf("%02X", K[i]);
    }
    printf("\n");
    printf("Plain: ");
    for (i = 0; i < BLOCKSIZE; i++) {
        printf("%02X", P[i]);
    }
    printf("\n");
    encrypt();
    printf("Cipher: ");
    for (i = 0; i < BLOCKSIZE; i++) {
        printf("%02X", C[i]);
    }
    printf("\n");
    decrypt();
    printf("Decrypted: ");
    for (i = 0; i < BLOCKSIZE; i++) {
        printf("%02X", P[i]);
    }
    printf("\n");
    return 0;
}
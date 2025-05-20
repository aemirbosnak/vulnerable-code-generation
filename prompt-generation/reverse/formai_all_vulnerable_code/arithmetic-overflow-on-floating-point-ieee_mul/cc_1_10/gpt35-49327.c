//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Function to generate keys */
void key_generation(int p, int q, int *n, int *phi, int *e, int *d)
{
    /* Calculate n */
    *n = p * q;

    /* Calculate Phi(n) */
    *phi = (p-1) * (q-1);

    /* Find e, such that gcd(e,Phi(n)) = 1 */
    int i;
    for(i=2; i<*phi; i++) {
        if((*phi % i) != 0) {
            *e = i;
            break;
        }
    }

    /* Calculate d, such that (d*e) mod Phi(n) = 1 */
    int k = 1;
    while(1) {
        k += *phi;
        if((k % *e) == 0) {
            *d = k / *e;
            break;
        }
    }
}

/* Function to encrypt the message using public key */
void encrypt(int *pt, int *ct, int n, int e, int len)
{
    int i;
    for(i=0; i<len; i++) {
        ct[i] = (int)(pow(pt[i], e)) % n;
    }
}

/* Function to decrypt the message using private key */
void decrypt(int *ct, int *pt, int n, int d, int len)
{
    int i;
    for(i=0; i<len; i++) {
        pt[i] = (int)(pow(ct[i], d)) % n;
    }
}

/* Main function */
int main()
{
    int p = 23, q = 17, n, phi, e, d;
    int plaintext[] = {12, 4, 7, 3, 16, 5, 1, 11, 14, 8, 9};
    int ciphertext[11], decryptedtext[11];

    /* Generate keys */
    key_generation(p, q, &n, &phi, &e, &d);

    /* Encrypt the plaintext */
    encrypt(plaintext, ciphertext, n, e, 11);

    /* Decrypt the ciphertext */
    decrypt(ciphertext, decryptedtext, n, d, 11);

    /* Print the plaintext and decryptedtext */
    printf("Plaintext: ");
    for(int i=0; i<11; i++) {
        printf("%d ", plaintext[i]);
    }
    printf("\nDecryptedtext: ");
    for(int i=0; i<11; i++) {
        printf("%d ", decryptedtext[i]);
    }
    printf("\n");

    return 0;
}
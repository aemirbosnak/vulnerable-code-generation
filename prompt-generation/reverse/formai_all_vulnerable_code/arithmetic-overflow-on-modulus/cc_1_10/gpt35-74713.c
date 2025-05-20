//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

int prime(int num) { //function to check if a number is prime or not
    int i;
    for(i=2; i<=num/2; i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) { //function to find the greatest common divisor of two numbers
    while(a!=b) {
        if(a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

int publicKey(int phi) { //function to generate the public key
    int e;
    for(e=2; e<phi; e++) {
        if(gcd(e, phi) == 1 && prime(e) == 1) {
            return e;
        }
    }
}

int privateKey(int e, int phi) { //function to generate the private key
    int d = 1;
    while((d*e)%phi != 1 || d == e) { //condition for d to be valid
        d++;
    }
    return d;
}

void encrypt(int *msg, int msgLen, int e, int n, int *cipher) { //function to encrypt the message
    int i;
    for(i=0; i<msgLen; i++) {
        cipher[i] = (int)pow(msg[i], e) % n;
    }
}

void decrypt(int *cipher, int msgLen, int d, int n, int *msg) { //function to decrypt the message
    int i;
    for(i=0; i<msgLen; i++) {
        msg[i] = (int)pow(cipher[i], d) % n;
    }
}

int main() {
    int p, q, n, phi, e, d, msg[MAX], cipher[MAX], decrypted[MAX], i, msgLen;
    printf("Enter two prime numbers:\n");
    scanf("%d %d", &p, &q);
    n = p * q; //calculating n
    phi = (p-1) * (q-1); //calculating phi
    srand(time(0)); //seeding the random number generator
    e = publicKey(phi); //generating the public key
    d = privateKey(e, phi); //generating the private key
    printf("Public key: (%d, %d)\n", e, n); //printing out the public key
    printf("Private key: (%d, %d)\n", d, n); //printing out the private key
    printf("Enter the message to be encrypted:\n");
    getchar(); //clearing the input buffer
    scanf("%[^\n]s", msg); //reading the entire line as input
    msgLen = strlen(msg); //calculating the length of the message
    encrypt(msg, msgLen, e, n, cipher); //encrypting the message
    printf("Encrypted message: ");
    for(i=0; i<msgLen; i++) {
        printf("%d ", cipher[i]); //printing out the encrypted message
    }
    printf("\n");
    decrypt(cipher, msgLen, d, n, decrypted); //decrypting the message
    printf("Decrypted message: ");
    for(i=0; i<msgLen; i++) {
        printf("%c", decrypted[i]); //printing out the decrypted message
    }
    printf("\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>

/* Function declarations */
int power(int num, unsigned int exp, int mod);
int gcd(int a, int b);
int findPrivateKey(int publicKey, int totient);
int encrypt(int msg, int publicKey, int n);
int decrypt(int encMsg, int privateKey, int n);

int main() {
    int p = 61; // first prime number
    int q = 53; // second prime number
    int n = p * q; // calculate n
    int totient = (p-1) * (q-1); // calculate totient

    int publicKey;
    do {
        printf("Enter the value of public key (0 < publicKey < %d) which is co-prime to %d: ", totient, totient);
        scanf("%d", &publicKey);
    } while (gcd(publicKey, totient) != 1);

    int privateKey = findPrivateKey(publicKey, totient);
    printf("Private Key : %d\n", privateKey);

    // encrypting message
    int msg;
    printf("Enter the message to be encrypted: ");
    scanf("%d", &msg);
    int encMsg = encrypt(msg, publicKey, n);
    printf("Encrypted message : %d\n", encMsg);

    // decrypting message
    int decMsg = decrypt(encMsg, privateKey, n);
    printf("Decrypted message : %d\n", decMsg);

    return 0;
}

// function to calculate power of a number modulo mod
int power(int num, unsigned int exp, int mod) {
    int res = 1;
    num = num % mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res*num) % mod;
        exp = exp>>1;
        num = (num*num) % mod;
    }
    return res;
}

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// function to calculate private key using extended euclidean algorithm
int findPrivateKey(int publicKey, int totient) {
    int a = totient, b = publicKey, x = 1, y = 0;
    while (b > 0)
    {
        int q = a/b;
        int t = b;
        b = a%b;
        a = t;
        t = y;
        y = x - q*y;
        x = t;
    }
    if (x < 0) x += totient;
    return x;
}

// function to encrypt message using public key and n
int encrypt(int msg, int publicKey, int n) {
    return power(msg, publicKey, n);
}

// function to decrypt message using private key and n
int decrypt(int encMsg, int privateKey, int n)
{
    return power(encMsg, privateKey, n);
}
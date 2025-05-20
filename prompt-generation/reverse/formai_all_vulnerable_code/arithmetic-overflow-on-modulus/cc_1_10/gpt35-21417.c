//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to find greatest common divisor using Euclidean algorithm
int gcd(int a, int b) {
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

//function to find multiplicative inverse of a mod m
int inverse(int a, int m) {
    a = a%m;
    for(int i = 1; i < m; i++)
        if((a * i) % m == 1)
            return i;
    return 0;
}

//function to find modular exponential using repeated squaring
int mod_exp(int base, int exponent, int mod) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1)
            result = (result*base) % mod;
        base = (base*base) % mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    int p, q, n, phi, e, d, plaintext, ciphertext, decryptedtext;
    
    //take user input for two prime numbers
    printf("Enter two prime numbers p and q: ");
    scanf("%d %d", &p, &q);
    
    //calculate n and phi of n
    n = p*q;
    phi = (p-1)*(q-1);
    
    //take user input for public key e
    printf("Enter public key e (1 < e < %d and gcd(e, %d) = 1): ", phi, phi);
    scanf("%d", &e);
    
    //check if public key is valid
    if(gcd(e, phi) != 1 || e >= phi) {
        printf("Invalid public key!\n");
        exit(0);
    }
    
    //calculate private key d
    d = inverse(e, phi);
    
    printf("\nPublic key: %d\nPrivate key: %d\n", e, d);
    
    //take user input for plaintext message
    printf("Enter plaintext message: ");
    scanf("%d", &plaintext);
    
    //encrypt plaintext message
    ciphertext = mod_exp(plaintext, e, n);
    printf("\nEncrypted message: %d\n", ciphertext);
    
    //decrypt ciphertext message
    decryptedtext = mod_exp(ciphertext, d, n);
    printf("Decrypted message: %d\n", decryptedtext);
    
    return 0;
}
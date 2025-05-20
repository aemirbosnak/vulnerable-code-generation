//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include<stdio.h>
#include<math.h>

// Function to calculate GCD
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

// Function to calculate only public key
int generatePublicKey(int p, int q, int e) {
    int n = p*q; // calculate value of n
    int phi = (p - 1)*(q - 1); // Calculate the value of phi

    // Check if e and phi are coprime
    if(gcd(phi, e) != 1) {
        return -1;
    }

    return e;
}

// Function to calculate both public and private key
int generateKeyPair(int p, int q, int e, int* privateKey) {
    int n = p*q; // calculate value of n
    int phi = (p - 1)*(q - 1); // Calculate the value of phi 

    // Check if e and phi are coprime
    if(gcd(phi, e) != 1) {
        return -1;
    }

    int k = 1;
    int d = (1 + (k * phi)) / e; // Calculate value of d

    while(d*e % phi != 1 || d <= e) {
        k++;
        d = (1 + (k * phi)) / e;
    }

    *privateKey = d;
    return e;
}

int main() {
    int p, q, e, privateKey;
    printf("Enter the value of p: ");
    scanf("%d", &p);
    printf("Enter the value of q: ");
    scanf("%d", &q);
    printf("Enter the value of e: ");
    scanf("%d", &e);

    int publicKey = generateKeyPair(p, q, e, &privateKey);

    if(publicKey == -1) {
        printf("Invalid parameters! Could not generate key pair.");
    } else {
        printf("Public key = %d\nPrivate key = %d", publicKey, privateKey);
    }

    return 0;
}
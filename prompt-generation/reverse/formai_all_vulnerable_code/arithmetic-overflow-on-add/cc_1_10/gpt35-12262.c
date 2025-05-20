//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
/*
This program uses the public-key algorithm to encrypt a message with a provided public key 
and then decrypt it using a corresponding private key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function for checking if a number is prime
int isPrime(int num) {
    int i;
    for(i=2; i<=(int)sqrt(num); i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function for generating a random prime number
int generatePrime() {
    int num = rand() % 100 + 1;
    while(!isPrime(num)) {
        num = rand() % 100 + 1;
    }
    return num;
}

// Function for finding the greatest common divisor of two numbers
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

// Function for finding the private key given a public key and the two prime numbers used to generate it
int findPrivateKey(int pubKey, int prime1, int prime2) {
    int n = (prime1-1) * (prime2-1);
    int i;
    for(i=2; i<n; i++) {
        if(gcd(i, n) == 1 && ((i*pubKey) % n) == 1) {
            return i; 
        }
    }
}

int main() {
    // Generate two prime numbers
    srand(time(NULL));
    int prime1 = generatePrime();
    int prime2 = generatePrime();
    
    // Calculate n and phi(n)
    int n = prime1 * prime2;
    int phi = (prime1-1) * (prime2-1);
    
    // Generate public key e
    int e = rand() % ((phi-1) - 2 + 1) + 2;
    while(gcd(e, phi) != 1) {
        e = rand() % ((phi-1) - 2 + 1) + 2;
    }
    
    // Calculate private key d
    int d = findPrivateKey(e, prime1, prime2);
    
    // Print out the public and private keys along with the prime numbers used to generate them
    printf("Public Key (e): %d\nPrivate Key (d): %d\nPrime Number 1: %d\nPrime Number 2: %d\n", e, d, prime1, prime2);
    
    // Get a message to encrypt
    printf("Enter a message to encrypt: ");
    char message[100];
    fgets(message, 100, stdin);
    
    // Encrypt the message
    int i;
    int encrypted[100];
    int decrypted[100];
    for(i=0; i<strlen(message); i++) {
        if(message[i] == ' ') {
            encrypted[i] = (int)' ';
            decrypted[i] = (int)' ';
            continue;
        }
        int num = ((int)message[i] - 96); // Convert the letter to a number (a=1, b=2, etc.)
        encrypted[i] = (int)pow(num, e) % n; // Apply the public key to the number
        decrypted[i] = (int)pow(encrypted[i], d) % n; // Apply the private key to the encrypted number
    }
    printf("Encrypted Message: ");
    for(i=0; i<strlen(message); i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\nDecrypted Message: ");
    for(i=0; i<strlen(message); i++) {
        if(encrypted[i] == (int)' ') {
            printf("%c", (char)encrypted[i]);
            continue;
        }
        int num = (int)sqrt(decrypted[i]) + 96; // Reverse the number to its corresponding letter
        printf("%c", (char)num);
    }
    printf("\n");
    
    return 0;
}
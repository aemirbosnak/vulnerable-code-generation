//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random prime number
int isPrime(int num) {
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));

    // Generate two large prime numbers
    int p = rand() % 1000 + 1;
    int q = rand() % 1000 + 1;

    // Ensure p and q are prime
    while (!isPrime(p) ||!isPrime(q)) {
        p = rand() % 1000 + 1;
        q = rand() % 1000 + 1;
    }

    // Calculate n = p * q
    int n = p * q;

    // Calculate totient of n
    int phi_n = (p - 1) * (q - 1);

    // Choose a random number e such that 1 < e < phi_n and e is coprime to phi_n
    int e = rand() % (phi_n - 1) + 1;

    // Calculate d such that d * e = 1 mod phi_n using the extended Euclidean algorithm
    int d = 0;
    int x = 0, y = 1;
    while (e!= 0) {
        int temp = d;
        d = e;
        e = temp % e;
        x = x - y * (temp / e);
    }

    // Output the public key (n, e) and private key (n, d)
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    return 0;
}
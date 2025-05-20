//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 10

typedef struct {
    int value;
    char *word;
} WordPair;

void generate_key_pair(int *public_key, int *private_key) {
    srand(time(NULL));

    // Generate two large prime numbers
    int prime1 = rand() % 100000 + 1;
    int prime2 = rand() % 100000 + 1;

    // Calculate n = p * q
    int n = prime1 * prime2;

    // Calculate totient function of n
    int phi_n = (prime1 - 1) * (prime2 - 1);

    // Choose a random number e such that 1 < e < phi_n and e is coprime to phi_n
    int e = rand() % phi_n + 2;
    while (gcd(e, phi_n)!= 1) {
        e = rand() % phi_n + 2;
    }

    // Calculate d such that d * e = 1 mod phi_n
    int d = gcd_ext(e, phi_n);

    // Public key: (n, e)
    public_key[0] = n;
    public_key[1] = e;

    // Private key: (n, d)
    private_key[0] = n;
    private_key[1] = d;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int gcd_ext(int a, int b) {
    int x, y;
    int gcd_result = gcd(a, b);
    x = a / gcd_result;
    y = b / gcd_result;
    return gcd(x, y);
}

int main() {
    int public_key[2];
    int private_key[2];

    generate_key_pair(public_key, private_key);

    printf("Public key: (%d, %d)\n", public_key[0], public_key[1]);
    printf("Private key: (%d, %d)\n", private_key[0], private_key[1]);

    return 0;
}
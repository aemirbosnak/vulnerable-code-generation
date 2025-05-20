//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

typedef struct {
    int a, b;
    int x, y;
} PublicKey;

PublicKey generate_key() {
    PublicKey key;
    int gcd_result;
    int a = rand() % MAX + 2;
    int b = rand() % (MAX - 2) + 1;

    while (gcd(a, b) == 1) {
        a = rand() % MAX + 2;
        b = rand() % (MAX - 2) + 1;
    }

    key.a = a;
    key.b = b;
    key.x = (b * (key.a - 1)) % key.b;
    key.y = ((key.a - 1) * key.x) % key.b;

    return key;
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

int main() {
    srand(time(NULL));

    PublicKey public_key = generate_key();
    int message = 42;

    int encrypted_message = (public_key.a * message) % public_key.b;

    printf("Public key: (%d, %d)\n", public_key.a, public_key.b);
    printf("Encrypted message: %d\n", encrypted_message);

    return 0;
}
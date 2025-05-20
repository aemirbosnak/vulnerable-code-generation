//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 10000

typedef struct {
    int p;
    int q;
    int n;
    int e;
    int d;
} key_pair;

key_pair generate_key_pair(int p, int q, int e) {
    key_pair key_pair;

    key_pair.p = p;
    key_pair.q = q;
    key_pair.n = p*q;
    key_pair.e = e;
    key_pair.d = modInverse(e, p-1);

    return key_pair;
}

int modInverse(int a, int m) {
    int x, y, z;
    x = 0;
    y = 1;
    while (a > 1) {
        if (a % 2 == 1) {
            z = m - a;
            x = y;
            y = z;
        }
        a = a/2;
    }
    return y;
}

int main() {
    int p, q, e;
    printf("Enter the prime numbers p and q: ");
    scanf("%d %d", &p, &q);
    printf("Enter the value of e: ");
    scanf("%d", &e);

    key_pair key_pair = generate_key_pair(p, q, e);
    printf("Public key: n=%d, e=%d\n", key_pair.n, key_pair.e);
    printf("Private key: d=%d\n", key_pair.d);

    return 0;
}
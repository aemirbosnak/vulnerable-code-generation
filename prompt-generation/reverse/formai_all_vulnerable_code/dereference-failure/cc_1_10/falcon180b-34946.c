//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct {
    int a;
    int b;
} Point;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int modpow(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

Point *generate_key() {
    Point *key = malloc(sizeof(Point));
    key->a = rand() % 10000 + 1;
    key->b = rand() % 10000 + 1;
    return key;
}

int *encrypt(Point *key, int message) {
    Point *point = malloc(sizeof(Point));
    point->a = message;
    point->b = 0;

    int *result = malloc(sizeof(int));
    result[0] = modpow(key->a, message, key->b);
    result[1] = modpow(key->b, message, key->a);

    free(point);
    return result;
}

int decrypt(Point *key, int *encrypted_message) {
    int message = modpow(encrypted_message[0], key->b, key->a);
    int temp = modpow(encrypted_message[1], key->a - 1, key->b);
    int result = (message * temp) % key->b;
    return result;
}

int main() {
    srand(time(NULL));

    Point *key = generate_key();
    int message = 12345;

    int *encrypted_message = encrypt(key, message);
    int decrypted_message = decrypt(key, encrypted_message);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d %d\n", encrypted_message[0], encrypted_message[1]);
    printf("Decrypted message: %d\n", decrypted_message);

    free(encrypted_message);
    free(key);
    return 0;
}
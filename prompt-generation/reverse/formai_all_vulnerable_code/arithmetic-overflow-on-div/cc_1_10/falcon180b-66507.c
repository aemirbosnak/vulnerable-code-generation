//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_PRIME 1000

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int primes[], int size) {
    int count = 0;
    for (int i = 2; count < size; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
        }
    }
}

int main() {
    int message_size, prime_size;
    char message[MAX_SIZE];
    int primes[MAX_PRIME];
    int key;

    printf("Enter message size: ");
    scanf("%d", &message_size);

    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter prime size: ");
    scanf("%d", &prime_size);

    generate_primes(primes, prime_size);

    key = primes[rand() % prime_size];

    int encrypted_message_size = message_size / key + ((message_size % key)? 1 : 0);
    char encrypted_message[encrypted_message_size];

    int j = 0;
    for (int i = 0; i < message_size; i += key) {
        encrypted_message[j++] = message[i] ^ (key % 256);
    }

    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}
//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to check if the number is prime or not
int is_prime(int num) {
    if(num < 2)
        return 0;
    for(int i=2; i<=num/2; i++) {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

// function to find the greatest common divisor
int gcd(int num1, int num2) {
    if(num1 == 0)
        return num2;
    else
        return gcd(num2 % num1, num1);
}

// function to find modular inverse
int modular_inverse(int num, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if(m == 1)
        return 0;
    while(num > 1) {
        q = num / m;
        t = m;
        m = num % m;
        num = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if(x1 < 0)
        x1 += m0;
    return x1;
}

// function to generate the key pair
void generate_key_pair(int prime1, int prime2, int *public_key, int *private_key) {
    int n = prime1 * prime2;
    int phi = (prime1 - 1) * (prime2 - 1);
    int e, d;
    do {
        e = rand() % phi + 1;
    } while(gcd(e, phi) != 1);
    d = modular_inverse(e, phi);
    *public_key = e;
    *private_key = d;
}

int main() {
    srand(time(NULL));
    int prime1, prime2, public_key, private_key;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &prime1, &prime2);
    if(!is_prime(prime1) || !is_prime(prime2))
        printf("Invalid input. Both numbers should be prime.\n");
    else {
        generate_key_pair(prime1, prime2, &public_key, &private_key);
        printf("Public key: %d\nPrivate key: %d\n", public_key, private_key);
    }
    return 0;
}
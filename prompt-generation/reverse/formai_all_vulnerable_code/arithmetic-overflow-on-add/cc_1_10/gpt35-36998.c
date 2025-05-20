//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Generate random prime number
int generate_prime_number(){
    int num;
    srand(time(NULL) + getpid()); // Seed random number generator
    num = rand() % 1000 + 1; // Generate random number between 1 and 1000
    if(num < 2)
        num += 2;
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            num++;
            i = 1;
        }
    }
    return num;
}

// Calculate GCD
int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b % a, a);
}

// Calculate modulo power
int mod_pow(int base, int exp, int modulus){
    long long result = 1;
    while(exp > 0){
        if(exp % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

// Generate public and private keys
void generate_keys(int *pub_key, int *priv_key, int prime1, int prime2){
    int n, phi, e;
    // Calculate n and phi
    n = prime1 * prime2;
    phi = (prime1 - 1) * (prime2 - 1);
    // Find e, the public exponent
    for(e = 2; e < phi; e++){
        if(gcd(e, phi) == 1)
            break;
    }
    // Calculate private key
    int d = 1;
    while((e * d) % phi != 1 || d == e){
        d++;
    }
    // Set public and private keys
    pub_key[0] = e;
    pub_key[1] = n;
    priv_key[0] = d;
    priv_key[1] = n;
}

// Encrypt plaintext
int encrypt(int m, int *pub_key){
    int c = mod_pow(m, pub_key[0], pub_key[1]);
    return c;
}

// Decrypt ciphertext
int decrypt(int c, int *priv_key){
    int m = mod_pow(c, priv_key[0], priv_key[1]);
    return m;
}

int main(){
    int prime1, prime2;
    int pub_key[2], priv_key[2];
    int m, c;

    printf("Generating prime numbers...\n");
    prime1 = generate_prime_number();
    prime2 = generate_prime_number();
    printf("Prime 1: %d\nPrime 2: %d\n", prime1, prime2);

    printf("Generating public and private keys...\n");
    generate_keys(pub_key, priv_key, prime1, prime2);
    printf("Public key: {%d, %d}\nPrivate key: {%d, %d}\n", pub_key[0], pub_key[1], priv_key[0], priv_key[1]);

    printf("Enter message to encrypt (integer): ");
    scanf("%d", &m);
    c = encrypt(m, pub_key);
    printf("Ciphertext: %d\n", c);

    printf("Decrypting ciphertext...\n");
    m = decrypt(c, priv_key);
    printf("Plaintext: %d\n", m);

    return 0;
}
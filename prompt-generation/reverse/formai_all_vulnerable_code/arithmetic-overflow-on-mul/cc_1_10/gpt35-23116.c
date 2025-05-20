//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define P_SIZE 20 // size of prime numbers to generate
#define BLOCK_SIZE 5 // size of data block
#define PUBLIC_EXP 65537 // public key exponent
#define PRIVATE_EXP 129983 // private key exponent (should be large prime number)

// function to generate a prime number
int generate_prime(){
    srand(time(NULL));
    int num = rand() % 10; // starting number
    int prime_found = 0;
    while(!prime_found){
        int is_prime = 1;
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                is_prime = 0;
                break;
            }
        }
        if(is_prime){
            prime_found = 1;
            return num;
        }
        num++;
    }
    return -1;
}

// function to calculate modular exponentiation
int mod_exp(int num, int exp, int mod){
    int result = 1;
    while(exp != 0){
        if(exp % 2 == 1){
            result = (result * num) % mod;
        }
        num = (num * num) % mod;
        exp /= 2;
    }
    return result;
}

// function to generate public and private keys
void generate_keys(int *public_key, int *private_key){
    int p = generate_prime(); // generate first prime
    int q;
    while(1){
        q = generate_prime(); // generate second prime
        if(p != q){
            break;
        }
    }
    int n = p * q; // calculate modulus
    int phi_n = (p-1) * (q-1); // calculate phi(n)
    *public_key = PUBLIC_EXP; // set public exponent
    *private_key = PRIVATE_EXP; // set private exponent
    if(mod_exp(*public_key, 1, phi_n) != 1){
        printf("Invalid public key exponent\n");
        exit(1);
    }
    if(mod_exp(*private_key, 1, phi_n) != 1){
        printf("Invalid private key exponent\n");
        exit(1);
    }
    while(*public_key == *private_key || *public_key >= phi_n || *private_key >= phi_n){
        *public_key = generate_prime();
        *private_key = generate_prime();
    }
}

// function to encrypt data
void encrypt(int *data, int length, int public_key, int modulus, int *encrypted_data){
    for(int i = 0; i < length; i++){
        encrypted_data[i] = mod_exp(data[i], public_key, modulus);
    }
}

// function to decrypt data
void decrypt(int *data, int length, int private_key, int modulus, int *decrypted_data){
    for(int i = 0; i < length; i++){
        decrypted_data[i] = mod_exp(data[i], private_key, modulus);
    }
}

int main(){
    int public_key, private_key;
    generate_keys(&public_key, &private_key);
    printf("Public key: %d, Private key: %d\n", public_key, private_key);

    int data[] = {1, 2, 3, 4, 5};
    int data_length = sizeof(data) / sizeof(int);
    printf("Original data: ");
    for(int i = 0; i < data_length; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    int encrypted_data[BLOCK_SIZE];
    encrypt(data, BLOCK_SIZE, public_key, public_key * private_key, encrypted_data);
    printf("Encrypted data: ");
    for(int i = 0; i < BLOCK_SIZE; i++){
        printf("%d ", encrypted_data[i]);
    }
    printf("\n");

    int decrypted_data[BLOCK_SIZE];
    decrypt(encrypted_data, BLOCK_SIZE, private_key, public_key * private_key, decrypted_data);
    printf("Decrypted data: ");
    for(int i = 0; i < BLOCK_SIZE; i++){
        printf("%d ", decrypted_data[i]);
    }
    printf("\n");

    return 0;
}
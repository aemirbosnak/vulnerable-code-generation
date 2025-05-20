//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

// function to generate a random prime number
int generate_prime_number(){
    int num;
    bool is_prime;

    do{
        num = rand() % 100 + 2; // generate a random number between 2 and 101
        is_prime = true;
        for(int i=2; i<=sqrt(num); i++){
            if(num % i == 0){ // check if the number is not prime
                is_prime = false;
                break;
            }
        }
    }while(!is_prime); // loop until a prime number is generated

    return num;
}

// function to calculate GCD using Euclid's algorithm
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

// function to calculate modular exponentiation using repeated squaring
int modular_exponentiation(int base, int exponent, int modulus){
    int result = 1;
    while(exponent > 0){
        if(exponent % 2 == 1){
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main(){
    int p = generate_prime_number(); // generate a random prime number
    int g = rand() % (p-2) + 2; // generate a random number between 2 and p-1
    int a = rand() % (p-1) + 1; // generate a random number between 1 and p-1
    int A = modular_exponentiation(g, a, p); // calculate A = g^a mod p
    int b = rand() % (p-1) + 1; // generate another random number between 1 and p-1
    int B = modular_exponentiation(g, b, p); // calculate B = g^b mod p
    int secret_key_A = modular_exponentiation(B, a, p); // calculate the secret key of A as B^a mod p
    int secret_key_B = modular_exponentiation(A, b, p); // calculate the secret key of B as A^b mod p

    printf("p = %d\n", p);
    printf("g = %d\n", g);
    printf("a = %d\n", a);
    printf("A = %d\n", A);
    printf("b = %d\n", b);
    printf("B = %d\n", B);
    printf("Secret key of A = %d\n", secret_key_A);
    printf("Secret key of B = %d\n", secret_key_B);

    return 0;
}
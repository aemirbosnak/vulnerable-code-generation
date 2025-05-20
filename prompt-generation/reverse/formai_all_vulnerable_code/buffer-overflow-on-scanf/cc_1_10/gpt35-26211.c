//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(const int n){
    if(n <= 1)
        return false;
    for(int i=2; i*i<=n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

// Finds GCD of two numbers using Euclidean algorithm
int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Extended Euclidean algorithm to calculate the inverse of a
int extended_euclidean(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_euclidean(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to generate public and private keys
void generate_keys(int p, int q, int *e, int *d, int *n){
    *n = p * q; // Calculate n
    int phi_n = (p-1)*(q-1); // Calculate phi_n

    for(int i=2; i<phi_n; i++){
        if(gcd(i, phi_n) == 1){
            *e = i; // Calculate e
            break;
        }
    }

    int x, y;
    extended_euclidean(*e, phi_n, &x, &y);
    *d = (x % phi_n + phi_n) % phi_n; // Calculate d
}

// Function to encrypt a message
int encrypt(int msg, int e, int n){
    int c = 1;
    for(int i=0; i<e; i++){
        c = c * msg;
        c = c % n;
    }
    return c;
}

// Function to decrypt a message
int decrypt(int msg, int d, int n){
    int m = 1;
    for(int i=0; i<d; i++){
        m = m * msg;
        m = m % n;
    }
    return m;
}

int main(){
    int p, q, e, d, n, msg;
    printf("Enter two prime numbers: ");
    scanf("%d%d", &p, &q);

    while(!is_prime(p) || !is_prime(q)){
        printf("Invalid input! Enter two prime numbers: ");
        scanf("%d%d", &p, &q);
    }

    generate_keys(p, q, &e, &d, &n);

    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);

    printf("Enter a message to encrypt: ");
    scanf("%d", &msg);
    int c = encrypt(msg, e, n);
    printf("Encrypted message: %d\n", c);

    int m = decrypt(c, d, n);
    printf("Decrypted message: %d\n", m);

    return 0;
}